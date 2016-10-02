#pragma once
#include "WrappedD3D11DeviceChild.h"

namespace rdcboost
{
	class WrappedD3D11VertexShader : public WrappedD3D11DeviceChild<ID3D11VertexShader>
	{
	public:
		WrappedD3D11VertexShader(const void* pShaderBytecode, SIZE_T BytecodeLength,
								 ID3D11VertexShader* pReal, WrappedD3D11Device* pDevice);

		virtual ~WrappedD3D11VertexShader();

	protected:
		virtual ID3D11DeviceChild* CopyToDevice(ID3D11Device* pNewDevice);

	private:
		byte* m_pShaderBytecode;
		SIZE_T m_BytecodeLength;
	};

	class WrappedD3D11HullShader : public WrappedD3D11DeviceChild<ID3D11HullShader>
	{
	public:
		WrappedD3D11HullShader(const void* pShaderBytecode, SIZE_T BytecodeLength,
							   ID3D11HullShader* pReal, WrappedD3D11Device* pDevice);

		virtual ~WrappedD3D11HullShader();

	protected:
		virtual ID3D11DeviceChild* CopyToDevice(ID3D11Device* pNewDevice);

	private:
		byte* m_pShaderBytecode;
		SIZE_T m_BytecodeLength;
	};

	class WrappedD3D11DomainShader : public WrappedD3D11DeviceChild<ID3D11DomainShader>
	{
	public:
		WrappedD3D11DomainShader(const void* pShaderBytecode, SIZE_T BytecodeLength,
								 ID3D11DomainShader* pReal, WrappedD3D11Device* pDevice);

		virtual ~WrappedD3D11DomainShader();

	protected:
		virtual ID3D11DeviceChild* CopyToDevice(ID3D11Device* pNewDevice);

	private:
		byte* m_pShaderBytecode;
		SIZE_T m_BytecodeLength;
	};

	class WrappedD3D11GeometryShader : public WrappedD3D11DeviceChild<ID3D11GeometryShader>
	{
	public:
		WrappedD3D11GeometryShader(const void* pShaderBytecode, SIZE_T BytecodeLength,
								   ID3D11GeometryShader* pReal, WrappedD3D11Device* pDevice);

		virtual ~WrappedD3D11GeometryShader();

	protected:
		virtual ID3D11DeviceChild* CopyToDevice(ID3D11Device* pNewDevice);

	private:
		byte* m_pShaderBytecode;
		SIZE_T m_BytecodeLength;
	};

	class WrappedD3D11PixelShader : public WrappedD3D11DeviceChild<ID3D11PixelShader>
	{
	public:
		WrappedD3D11PixelShader(const void* pShaderBytecode, SIZE_T BytecodeLength,
								ID3D11PixelShader* pReal, WrappedD3D11Device* pDevice);

		virtual ~WrappedD3D11PixelShader();

	protected:
		virtual ID3D11DeviceChild* CopyToDevice(ID3D11Device* pNewDevice);

	private:
		byte* m_pShaderBytecode;
		SIZE_T m_BytecodeLength;
	};

	class WrappedD3D11ComputeShader : public WrappedD3D11DeviceChild<ID3D11ComputeShader>
	{
	public:
		WrappedD3D11ComputeShader(const void* pShaderBytecode, SIZE_T BytecodeLength,
								  ID3D11ComputeShader* pReal, WrappedD3D11Device* pDevice);

		virtual ~WrappedD3D11ComputeShader();

	protected:
		virtual ID3D11DeviceChild* CopyToDevice(ID3D11Device* pNewDevice);

	private:
		byte* m_pShaderBytecode;
		SIZE_T m_BytecodeLength;
	};
}

