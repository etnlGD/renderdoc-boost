#pragma once
#include "WrappedD3D11DeviceChild.h"

namespace rdclight
{
	class WrappedD3D11BlendState : public WrappedD3D11DeviceChild<ID3D11BlendState>
	{
	public:
		WrappedD3D11BlendState(ID3D11BlendState* pReal, WrappedD3D11Device* pDevice);
		virtual void STDMETHODCALLTYPE GetDesc(D3D11_BLEND_DESC *pDesc);
	};

	class WrappedD3D11DepthStencilState : public WrappedD3D11DeviceChild<ID3D11DepthStencilState>
	{
	public:
		WrappedD3D11DepthStencilState(ID3D11DepthStencilState* pReal, WrappedD3D11Device* pDevice);
		virtual void STDMETHODCALLTYPE GetDesc(D3D11_DEPTH_STENCIL_DESC *pDesc);
	};

	class WrappedD3D11RasterizerState : public WrappedD3D11DeviceChild<ID3D11RasterizerState>
	{
	public:
		WrappedD3D11RasterizerState(ID3D11RasterizerState* pReal, WrappedD3D11Device* pDevice);
		virtual void STDMETHODCALLTYPE GetDesc(D3D11_RASTERIZER_DESC *pDesc);
	};

	class WrappedD3D11SamplerState : public WrappedD3D11DeviceChild<ID3D11SamplerState>
	{
	public:
		WrappedD3D11SamplerState(ID3D11SamplerState* pReal, WrappedD3D11Device* pDevice);
		virtual void STDMETHODCALLTYPE GetDesc(D3D11_SAMPLER_DESC *pDesc);
	};

	typedef WrappedD3D11DeviceChild<ID3D11InputLayout> WrappedD3D11InputLayout;
}

