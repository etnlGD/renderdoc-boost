#pragma once
#include <d3d11.h>
#include "WrappedD3D11Device.h"

namespace rdclight
{
	class WrappedD3D11Device;

	class WrappedD3D11DeviceChildBase
	{
	public:
		WrappedD3D11DeviceChildBase(ID3D11DeviceChild* pReal) :
			m_pReal(pReal)
		{
			m_pReal->AddRef();
		}

		virtual ~WrappedD3D11DeviceChildBase()
		{
			m_pReal->Release();
		}

		ID3D11DeviceChild* GetRealDeviceChild() { return m_pReal; }

	protected:
		ID3D11DeviceChild* m_pReal;
	};

	template <typename NestedType>
	class WrappedD3D11DeviceChild : public NestedType, public WrappedD3D11DeviceChildBase
	{
	public:
		WrappedD3D11DeviceChild(NestedType* pReal, WrappedD3D11Device* pDevice) :
			WrappedD3D11DeviceChildBase(pReal), m_Ref(1), m_pWrappedDevice(pDevice)
		{
		}

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject)
		{
			if (riid == __uuidof(NestedType) ||
				riid == __uuidof(ID3D11DeviceChild) ||
				riid == __uuidof(IUnknown))
			{
				*ppvObject = this;
				AddRef();
				return S_OK;
			}

			*ppvObject = NULL;
			return E_POINTER;
		}

		virtual ULONG STDMETHODCALLTYPE AddRef(void)
		{
			return InterlockedIncrement(&m_Ref);
		}

		virtual ULONG STDMETHODCALLTYPE Release(void)
		{
			unsigned int ret = InterlockedDecrement(&m_Ref);
			if (ret == 0)
				delete this;
			return ret;
		}

		virtual void STDMETHODCALLTYPE GetDevice(ID3D11Device **ppDevice)
		{
			if (ppDevice)
			{
				*ppDevice = m_pWrappedDevice;
				m_pWrappedDevice->AddRef();
			}
		}

		virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID guid, UINT *pDataSize, void *pData)
		{
			return GetReal()->GetPrivateData(guid, pDataSize, pData);
		}

		virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID guid, UINT DataSize, const void *pData)
		{
			return GetReal()->SetPrivateData(guid, DataSize, pData);
		}

		virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID guid, const IUnknown *pData)
		{
			return GetReal()->SetPrivateDataInterface(guid, pData);
		}

		NestedType* GetReal() { return (NestedType*) m_pReal; }

	private:
		unsigned int m_Ref;
		WrappedD3D11Device* m_pWrappedDevice;
	};
}

