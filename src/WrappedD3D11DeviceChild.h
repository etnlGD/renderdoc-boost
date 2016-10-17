#pragma once
#include <d3d11.h>
#include "WrappedD3D11Device.h"
#include "PrivateDataMap.h"

namespace rdcboost
{
	class WrappedD3D11Device;

	class WrappedD3D11DeviceChildBase
	{
	public:
		WrappedD3D11DeviceChildBase(ID3D11DeviceChild* pReal, WrappedD3D11Device* pDevice);

		virtual ~WrappedD3D11DeviceChildBase();

		virtual void SwitchToDevice(ID3D11Device* pNewDevice) = 0;
		
		ID3D11Device* GetRealDevice() { return m_pRealDevice; }

		ID3D11DeviceChild* GetRealDeviceChild()
		{
			return m_pReal;
		}

	protected:
		WrappedD3D11Device* const m_pWrappedDevice;
		ID3D11DeviceChild* m_pReal;

	private:
		template <typename T>
		friend class WrappedD3D11DeviceChild;

		ID3D11Device* m_pRealDevice;
	};

	template <typename NestedType>
	class WrappedD3D11DeviceChild : public WrappedD3D11DeviceChildBase, public NestedType
	{
	public:
		WrappedD3D11DeviceChild(NestedType* pReal, WrappedD3D11Device* pDevice) :
			WrappedD3D11DeviceChildBase(pReal, pDevice), m_Ref(1)
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
			m_PrivateData.SetPrivateData(guid, DataSize, pData);
			return GetReal()->SetPrivateData(guid, DataSize, pData);
		}

		virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID guid, const IUnknown *pData)
		{
			LogWarn("SetPrivateDataInterface may be risky");
			m_PrivateData.SetPrivateDataInterface(guid, pData);
			return GetReal()->SetPrivateDataInterface(guid, pData);
		}

		NestedType* GetReal() { return static_cast<NestedType*>(m_pReal); }

		NestedType* GetRealOrRDCWrapped(bool rdcWrapped);

		void SwitchToDeviceForSwapChainBuffer(ID3D11Device* pNewDevice, NestedType* pNewBuffer)
		{
			if (m_pRealDevice == pNewDevice)
				return;

			CopyToDeviceForSwapChainBuffer(pNewDevice, pNewBuffer);
			m_PrivateData.CopyPrivateData(pNewBuffer);
			m_pReal->Release();
			m_pReal = pNewBuffer;
			m_pRealDevice = pNewDevice;
		}

		virtual void SwitchToDevice(ID3D11Device* pNewDevice)
		{
			if (m_pRealDevice == pNewDevice)
				return;

			ID3D11DeviceChild* pCopied = CopyToDevice(pNewDevice);
			Assert(pCopied != NULL);
			m_PrivateData.CopyPrivateData(pCopied);
			m_pReal->Release();
			m_pReal = pCopied;
			m_pRealDevice = pNewDevice;
		}

	protected:
		virtual ID3D11DeviceChild* CopyToDevice(ID3D11Device* pNewDevice) = 0;
		virtual void CopyToDeviceForSwapChainBuffer(ID3D11Device* pNewDevice, NestedType* pNewBuffer) {}

	protected:
		unsigned int m_Ref;

	private:
		PrivateDataMap m_PrivateData;
	};

	inline WrappedD3D11DeviceChildBase* ConvertToWrappedBase(ID3D11DeviceChild* pWrapped)
	{
		return static_cast<WrappedD3D11DeviceChild<ID3D11DeviceChild>*>(pWrapped);
	}

	template <typename UnwrapType>
	UnwrapType* UnwrapDeviceChild(ID3D11DeviceChild* pWrapped)
	{
		if (pWrapped == NULL)
			return NULL;

		WrappedD3D11DeviceChildBase* base = ConvertToWrappedBase(pWrapped);
		return static_cast<UnwrapType*>(base->GetRealDeviceChild());
	}

	template <typename UnwrapType>
	UnwrapType* UnwrapSelf(UnwrapType* pWrapped)
	{
		return UnwrapDeviceChild<UnwrapType>(pWrapped);
	}
}

