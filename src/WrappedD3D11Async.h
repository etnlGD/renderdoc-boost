#pragma once
#include "WrappedD3D11DeviceChild.h"

namespace rdclight
{
	template <typename NestedType>
	class WrappedD3D11Async : public WrappedD3D11DeviceChild<NestedType>
	{
	public:
		WrappedD3D11Async(NestedType* pReal, WrappedD3D11Device* pDevice) : 
			WrappedD3D11DeviceChild(pReal, pDevice)
		{
		}

		virtual UINT STDMETHODCALLTYPE GetDataSize(void)
		{
			return GetReal()->GetDataSize();
		}

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject)
		{
			if (riid == __uuidof(ID3D11Asynchronous))
			{
				*ppvObject = this;
				AddRef();
				return S_OK;
			}

			return WrappedD3D11DeviceChild::QueryInterface(riid, ppvObject);
		}
	};

	template <typename NestedType>
	class WrappedD3D11QueryBase : public WrappedD3D11Async<NestedType>
	{
	public:
		WrappedD3D11QueryBase(NestedType* pReal, WrappedD3D11Device* pDevice) :
			WrappedD3D11Async(pReal, pDevice)
		{
		}

		virtual void STDMETHODCALLTYPE GetDesc(D3D11_QUERY_DESC *pDesc)
		{
			GetReal()->GetDesc(pDesc);
		}

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject)
		{
			if (riid == __uuidof(ID3D11Query))
			{
				*ppvObject = this;
				AddRef();
				return S_OK;
			}

			return WrappedD3D11DeviceChild::QueryInterface(riid, ppvObject);
		}
	};

	class WrappedD3D11Counter : public WrappedD3D11Async<ID3D11Counter>
	{
	public:
		WrappedD3D11Counter(ID3D11Counter* pReal, WrappedD3D11Device* pDevice);
		virtual void STDMETHODCALLTYPE GetDesc(D3D11_COUNTER_DESC *pDesc);
	};

	typedef WrappedD3D11QueryBase<ID3D11Query> WrappedD3D11Query;
	typedef WrappedD3D11QueryBase<ID3D11Predicate> WrappedD3D11Predicate;
}

