#include "WrappedD3D11Async.h"
#include "Log.h"

namespace rdclight
{

	WrappedD3D11Counter::WrappedD3D11Counter(ID3D11Counter* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11Async(pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11Counter::GetDesc(D3D11_COUNTER_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	ID3D11DeviceChild* WrappedD3D11Counter::CopyToDevice(ID3D11Device* pNewDevice)
	{
		D3D11_COUNTER_DESC desc;
		GetReal()->GetDesc(&desc);

		ID3D11Counter* pNewCounter = NULL;
		if (FAILED(pNewDevice->CreateCounter(&desc, &pNewCounter)))
			LogError("CreateCounter failed when CopyToDevice");

		return pNewCounter;
	}

}

