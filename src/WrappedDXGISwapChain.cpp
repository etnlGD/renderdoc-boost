#include "WrappedDXGISwapChain.h"
#include "Log.h"
#include <d3d11.h>
#include "WrappedD3D11Device.h"
#include "WrappedD3D11Resource.h"

namespace rdcboost
{
	WrappedDXGISwapChain::WrappedDXGISwapChain(
		IDXGISwapChain* pReal, WrappedD3D11Device* pWrappedDevice) :
		m_pWrappedDevice(pWrappedDevice), m_pReal(pReal), m_Ref(1)
	{
		m_pReal->AddRef();
	}

	WrappedDXGISwapChain::~WrappedDXGISwapChain()
	{
		m_pReal->Release();
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::GetBuffer(UINT Buffer, REFIID riid, 
															  void **ppSurface)
	{
		if (ppSurface == NULL) return E_INVALIDARG;

		// ID3D10Texture2D UUID {9B7E4C04-342C-4106-A19F-4F2704F689F0}
		static const GUID ID3D10Texture2D_uuid = { 0x9b7e4c04, 0x342c, 0x4106, { 0xa1, 0x9f, 0x4f, 0x27, 0x04, 0xf6, 0x89, 0xf0 } };

		// ID3D10Resource  UUID {9B7E4C01-342C-4106-A19F-4F2704F689F0}
		static const GUID ID3D10Resource_uuid = { 0x9b7e4c01, 0x342c, 0x4106, { 0xa1, 0x9f, 0x4f, 0x27, 0x04, 0xf6, 0x89, 0xf0 } };

		if (riid == ID3D10Texture2D_uuid || riid == ID3D10Resource_uuid)
		{
			LogError("Querying swapchain buffers via D3D10 interface UUIDs is not supported");
			return E_NOINTERFACE;
		}
		else if (riid != __uuidof(ID3D11Texture2D) && riid != __uuidof(ID3D11Resource))
		{
			LogError("Unsupported or unrecognised UUID passed to IDXGISwapChain::GetBuffer");
			return E_NOINTERFACE;
		}

		Assert(riid == __uuidof(ID3D11Texture2D) || riid == __uuidof(ID3D11Resource));

		HRESULT ret = m_pReal->GetBuffer(Buffer, riid, ppSurface);

		ID3D11Texture2D *realSurface = (ID3D11Texture2D *)*ppSurface;
		ID3D11Texture2D *tex = realSurface;
		if (FAILED(ret))
		{
			LogError("Failed to get swapchain backbuffer %d: %08x", Buffer, ret);
			if (realSurface)
			{
				realSurface->Release();
				realSurface = NULL;
			}
			tex = NULL;
		}
		else 
		{
			tex = m_pWrappedDevice->GetWrappedSwapChainBuffer(realSurface);
			realSurface->Release();
		}

		*ppSurface = tex;

		return ret;
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::SetFullscreenState(BOOL Fullscreen,
																	   IDXGIOutput *pTarget)
	{
		return m_pReal->SetFullscreenState(Fullscreen, pTarget);
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::GetFullscreenState(BOOL *pFullscreen, 
																	   IDXGIOutput **ppTarget)
	{
		return m_pReal->GetFullscreenState(pFullscreen, ppTarget);
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::GetContainingOutput(IDXGIOutput **ppOutput)
	{
		return m_pReal->GetContainingOutput(ppOutput);
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::SetPrivateData(
		REFGUID Name, UINT DataSize, const void *pData)
	{
		LogError("This method is not supported by now.");
		return E_FAIL;
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::SetPrivateDataInterface(
		REFGUID Name, const IUnknown *pUnknown)
	{
		LogError("This method is not supported by now.");
		return E_FAIL;
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::GetPrivateData(
		REFGUID Name, UINT *pDataSize, void *pData)
	{
		LogError("This method is not supported by now.");
		return E_FAIL;
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::GetDevice(REFIID riid, void **ppDevice)
	{
		*ppDevice = NULL;
		LogError("This method is not supported by now.");
		return E_FAIL;
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::GetParent(REFIID riid, void **ppParent)
	{
		*ppParent = NULL;
		LogError("This method is not supported by now.");
		return E_FAIL;
	}

	HRESULT STDMETHODCALLTYPE WrappedDXGISwapChain::QueryInterface(
		REFIID riid, _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject)
	{
		*ppvObject = NULL;
		LogError("This method is not supported by now.");
		return E_FAIL;
	}

	ULONG STDMETHODCALLTYPE WrappedDXGISwapChain::AddRef(void)
	{
		return InterlockedIncrement(&m_Ref);
	}

	ULONG STDMETHODCALLTYPE WrappedDXGISwapChain::Release(void)
	{
		unsigned int ret = InterlockedDecrement(&m_Ref);
		if (ret == 0)
			delete this;
		return ret;
	}

}

