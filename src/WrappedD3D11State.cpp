#include "WrappedD3D11State.h"

namespace rdclight
{

	WrappedD3D11BlendState::WrappedD3D11BlendState(ID3D11BlendState* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11DeviceChild(pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11BlendState::GetDesc(D3D11_BLEND_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11DepthStencilState::WrappedD3D11DepthStencilState(ID3D11DepthStencilState* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11DeviceChild(pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11DepthStencilState::GetDesc(D3D11_DEPTH_STENCIL_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11RasterizerState::WrappedD3D11RasterizerState(ID3D11RasterizerState* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11DeviceChild(pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11RasterizerState::GetDesc(D3D11_RASTERIZER_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11SamplerState::WrappedD3D11SamplerState(ID3D11SamplerState* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11DeviceChild(pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11SamplerState::GetDesc(D3D11_SAMPLER_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

}

