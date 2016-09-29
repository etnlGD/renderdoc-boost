#pragma once
#include "WrappedD3D11DeviceChild.h"

namespace rdclight
{
	typedef WrappedD3D11DeviceChild<ID3D11ComputeShader> WrappedD3D11ComputeShader;
	typedef WrappedD3D11DeviceChild<ID3D11DomainShader> WrappedD3D11DomainShader;
	typedef WrappedD3D11DeviceChild<ID3D11GeometryShader> WrappedD3D11GeometryShader;
	typedef WrappedD3D11DeviceChild<ID3D11HullShader> WrappedD3D11HullShader;
	typedef WrappedD3D11DeviceChild<ID3D11PixelShader> WrappedD3D11PixelShader;
	typedef WrappedD3D11DeviceChild<ID3D11VertexShader> WrappedD3D11VertexShader;
}

