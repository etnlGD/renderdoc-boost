#include "WrappedD3D11Shader.h"
#include "Log.h"

namespace rdcboost
{
	WrappedD3D11VertexShader::WrappedD3D11VertexShader(
		const void* pShaderBytecode, SIZE_T BytecodeLength, 
		ID3D11VertexShader* pReal, WrappedD3D11Device* pDevice) : 
		WrappedD3D11DeviceChild(pReal, pDevice), m_BytecodeLength(BytecodeLength)
	{
		m_pShaderBytecode = new byte[BytecodeLength];
		memcpy(m_pShaderBytecode, pShaderBytecode, BytecodeLength);
	}

	WrappedD3D11VertexShader::~WrappedD3D11VertexShader()
	{
		delete[] m_pShaderBytecode;
	}

	ID3D11DeviceChild* WrappedD3D11VertexShader::CopyToDevice(ID3D11Device* pNewDevice)
	{
		ID3D11VertexShader* pNewShader = NULL;
		if (FAILED(pNewDevice->CreateVertexShader(m_pShaderBytecode, m_BytecodeLength, NULL, &pNewShader)))
		{
			LogError("CreateVertexShader failed when CopyToDevice");
		}
		return pNewShader;
	}

	WrappedD3D11HullShader::WrappedD3D11HullShader(
		const void* pShaderBytecode, SIZE_T BytecodeLength, 
		ID3D11HullShader* pReal, WrappedD3D11Device* pDevice) :
		WrappedD3D11DeviceChild(pReal, pDevice), m_BytecodeLength(BytecodeLength)
	{
		m_pShaderBytecode = new byte[BytecodeLength];
		memcpy(m_pShaderBytecode, pShaderBytecode, BytecodeLength);
	}

	WrappedD3D11HullShader::~WrappedD3D11HullShader()
	{
		delete[] m_pShaderBytecode;
	}

	ID3D11DeviceChild* WrappedD3D11HullShader::CopyToDevice(ID3D11Device* pNewDevice)
	{
		ID3D11HullShader* pNewShader = NULL;
		if (FAILED(pNewDevice->CreateHullShader(m_pShaderBytecode, m_BytecodeLength, NULL, &pNewShader)))
		{
			LogError("CreateHullShader failed when CopyToDevice");
		}
		return pNewShader;
	}

	WrappedD3D11DomainShader::WrappedD3D11DomainShader(
		const void* pShaderBytecode, SIZE_T BytecodeLength, 
		ID3D11DomainShader* pReal, WrappedD3D11Device* pDevice) : 
		WrappedD3D11DeviceChild(pReal, pDevice), m_BytecodeLength(BytecodeLength)
	{
		m_pShaderBytecode = new byte[BytecodeLength];
		memcpy(m_pShaderBytecode, pShaderBytecode, BytecodeLength);
	}

	WrappedD3D11DomainShader::~WrappedD3D11DomainShader()
	{
		delete[] m_pShaderBytecode;
	}

	ID3D11DeviceChild* WrappedD3D11DomainShader::CopyToDevice(ID3D11Device* pNewDevice)
	{
		ID3D11DomainShader* pNewShader = NULL;
		if (FAILED(pNewDevice->CreateDomainShader(m_pShaderBytecode, m_BytecodeLength, NULL, &pNewShader)))
		{
			LogError("CreateDomainShader failed when CopyToDevice");
		}
		return pNewShader;
	}

	WrappedD3D11GeometryShader::WrappedD3D11GeometryShader(
		const void* pShaderBytecode, SIZE_T BytecodeLength, 
		ID3D11GeometryShader* pReal, WrappedD3D11Device* pDevice) : 
		WrappedD3D11DeviceChild(pReal, pDevice), m_BytecodeLength(BytecodeLength)
	{
		m_pShaderBytecode = new byte[BytecodeLength];
		memcpy(m_pShaderBytecode, pShaderBytecode, BytecodeLength);
	}

	WrappedD3D11GeometryShader::~WrappedD3D11GeometryShader()
	{
		delete[] m_pShaderBytecode;
	}

	ID3D11DeviceChild* WrappedD3D11GeometryShader::CopyToDevice(ID3D11Device* pNewDevice)
	{
		ID3D11GeometryShader* pNewShader = NULL;
		if (FAILED(pNewDevice->CreateGeometryShader(m_pShaderBytecode, m_BytecodeLength, NULL, &pNewShader)))
		{
			LogError("CreateGeometryShader failed when CopyToDevice");
		}
		return pNewShader;
	}

	WrappedD3D11PixelShader::WrappedD3D11PixelShader(
		const void* pShaderBytecode, SIZE_T BytecodeLength, 
		ID3D11PixelShader* pReal, WrappedD3D11Device* pDevice) : 
		WrappedD3D11DeviceChild(pReal, pDevice), m_BytecodeLength(BytecodeLength)
	{
		m_pShaderBytecode = new byte[BytecodeLength];
		memcpy(m_pShaderBytecode, pShaderBytecode, BytecodeLength);
	}

	WrappedD3D11PixelShader::~WrappedD3D11PixelShader()
	{
		delete[] m_pShaderBytecode;
	}

	ID3D11DeviceChild* WrappedD3D11PixelShader::CopyToDevice(ID3D11Device* pNewDevice)
	{
		ID3D11PixelShader* pNewShader = NULL;
		if (FAILED(pNewDevice->CreatePixelShader(m_pShaderBytecode, m_BytecodeLength, NULL, &pNewShader)))
		{
			LogError("CreatePixelShader failed when CopyToDevice");
		}
		return pNewShader;
	}

	WrappedD3D11ComputeShader::WrappedD3D11ComputeShader(
		const void* pShaderBytecode, SIZE_T BytecodeLength, 
		ID3D11ComputeShader* pReal, WrappedD3D11Device* pDevice) : 
		WrappedD3D11DeviceChild(pReal, pDevice), m_BytecodeLength(BytecodeLength)
	{
		m_pShaderBytecode = new byte[BytecodeLength];
		memcpy(m_pShaderBytecode, pShaderBytecode, BytecodeLength);
	}

	WrappedD3D11ComputeShader::~WrappedD3D11ComputeShader()
	{
		delete[] m_pShaderBytecode;
	}

	ID3D11DeviceChild* WrappedD3D11ComputeShader::CopyToDevice(ID3D11Device* pNewDevice)
	{
		ID3D11ComputeShader* pNewShader = NULL;
		if (FAILED(pNewDevice->CreateComputeShader(m_pShaderBytecode, m_BytecodeLength, NULL, &pNewShader)))
		{
			LogError("CreateComputeShader failed when CopyToDevice");
		}
		return pNewShader;
	}
}
