#include "D3D11ContextDelegate.h"

namespace rdclight
{
	void D3D11ContextDelegate::VSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		m_pReal->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::PSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		m_pReal->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::PSSetShader(ID3D11PixelShader *pPixelShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		m_pReal->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextDelegate::PSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		m_pReal->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::VSSetShader(ID3D11VertexShader *pVertexShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		m_pReal->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextDelegate::DrawIndexed(UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation)
	{
		m_pReal->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
	}

	void D3D11ContextDelegate::Draw(UINT VertexCount, UINT StartVertexLocation)
	{
		m_pReal->Draw(VertexCount, StartVertexLocation);
	}

	HRESULT D3D11ContextDelegate::Map(ID3D11Resource *pResource, UINT Subresource, D3D11_MAP MapType, UINT MapFlags, D3D11_MAPPED_SUBRESOURCE *pMappedResource)
	{
		return m_pReal->Map(pResource, Subresource, MapType, MapFlags, pMappedResource);
	}

	void D3D11ContextDelegate::Unmap(ID3D11Resource *pResource, UINT Subresource)
	{
		m_pReal->Unmap(pResource, Subresource);
	}

	void D3D11ContextDelegate::PSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		m_pReal->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::IASetInputLayout(ID3D11InputLayout *pInputLayout)
	{
		m_pReal->IASetInputLayout(pInputLayout);
	}

	void D3D11ContextDelegate::IASetVertexBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppVertexBuffers, const UINT *pStrides, const UINT *pOffsets)
	{
		m_pReal->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
	}

	void D3D11ContextDelegate::IASetIndexBuffer(ID3D11Buffer *pIndexBuffer, DXGI_FORMAT Format, UINT Offset)
	{
		m_pReal->IASetIndexBuffer(pIndexBuffer, Format, Offset);
	}

	void D3D11ContextDelegate::DrawIndexedInstanced(UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation)
	{
		m_pReal->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
	}

	void D3D11ContextDelegate::DrawInstanced(UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation)
	{
		m_pReal->DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
	}

	void D3D11ContextDelegate::GSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		m_pReal->GSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::GSSetShader(ID3D11GeometryShader *pShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		m_pReal->GSSetShader(pShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextDelegate::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
	{
		m_pReal->IASetPrimitiveTopology(Topology);
	}

	void D3D11ContextDelegate::VSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		m_pReal->VSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::VSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		m_pReal->VSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::Begin(ID3D11Asynchronous *pAsync)
	{
		m_pReal->Begin(pAsync);
	}

	void D3D11ContextDelegate::End(ID3D11Asynchronous *pAsync)
	{
		m_pReal->End(pAsync);
	}

	HRESULT D3D11ContextDelegate::GetData(ID3D11Asynchronous *pAsync, void *pData, UINT DataSize, UINT GetDataFlags)
	{
		return m_pReal->GetData(pAsync, pData, DataSize, GetDataFlags);
	}

	void D3D11ContextDelegate::SetPredication(ID3D11Predicate *pPredicate, BOOL PredicateValue)
	{
		m_pReal->SetPredication(pPredicate, PredicateValue);
	}

	void D3D11ContextDelegate::GSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		m_pReal->GSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::GSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		m_pReal->GSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::OMSetRenderTargets(UINT NumViews, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView)
	{
		m_pReal->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
	}

	void D3D11ContextDelegate::OMSetRenderTargetsAndUnorderedAccessViews(UINT NumRTVs, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, const UINT *pUAVInitialCounts)
	{
		m_pReal->OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, pDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
	}

	void D3D11ContextDelegate::OMSetBlendState(ID3D11BlendState *pBlendState, const FLOAT BlendFactor[4], UINT SampleMask)
	{
		m_pReal->OMSetBlendState(pBlendState, BlendFactor, SampleMask);
	}

	void D3D11ContextDelegate::OMSetDepthStencilState(ID3D11DepthStencilState *pDepthStencilState, UINT StencilRef)
	{
		m_pReal->OMSetDepthStencilState(pDepthStencilState, StencilRef);
	}

	void D3D11ContextDelegate::SOSetTargets(UINT NumBuffers, ID3D11Buffer *const *ppSOTargets, const UINT *pOffsets)
	{
		m_pReal->SOSetTargets(NumBuffers, ppSOTargets, pOffsets);
	}

	void D3D11ContextDelegate::DrawAuto()
	{
		m_pReal->DrawAuto();
	}

	void D3D11ContextDelegate::DrawIndexedInstancedIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		m_pReal->DrawIndexedInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
	}

	void D3D11ContextDelegate::DrawInstancedIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		m_pReal->DrawInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
	}

	void D3D11ContextDelegate::Dispatch(UINT ThreadGroupCountX, UINT ThreadGroupCountY, UINT ThreadGroupCountZ)
	{
		m_pReal->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
	}

	void D3D11ContextDelegate::DispatchIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		m_pReal->DispatchIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
	}

	void D3D11ContextDelegate::RSSetState(ID3D11RasterizerState *pRasterizerState)
	{
		m_pReal->RSSetState(pRasterizerState);
	}

