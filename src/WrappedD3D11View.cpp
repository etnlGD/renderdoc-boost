#include "WrappedD3D11View.h"

namespace rdclight
{

	WrappedD3D11DepthStencilView::WrappedD3D11DepthStencilView(
		ID3D11Resource* pWrappedResource, ID3D11DepthStencilView* pReal, 
		WrappedD3D11Device* pDevice) :
		WrappedD3D11View(pWrappedResource, pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11DepthStencilView::GetDesc(D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11RenderTargetView::WrappedD3D11RenderTargetView(
		ID3D11Resource* pWrappedResource, ID3D11RenderTargetView* pReal, 
		WrappedD3D11Device* pDevice) : 
		WrappedD3D11View(pWrappedResource, pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11RenderTargetView::GetDesc(D3D11_RENDER_TARGET_VIEW_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11ShaderResourceView::WrappedD3D11ShaderResourceView(
		ID3D11Resource* pWrappedResource, ID3D11ShaderResourceView* pReal, 
		WrappedD3D11Device* pDevice) : 
		WrappedD3D11View(pWrappedResource, pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11ShaderResourceView::GetDesc(D3D11_SHADER_RESOURCE_VIEW_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11UnorderedAccessView::WrappedD3D11UnorderedAccessView(
		ID3D11Resource* pWrappedResource, ID3D11UnorderedAccessView* pReal, 
		WrappedD3D11Device* pDevice) : 
		WrappedD3D11View(pWrappedResource, pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11UnorderedAccessView::GetDesc(D3D11_UNORDERED_ACCESS_VIEW_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

}

