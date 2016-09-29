#include "D3D11ContextRecorder.h"

namespace rdclight
{
	static uint64_t GetIDForResource(void*)
	{
		return 0;
	}

#pragma region Input Assembly
	void D3D11ContextRecorder::IASetInputLayout(ID3D11InputLayout *pInputLayout)
	{
		D3D11ContextDelegate::IASetInputLayout(pInputLayout);
	}

	void D3D11ContextRecorder::IASetVertexBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppVertexBuffers, const UINT *pStrides, const UINT *pOffsets)
	{
		D3D11ContextDelegate::IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
	}

	void D3D11ContextRecorder::IASetIndexBuffer(ID3D11Buffer *pIndexBuffer, DXGI_FORMAT Format, UINT Offset)
	{
		D3D11ContextDelegate::IASetIndexBuffer(pIndexBuffer, Format, Offset);
	}

	void D3D11ContextRecorder::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
	{
		D3D11ContextDelegate::IASetPrimitiveTopology(Topology);
	}
#pragma endregion Input Assembly


#pragma region Rasterizer
	void D3D11ContextRecorder::RSSetState(ID3D11RasterizerState *pRasterizerState)
	{
		D3D11ContextDelegate::RSSetState(pRasterizerState);
	}

	void D3D11ContextRecorder::RSSetViewports(UINT NumViewports, const D3D11_VIEWPORT *pViewports)
	{
		D3D11ContextDelegate::RSSetViewports(NumViewports, pViewports);
	}

	void D3D11ContextRecorder::RSSetScissorRects(UINT NumRects, const D3D11_RECT *pRects)
	{
		D3D11ContextDelegate::RSSetScissorRects(NumRects, pRects);
	}
#pragma endregion Rasterizer


#pragma region SetConstantBuffers
	void D3D11ContextRecorder::Serialise_SetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{

	}

	void D3D11ContextRecorder::VSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		Serialise_SetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		D3D11ContextDelegate::VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextRecorder::HSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		Serialise_SetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		D3D11ContextDelegate::HSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextRecorder::DSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		Serialise_SetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		D3D11ContextDelegate::DSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextRecorder::GSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		Serialise_SetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		D3D11ContextDelegate::GSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextRecorder::PSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		Serialise_SetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		D3D11ContextDelegate::PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextRecorder::CSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		Serialise_SetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		D3D11ContextDelegate::CSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}
#pragma endregion SetConstantBuffers


#pragma region SetShaderResources
	void D3D11ContextRecorder::VSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		D3D11ContextDelegate::VSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextRecorder::HSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		D3D11ContextDelegate::HSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextRecorder::DSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		D3D11ContextDelegate::DSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextRecorder::GSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		D3D11ContextDelegate::GSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextRecorder::PSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		D3D11ContextDelegate::PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextRecorder::CSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		D3D11ContextDelegate::CSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}
#pragma endregion SetShaderResources


