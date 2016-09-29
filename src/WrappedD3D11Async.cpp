#include "WrappedD3D11Async.h"

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

}

