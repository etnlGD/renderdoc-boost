#include "WrappedD3D11Resource.h"

namespace rdclight
{

	WrappedD3D11Buffer::WrappedD3D11Buffer(ID3D11Buffer* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11Resource(pReal, pDevice)
	{

	}

	void STDMETHODCALLTYPE WrappedD3D11Buffer::GetDesc(D3D11_BUFFER_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11Texture1D::WrappedD3D11Texture1D(ID3D11Texture1D* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11Resource(pReal, pDevice)
	{
	}

	void STDMETHODCALLTYPE WrappedD3D11Texture1D::GetDesc(D3D11_TEXTURE1D_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11Texture2D::WrappedD3D11Texture2D(ID3D11Texture2D* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11Resource(pReal, pDevice)
	{

	}

	void STDMETHODCALLTYPE WrappedD3D11Texture2D::GetDesc(D3D11_TEXTURE2D_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

	WrappedD3D11Texture3D::WrappedD3D11Texture3D(ID3D11Texture3D* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11Resource(pReal, pDevice)
	{

	}

	void STDMETHODCALLTYPE WrappedD3D11Texture3D::GetDesc(D3D11_TEXTURE3D_DESC *pDesc)
	{
		GetReal()->GetDesc(pDesc);
	}

}