#pragma region SetShader
	void D3D11ContextRecorder::VSSetShader(ID3D11VertexShader *pVertexShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		D3D11ContextDelegate::VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextRecorder::HSSetShader(ID3D11HullShader *pHullShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		D3D11ContextDelegate::HSSetShader(pHullShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextRecorder::DSSetShader(ID3D11DomainShader *pDomainShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		D3D11ContextDelegate::DSSetShader(pDomainShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextRecorder::GSSetShader(ID3D11GeometryShader *pShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		D3D11ContextDelegate::GSSetShader(pShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextRecorder::PSSetShader(ID3D11PixelShader *pPixelShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		D3D11ContextDelegate::PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextRecorder::CSSetShader(ID3D11ComputeShader *pComputeShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		D3D11ContextDelegate::CSSetShader(pComputeShader, ppClassInstances, NumClassInstances);
	}
#pragma endregion SetShader


#pragma region SetSamplers
	void D3D11ContextRecorder::VSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		D3D11ContextDelegate::VSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextRecorder::HSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		D3D11ContextDelegate::HSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextRecorder::DSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		D3D11ContextDelegate::DSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextRecorder::GSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		D3D11ContextDelegate::GSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextRecorder::PSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)

	{
		D3D11ContextDelegate::PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextRecorder::CSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		D3D11ContextDelegate::CSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}
#pragma endregion SetSamplers


	void D3D11ContextRecorder::CSSetUnorderedAccessViews(UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, const UINT *pUAVInitialCounts)
	{
		D3D11ContextDelegate::CSSetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
	}


#pragma region Output Merger
	void D3D11ContextRecorder::OMSetRenderTargets(UINT NumViews, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView)
	{
		D3D11ContextDelegate::OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
	}

	void D3D11ContextRecorder::OMSetRenderTargetsAndUnorderedAccessViews(UINT NumRTVs, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, const UINT *pUAVInitialCounts)
	{
		D3D11ContextDelegate::OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, pDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
	}

	void D3D11ContextRecorder::OMSetBlendState(ID3D11BlendState *pBlendState, const FLOAT BlendFactor[4], UINT SampleMask)
	{
		D3D11ContextDelegate::OMSetBlendState(pBlendState, BlendFactor, SampleMask);
	}

	void D3D11ContextRecorder::OMSetDepthStencilState(ID3D11DepthStencilState *pDepthStencilState, UINT StencilRef)
	{
		D3D11ContextDelegate::OMSetDepthStencilState(pDepthStencilState, StencilRef);
	}
#pragma endregion Output Merger


	void D3D11ContextRecorder::DrawIndexed(UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation)
	{
		D3D11ContextDelegate::DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
	}

	void D3D11ContextRecorder::Draw(UINT VertexCount, UINT StartVertexLocation)
	{
		D3D11ContextDelegate::Draw(VertexCount, StartVertexLocation);
	}

	void D3D11ContextRecorder::DrawIndexedInstanced(UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation)
	{
		D3D11ContextDelegate::DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
	}

	void D3D11ContextRecorder::DrawInstanced(UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation)
	{
		D3D11ContextDelegate::DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
	}

	void D3D11ContextRecorder::DrawAuto()
	{
		D3D11ContextDelegate::DrawAuto();
	}

	void D3D11ContextRecorder::DrawIndexedInstancedIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		D3D11ContextDelegate::DrawIndexedInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
	}

	void D3D11ContextRecorder::DrawInstancedIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		D3D11ContextDelegate::DrawInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
	}

	void D3D11ContextRecorder::Dispatch(UINT ThreadGroupCountX, UINT ThreadGroupCountY, UINT ThreadGroupCountZ)
	{
		D3D11ContextDelegate::Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
	}

	void D3D11ContextRecorder::DispatchIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		D3D11ContextDelegate::DispatchIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
	}

	void D3D11ContextRecorder::Begin(ID3D11Asynchronous *pAsync)
	{
		D3D11ContextDelegate::Begin(pAsync);
	}

	void D3D11ContextRecorder::End(ID3D11Asynchronous *pAsync)
	{
		D3D11ContextDelegate::End(pAsync);
	}

	void D3D11ContextRecorder::SetPredication(ID3D11Predicate *pPredicate, BOOL PredicateValue)
	{
		D3D11ContextDelegate::SetPredication(pPredicate, PredicateValue);
	}

	void D3D11ContextRecorder::SOSetTargets(UINT NumBuffers, ID3D11Buffer *const *ppSOTargets, const UINT *pOffsets)
	{
		D3D11ContextDelegate::SOSetTargets(NumBuffers, ppSOTargets, pOffsets);
	}

	HRESULT D3D11ContextRecorder::Map(ID3D11Resource *pResource, UINT Subresource, D3D11_MAP MapType, UINT MapFlags, D3D11_MAPPED_SUBRESOURCE *pMappedResource)
	{
		return D3D11ContextDelegate::Map(pResource, Subresource, MapType, MapFlags, pMappedResource);
	}

	void D3D11ContextRecorder::Unmap(ID3D11Resource *pResource, UINT Subresource)
	{
		D3D11ContextDelegate::Unmap(pResource, Subresource);
	}
	
	void D3D11ContextRecorder::UpdateSubresource(ID3D11Resource *pDstResource, UINT DstSubresource, const D3D11_BOX *pDstBox, const void *pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
	{
		D3D11ContextDelegate::UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
	}

	void D3D11ContextRecorder::CopySubresourceRegion(ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox)
	{
		D3D11ContextDelegate::CopySubresourceRegion(pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
	}

	void D3D11ContextRecorder::CopyResource(ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource)
	{
		D3D11ContextDelegate::CopyResource(pDstResource, pSrcResource);
	}

	void D3D11ContextRecorder::CopyStructureCount(ID3D11Buffer *pDstBuffer, UINT DstAlignedByteOffset, ID3D11UnorderedAccessView *pSrcView)
	{
		D3D11ContextDelegate::CopyStructureCount(pDstBuffer, DstAlignedByteOffset, pSrcView);
	}

	void D3D11ContextRecorder::ClearRenderTargetView(ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4])
	{
		D3D11ContextDelegate::ClearRenderTargetView(pRenderTargetView, ColorRGBA);
	}

	void D3D11ContextRecorder::ClearUnorderedAccessViewUint(ID3D11UnorderedAccessView *pUnorderedAccessView, const UINT Values[4])
	{
		D3D11ContextDelegate::ClearUnorderedAccessViewUint(pUnorderedAccessView, Values);
	}

	void D3D11ContextRecorder::ClearUnorderedAccessViewFloat(ID3D11UnorderedAccessView *pUnorderedAccessView, const FLOAT Values[4])
	{
		D3D11ContextDelegate::ClearUnorderedAccessViewFloat(pUnorderedAccessView, Values);
	}

	void D3D11ContextRecorder::ClearDepthStencilView(ID3D11DepthStencilView *pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil)
	{
		D3D11ContextDelegate::ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
	}

	void D3D11ContextRecorder::GenerateMips(ID3D11ShaderResourceView *pShaderResourceView)
	{
		D3D11ContextDelegate::GenerateMips(pShaderResourceView);
	}

	void D3D11ContextRecorder::SetResourceMinLOD(ID3D11Resource *pResource, FLOAT MinLOD)
	{
		D3D11ContextDelegate::SetResourceMinLOD(pResource, MinLOD);
	}

	void D3D11ContextRecorder::ResolveSubresource(ID3D11Resource *pDstResource, UINT DstSubresource, ID3D11Resource *pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format)
	{
		D3D11ContextDelegate::ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
	}

	void D3D11ContextRecorder::ExecuteCommandList(ID3D11CommandList *pCommandList, BOOL RestoreContextState)
	{
		D3D11ContextDelegate::ExecuteCommandList(pCommandList, RestoreContextState);
	}

	void D3D11ContextRecorder::ClearState()
	{
		D3D11ContextDelegate::ClearState();
	}

	HRESULT D3D11ContextRecorder::FinishCommandList(BOOL RestoreDeferredContextState, ID3D11CommandList **ppCommandList)
	{
		return D3D11ContextDelegate::FinishCommandList(RestoreDeferredContextState, ppCommandList);
	}
}