	void D3D11ContextDelegate::RSSetViewports(UINT NumViewports, const D3D11_VIEWPORT *pViewports)
	{
		m_pReal->RSSetViewports(NumViewports, pViewports);
	}

	void D3D11ContextDelegate::RSSetScissorRects(UINT NumRects, const D3D11_RECT *pRects)
	{
		m_pReal->RSSetScissorRects(NumRects, pRects);
	}

	void D3D11ContextDelegate::CopySubresourceRegion(ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox)
	{
		m_pReal->CopySubresourceRegion(pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
	}

	void D3D11ContextDelegate::CopyResource(ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource)
	{
		m_pReal->CopyResource(pDstResource, pSrcResource);
	}

	void D3D11ContextDelegate::UpdateSubresource(ID3D11Resource *pDstResource, UINT DstSubresource, const D3D11_BOX *pDstBox, const void *pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
	{
		m_pReal->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
	}

	void D3D11ContextDelegate::CopyStructureCount(ID3D11Buffer *pDstBuffer, UINT DstAlignedByteOffset, ID3D11UnorderedAccessView *pSrcView)
	{
		m_pReal->CopyStructureCount(pDstBuffer, DstAlignedByteOffset, pSrcView);
	}

	void D3D11ContextDelegate::ClearRenderTargetView(ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4])
	{
		m_pReal->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
	}

	void D3D11ContextDelegate::ClearUnorderedAccessViewUint(ID3D11UnorderedAccessView *pUnorderedAccessView, const UINT Values[4])
	{
		m_pReal->ClearUnorderedAccessViewUint(pUnorderedAccessView, Values);
	}

	void D3D11ContextDelegate::ClearUnorderedAccessViewFloat(ID3D11UnorderedAccessView *pUnorderedAccessView, const FLOAT Values[4])
	{
		m_pReal->ClearUnorderedAccessViewFloat(pUnorderedAccessView, Values);
	}

	void D3D11ContextDelegate::ClearDepthStencilView(ID3D11DepthStencilView *pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil)
	{
		m_pReal->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
	}

	void D3D11ContextDelegate::GenerateMips(ID3D11ShaderResourceView *pShaderResourceView)
	{
		m_pReal->GenerateMips(pShaderResourceView);
	}

	void D3D11ContextDelegate::SetResourceMinLOD(ID3D11Resource *pResource, FLOAT MinLOD)
	{
		m_pReal->SetResourceMinLOD(pResource, MinLOD);
	}

	FLOAT D3D11ContextDelegate::GetResourceMinLOD(ID3D11Resource *pResource)
	{
		return m_pReal->GetResourceMinLOD(pResource);
	}

	void D3D11ContextDelegate::ResolveSubresource(ID3D11Resource *pDstResource, UINT DstSubresource, ID3D11Resource *pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format)
	{
		m_pReal->ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
	}

	void D3D11ContextDelegate::ExecuteCommandList(ID3D11CommandList *pCommandList, BOOL RestoreContextState)
	{
		m_pReal->ExecuteCommandList(pCommandList, RestoreContextState);
	}

	void D3D11ContextDelegate::HSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		m_pReal->HSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::HSSetShader(ID3D11HullShader *pHullShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		m_pReal->HSSetShader(pHullShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextDelegate::HSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		m_pReal->HSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::HSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		m_pReal->HSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::DSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		m_pReal->DSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::DSSetShader(ID3D11DomainShader *pDomainShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		m_pReal->DSSetShader(pDomainShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextDelegate::DSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		m_pReal->DSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::DSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		m_pReal->DSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::CSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		m_pReal->CSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::CSSetUnorderedAccessViews(UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, const UINT *pUAVInitialCounts)
	{
		m_pReal->CSSetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
	}

	void D3D11ContextDelegate::CSSetShader(ID3D11ComputeShader *pComputeShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		m_pReal->CSSetShader(pComputeShader, ppClassInstances, NumClassInstances);
	}

	void D3D11ContextDelegate::CSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		m_pReal->CSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::CSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		m_pReal->CSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::VSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers)
	{
		m_pReal->VSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::PSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		m_pReal->PSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::PSGetShader(ID3D11PixelShader **ppPixelShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances)
	{
		m_pReal->PSGetShader(ppPixelShader, ppClassInstances, pNumClassInstances);
	}

	void D3D11ContextDelegate::PSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers)
	{
		m_pReal->PSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::VSGetShader(ID3D11VertexShader **ppVertexShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances)
	{
		m_pReal->VSGetShader(ppVertexShader, ppClassInstances, pNumClassInstances);
	}

	void D3D11ContextDelegate::PSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers)
	{
		m_pReal->PSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::IAGetInputLayout(ID3D11InputLayout **ppInputLayout)
	{
		m_pReal->IAGetInputLayout(ppInputLayout);
	}

	void D3D11ContextDelegate::IAGetVertexBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppVertexBuffers, UINT *pStrides, UINT *pOffsets)
	{
		m_pReal->IAGetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
	}

	void D3D11ContextDelegate::IAGetIndexBuffer(ID3D11Buffer **pIndexBuffer, DXGI_FORMAT *Format, UINT *Offset)
	{
		m_pReal->IAGetIndexBuffer(pIndexBuffer, Format, Offset);
	}

	void D3D11ContextDelegate::GSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers)
	{
		m_pReal->GSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::GSGetShader(ID3D11GeometryShader **ppGeometryShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances)
	{
		m_pReal->GSGetShader(ppGeometryShader, ppClassInstances, pNumClassInstances);
	}

	void D3D11ContextDelegate::IAGetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY *pTopology)
	{
		m_pReal->IAGetPrimitiveTopology(pTopology);
	}

	void D3D11ContextDelegate::VSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		m_pReal->VSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::VSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers)
	{
		m_pReal->VSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::GetPredication(ID3D11Predicate **ppPredicate, BOOL *pPredicateValue)
	{
		m_pReal->GetPredication(ppPredicate, pPredicateValue);
	}

	void D3D11ContextDelegate::GSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		m_pReal->GSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::GSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers)
	{
		m_pReal->GSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::OMGetRenderTargets(UINT NumViews, ID3D11RenderTargetView **ppRenderTargetViews, ID3D11DepthStencilView **ppDepthStencilView)
	{
		m_pReal->OMGetRenderTargets(NumViews, ppRenderTargetViews, ppDepthStencilView);
	}

	void D3D11ContextDelegate::OMGetRenderTargetsAndUnorderedAccessViews(UINT NumRTVs, ID3D11RenderTargetView **ppRenderTargetViews, ID3D11DepthStencilView **ppDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView **ppUnorderedAccessViews)
	{
		m_pReal->OMGetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, ppDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews);
	}

	void D3D11ContextDelegate::OMGetBlendState(ID3D11BlendState **ppBlendState, FLOAT BlendFactor[4], UINT *pSampleMask)
	{
		m_pReal->OMGetBlendState(ppBlendState, BlendFactor, pSampleMask);
	}

	void D3D11ContextDelegate::OMGetDepthStencilState(ID3D11DepthStencilState **ppDepthStencilState, UINT *pStencilRef)
	{
		m_pReal->OMGetDepthStencilState(ppDepthStencilState, pStencilRef);
	}

	void D3D11ContextDelegate::SOGetTargets(UINT NumBuffers, ID3D11Buffer **ppSOTargets)
	{
		m_pReal->SOGetTargets(NumBuffers, ppSOTargets);
	}

	void D3D11ContextDelegate::RSGetState(ID3D11RasterizerState **ppRasterizerState)
	{
		m_pReal->RSGetState(ppRasterizerState);
	}

	void D3D11ContextDelegate::RSGetViewports(UINT *pNumViewports, D3D11_VIEWPORT *pViewports)
	{
		m_pReal->RSGetViewports(pNumViewports, pViewports);
	}

	void D3D11ContextDelegate::RSGetScissorRects(UINT *pNumRects, D3D11_RECT *pRects)
	{
		m_pReal->RSGetScissorRects(pNumRects, pRects);
	}

	void D3D11ContextDelegate::HSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		m_pReal->HSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::HSGetShader(ID3D11HullShader **ppHullShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances)
	{
		m_pReal->HSGetShader(ppHullShader, ppClassInstances, pNumClassInstances);
	}

	void D3D11ContextDelegate::HSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers)
	{
		m_pReal->HSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::HSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers)
	{
		m_pReal->HSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::DSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		m_pReal->DSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::DSGetShader(ID3D11DomainShader **ppDomainShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances)
	{
		m_pReal->DSGetShader(ppDomainShader, ppClassInstances, pNumClassInstances);
	}

	void D3D11ContextDelegate::DSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers)
	{
		m_pReal->DSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::DSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers)
	{
		m_pReal->DSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::CSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		m_pReal->CSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void D3D11ContextDelegate::CSGetUnorderedAccessViews(UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView **ppUnorderedAccessViews)
	{
		m_pReal->CSGetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews);
	}

	void D3D11ContextDelegate::CSGetShader(ID3D11ComputeShader **ppComputeShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances)
	{
		m_pReal->CSGetShader(ppComputeShader, ppClassInstances, pNumClassInstances);
	}

	void D3D11ContextDelegate::CSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers)
	{
		m_pReal->CSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::CSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers)
	{
		m_pReal->CSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void D3D11ContextDelegate::ClearState()
	{
		m_pReal->ClearState();
	}

	void D3D11ContextDelegate::Flush()
	{
		m_pReal->Flush();
	}

	D3D11_DEVICE_CONTEXT_TYPE D3D11ContextDelegate::GetType()
	{
		return m_pReal->GetType();
	}

	UINT D3D11ContextDelegate::GetContextFlags()
	{
		return m_pReal->GetContextFlags();
	}

	HRESULT D3D11ContextDelegate::FinishCommandList(BOOL RestoreDeferredContextState, ID3D11CommandList **ppCommandList)
	{
		return m_pReal->FinishCommandList(RestoreDeferredContextState, ppCommandList);
	}
}
