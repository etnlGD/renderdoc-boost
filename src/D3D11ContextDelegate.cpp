#include "D3D11ContextDelegate.h"
#include "WrappedD3D11Resource.h"
#include "WrappedD3D11View.h"
#include "WrappedD3D11State.h"
#include "WrappedD3D11Shader.h"
#include "Log.h"

namespace rdclight
{

	D3D11ContextDelegate::D3D11ContextDelegate(
		ID3D11DeviceContext* pRealContext, WrappedD3D11Device* pWrappedDevice) :
		WrappedD3D11DeviceChild(pRealContext, pWrappedDevice)
	{
	}

#pragma region SetConstantBuffers
	void D3D11ContextDelegate::SetConstantBuffers_imp(
		UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers, 
		void (STDMETHODCALLTYPE ID3D11DeviceContext::* pfn)(UINT, UINT, ID3D11Buffer*const*))
	{
		ID3D11Buffer* pUnwrapped[D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT];
		(GetActivePtr()->*pfn)(StartSlot, NumBuffers, 
							   Unwrap(NumBuffers, ppConstantBuffers, pUnwrapped));
	}

	void D3D11ContextDelegate::VSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::VSSetConstantBuffers);
	}

	void D3D11ContextDelegate::HSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::HSSetConstantBuffers);
	}

	void D3D11ContextDelegate::DSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::DSSetConstantBuffers);
	}

	void D3D11ContextDelegate::GSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::GSSetConstantBuffers);
	}

	void D3D11ContextDelegate::PSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::PSSetConstantBuffers);
	}

	void D3D11ContextDelegate::CSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::CSSetConstantBuffers);
	}
#pragma endregion SetConstantBuffers


#pragma region SetShaderResources
	void D3D11ContextDelegate::SetShaderResources_imp(
		UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews, 
		void (STDMETHODCALLTYPE ID3D11DeviceContext::* pfn)(UINT, UINT, ID3D11ShaderResourceView*const*))
	{
		ID3D11ShaderResourceView* pUnwrapped[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT];
		(GetActivePtr()->*pfn)(StartSlot, NumViews, 
								Unwrap(NumViews, ppShaderResourceViews, pUnwrapped));
	}

	void D3D11ContextDelegate::VSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::VSSetShaderResources);
	}

	void D3D11ContextDelegate::HSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::HSSetShaderResources);
	}

	void D3D11ContextDelegate::DSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::DSSetShaderResources);
	}

	void D3D11ContextDelegate::GSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::GSSetShaderResources);
	}

	void D3D11ContextDelegate::PSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::PSSetShaderResources);
	}

	void D3D11ContextDelegate::CSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::CSSetShaderResources);
	}
#pragma endregion SetShaderResources


#pragma region SetSamplers
	void D3D11ContextDelegate::SetSamplers_imp(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers, void (STDMETHODCALLTYPE ID3D11DeviceContext::* pfn)(UINT, UINT, ID3D11SamplerState*const*))
	{
		ID3D11SamplerState* pUnwrapped[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT];
		(GetActivePtr()->*pfn)(StartSlot, NumSamplers,
								Unwrap(NumSamplers, ppSamplers, pUnwrapped));
	}

	void D3D11ContextDelegate::VSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		GetActivePtr()->VSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::HSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		GetActivePtr()->HSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::DSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		GetActivePtr()->DSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::GSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		GetActivePtr()->GSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::PSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		GetActivePtr()->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void D3D11ContextDelegate::CSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		GetActivePtr()->CSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}
#pragma endregion SetSamplers


#pragma region SetShader
	template <typename WrappedShaderType, typename ShaderType>
	inline static void SetShader_imp(
		ID3D11DeviceContext* pActive, ShaderType* pShader, bool inCapture,
		void (STDMETHODCALLTYPE ID3D11DeviceContext::*pfn)(ShaderType*, ID3D11ClassInstance*const*, UINT))
	{
		if (pShader == NULL)
		{
			(pActive->*pfn)(NULL, NULL, 0);
		}
		else
		{
			ShaderType* pUnwrapped = UnwrapSelf(pShader, inCapture);
			(pActive->*pfn)(pUnwrapped, NULL, 0);
		}
	}

	void D3D11ContextDelegate::VSSetShader(ID3D11VertexShader *pVertexShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11VertexShader>(GetActivePtr(), pVertexShader, InCapture(),
												&ID3D11DeviceContext::VSSetShader);
	}

	void D3D11ContextDelegate::HSSetShader(ID3D11HullShader *pHullShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11HullShader>(GetActivePtr(), pHullShader, InCapture(),
												&ID3D11DeviceContext::HSSetShader);
	}

	void D3D11ContextDelegate::DSSetShader(ID3D11DomainShader *pDomainShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11DomainShader>(GetActivePtr(), pDomainShader, InCapture(),
												&ID3D11DeviceContext::DSSetShader);
	}

	void D3D11ContextDelegate::GSSetShader(ID3D11GeometryShader *pShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11GeometryShader>(GetActivePtr(), pShader, InCapture(),
												&ID3D11DeviceContext::GSSetShader);
	}

	void D3D11ContextDelegate::PSSetShader(ID3D11PixelShader *pPixelShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11PixelShader>(GetActivePtr(), pPixelShader, InCapture(),
												&ID3D11DeviceContext::PSSetShader);
	}

	void D3D11ContextDelegate::CSSetShader(ID3D11ComputeShader *pComputeShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11ComputeShader>(GetActivePtr(), pComputeShader, InCapture(),
												&ID3D11DeviceContext::CSSetShader);
	}
#pragma endregion SetShader


	void D3D11ContextDelegate::DrawIndexed(UINT IndexCount, UINT StartIndexLocation, 
										   INT BaseVertexLocation)
	{
		GetActivePtr()->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
	}

	void D3D11ContextDelegate::Draw(UINT VertexCount, UINT StartVertexLocation)
	{
		GetActivePtr()->Draw(VertexCount, StartVertexLocation);
	}

	HRESULT D3D11ContextDelegate::Map(ID3D11Resource *pResource, UINT Subresource, 
									  D3D11_MAP MapType, UINT MapFlags, 
									  D3D11_MAPPED_SUBRESOURCE *pMappedResource)
	{
		return GetActivePtr()->Map(Unwrap(pResource), Subresource, MapType, MapFlags, pMappedResource);
	}

	void D3D11ContextDelegate::Unmap(ID3D11Resource *pResource, UINT Subresource)
	{
		GetActivePtr()->Unmap(Unwrap(pResource), Subresource);
	}

	void D3D11ContextDelegate::IASetInputLayout(ID3D11InputLayout *pInputLayout)
	{
		GetActivePtr()->IASetInputLayout(Unwrap(pInputLayout));
	}

	void D3D11ContextDelegate::IASetVertexBuffers(UINT StartSlot, UINT NumBuffers, 
												  ID3D11Buffer *const *ppVertexBuffers, 
												  const UINT *pStrides, const UINT *pOffsets)
	{
		ID3D11Buffer* pUnwrappedBuffers[D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT];
		GetActivePtr()->IASetVertexBuffers(
			StartSlot, NumBuffers, Unwrap(NumBuffers, ppVertexBuffers, pUnwrappedBuffers), 
			pStrides, pOffsets);
	}

	void D3D11ContextDelegate::IASetIndexBuffer(ID3D11Buffer *pIndexBuffer, DXGI_FORMAT Format, 
												UINT Offset)
	{
		GetActivePtr()->IASetIndexBuffer(Unwrap(pIndexBuffer), Format, Offset);
	}

	void D3D11ContextDelegate::DrawIndexedInstanced(
		UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, 
		INT BaseVertexLocation, UINT StartInstanceLocation)
	{
		GetActivePtr()->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, 
											 StartIndexLocation, BaseVertexLocation, 
											 StartInstanceLocation);
	}

	void D3D11ContextDelegate::DrawInstanced(UINT VertexCountPerInstance, UINT InstanceCount, 
											 UINT StartVertexLocation, 
											 UINT StartInstanceLocation)
	{
		GetActivePtr()->DrawInstanced(VertexCountPerInstance, InstanceCount, 
									  StartVertexLocation, StartInstanceLocation);
	}

	void D3D11ContextDelegate::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
	{
		GetActivePtr()->IASetPrimitiveTopology(Topology);
	}

	void D3D11ContextDelegate::Begin(ID3D11Asynchronous *pAsync)
	{
		GetActivePtr()->Begin(Unwrap(pAsync));
	}

	void D3D11ContextDelegate::End(ID3D11Asynchronous *pAsync)
	{
		GetActivePtr()->End(Unwrap(pAsync));
	}

	HRESULT D3D11ContextDelegate::GetData(ID3D11Asynchronous *pAsync, void *pData, UINT DataSize, UINT GetDataFlags)
	{
		return GetActivePtr()->GetData(Unwrap(pAsync), pData, DataSize, GetDataFlags);
	}

	void D3D11ContextDelegate::SetPredication(ID3D11Predicate *pPredicate, BOOL PredicateValue)
	{
		GetActivePtr()->SetPredication(Unwrap(pPredicate), PredicateValue);
	}

	void D3D11ContextDelegate::OMSetRenderTargets(UINT NumViews, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView)
	{
		ID3D11RenderTargetView* pUnwrappedRTViews[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];
		GetActivePtr()->OMSetRenderTargets(NumViews, 
										   Unwrap(NumViews, ppRenderTargetViews, pUnwrappedRTViews),
										   Unwrap(pDepthStencilView));
	}

	void D3D11ContextDelegate::OMSetRenderTargetsAndUnorderedAccessViews(
		UINT NumRTVs, ID3D11RenderTargetView *const *ppRenderTargetViews, 
		ID3D11DepthStencilView *pDepthStencilView, 
		UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, 
		const UINT *pUAVInitialCounts)
	{
		ID3D11RenderTargetView* pUnwrappedRTViews[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];
		ID3D11UnorderedAccessView* pUnwrappedUAViews[D3D11_1_UAV_SLOT_COUNT];
		GetActivePtr()->OMSetRenderTargetsAndUnorderedAccessViews(
			NumRTVs, Unwrap(NumRTVs, ppRenderTargetViews, pUnwrappedRTViews), 
			Unwrap(pDepthStencilView),
			UAVStartSlot, NumUAVs, Unwrap(NumUAVs, ppUnorderedAccessViews, pUnwrappedUAViews), 
			pUAVInitialCounts);
	}

	void D3D11ContextDelegate::OMSetBlendState(ID3D11BlendState *pBlendState, const FLOAT BlendFactor[4], UINT SampleMask)
	{
		GetActivePtr()->OMSetBlendState(Unwrap(pBlendState), BlendFactor, SampleMask);
	}

	void D3D11ContextDelegate::OMSetDepthStencilState(ID3D11DepthStencilState *pDepthStencilState, UINT StencilRef)
	{
		GetActivePtr()->OMSetDepthStencilState(Unwrap(pDepthStencilState), StencilRef);
	}

	void D3D11ContextDelegate::SOSetTargets(UINT NumBuffers, ID3D11Buffer *const *ppSOTargets, const UINT *pOffsets)
	{
		ID3D11Buffer* pUnwrappedSOTargets[D3D11_SO_BUFFER_SLOT_COUNT];
		GetActivePtr()->SOSetTargets(NumBuffers, 
									 Unwrap(NumBuffers, ppSOTargets, pUnwrappedSOTargets), 
									 pOffsets);
	}

	void D3D11ContextDelegate::CSSetUnorderedAccessViews(
		UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, 
		const UINT *pUAVInitialCounts)
	{
		ID3D11UnorderedAccessView* pUnwrappedUAViews[D3D11_1_UAV_SLOT_COUNT];
		GetActivePtr()->CSSetUnorderedAccessViews(
			StartSlot, NumUAVs, Unwrap(NumUAVs, ppUnorderedAccessViews, pUnwrappedUAViews), 
			pUAVInitialCounts);
	}

	void D3D11ContextDelegate::DrawAuto()
	{
		GetActivePtr()->DrawAuto();
	}

	void D3D11ContextDelegate::DrawIndexedInstancedIndirect(
		ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		GetActivePtr()->DrawIndexedInstancedIndirect(Unwrap(pBufferForArgs), AlignedByteOffsetForArgs);
	}

	void D3D11ContextDelegate::DrawInstancedIndirect(ID3D11Buffer *pBufferForArgs, 
													 UINT AlignedByteOffsetForArgs)
	{
		GetActivePtr()->DrawInstancedIndirect(Unwrap(pBufferForArgs), AlignedByteOffsetForArgs);
	}

	void D3D11ContextDelegate::Dispatch(UINT ThreadGroupCountX, UINT ThreadGroupCountY, 
										UINT ThreadGroupCountZ)
	{
		GetActivePtr()->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
	}

	void D3D11ContextDelegate::DispatchIndirect(ID3D11Buffer *pBufferForArgs, 
												UINT AlignedByteOffsetForArgs)
	{
		GetActivePtr()->DispatchIndirect(Unwrap(pBufferForArgs), AlignedByteOffsetForArgs);
	}

	void D3D11ContextDelegate::RSSetState(ID3D11RasterizerState *pRasterizerState)
	{
		GetActivePtr()->RSSetState(Unwrap(pRasterizerState));
	}

	void D3D11ContextDelegate::RSSetViewports(UINT NumViewports, const D3D11_VIEWPORT *pViewports)
	{
		GetActivePtr()->RSSetViewports(NumViewports, pViewports);
	}

	void D3D11ContextDelegate::RSSetScissorRects(UINT NumRects, const D3D11_RECT *pRects)
	{
		GetActivePtr()->RSSetScissorRects(NumRects, pRects);
	}

	void D3D11ContextDelegate::CopySubresourceRegion(
		ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, 
		ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox)
	{
		GetActivePtr()->CopySubresourceRegion(
			Unwrap(pDstResource), DstSubresource, DstX, DstY, DstZ, 
			Unwrap(pSrcResource), SrcSubresource, pSrcBox);
	}

	void D3D11ContextDelegate::CopyResource(ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource)
	{
		GetActivePtr()->CopyResource(Unwrap(pDstResource), Unwrap(pSrcResource));
	}

	void D3D11ContextDelegate::UpdateSubresource(
		ID3D11Resource *pDstResource, UINT DstSubresource, const D3D11_BOX *pDstBox, 
		const void *pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
	{
		GetActivePtr()->UpdateSubresource(Unwrap(pDstResource), DstSubresource, pDstBox, 
										  pSrcData, SrcRowPitch, SrcDepthPitch);
	}

	void D3D11ContextDelegate::CopyStructureCount(ID3D11Buffer *pDstBuffer, UINT DstAlignedByteOffset, 
												  ID3D11UnorderedAccessView *pSrcView)
	{
		GetActivePtr()->CopyStructureCount(
			Unwrap(pDstBuffer), DstAlignedByteOffset, Unwrap(pSrcView));
	}

	void D3D11ContextDelegate::ClearRenderTargetView(ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4])
	{
		GetActivePtr()->ClearRenderTargetView(Unwrap(pRenderTargetView), ColorRGBA);
	}

	void D3D11ContextDelegate::ClearUnorderedAccessViewUint(ID3D11UnorderedAccessView *pUnorderedAccessView, const UINT Values[4])
	{
		GetActivePtr()->ClearUnorderedAccessViewUint(Unwrap(pUnorderedAccessView), Values);
	}

	void D3D11ContextDelegate::ClearUnorderedAccessViewFloat(ID3D11UnorderedAccessView *pUnorderedAccessView, const FLOAT Values[4])
	{
		GetActivePtr()->ClearUnorderedAccessViewFloat(Unwrap(pUnorderedAccessView), Values);
	}

	void D3D11ContextDelegate::ClearDepthStencilView(ID3D11DepthStencilView *pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil)
	{
		GetActivePtr()->ClearDepthStencilView(Unwrap(pDepthStencilView), ClearFlags, Depth, Stencil);
	}

	void D3D11ContextDelegate::GenerateMips(ID3D11ShaderResourceView *pShaderResourceView)
	{
		GetActivePtr()->GenerateMips(Unwrap(pShaderResourceView));
	}

	void D3D11ContextDelegate::SetResourceMinLOD(ID3D11Resource *pResource, FLOAT MinLOD)
	{
		GetActivePtr()->SetResourceMinLOD(Unwrap(pResource), MinLOD);
	}

	FLOAT D3D11ContextDelegate::GetResourceMinLOD(ID3D11Resource *pResource)
	{
		return GetActivePtr()->GetResourceMinLOD(Unwrap(pResource));
	}

	void D3D11ContextDelegate::ResolveSubresource(
		ID3D11Resource *pDstResource, UINT DstSubresource, 
		ID3D11Resource *pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format)
	{
		GetActivePtr()->ResolveSubresource(Unwrap(pDstResource), DstSubresource, 
										   Unwrap(pSrcResource), SrcSubresource, Format);
	}

	void D3D11ContextDelegate::ExecuteCommandList(ID3D11CommandList *pCommandList, BOOL RestoreContextState)
	{
		// not support yet.
// 		GetActivePtr()->ExecuteCommandList(pCommandList, RestoreContextState);
	}


#pragma region GetShaderState
	void D3D11ContextDelegate::VSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->VSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void D3D11ContextDelegate::VSGetShader(ID3D11VertexShader **ppVertexShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->VSGetShader(ppVertexShader, NULL, pNumClassInstances);
		Wrap(ppVertexShader);
	}

	void D3D11ContextDelegate::VSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->VSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void D3D11ContextDelegate::VSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->VSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void D3D11ContextDelegate::HSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->HSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void D3D11ContextDelegate::HSGetShader(ID3D11HullShader **ppHullShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->HSGetShader(ppHullShader, NULL, pNumClassInstances);
		Wrap(ppHullShader);
	}

	void D3D11ContextDelegate::HSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->HSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void D3D11ContextDelegate::HSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->HSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void D3D11ContextDelegate::DSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->DSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void D3D11ContextDelegate::DSGetShader(ID3D11DomainShader **ppDomainShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->DSGetShader(ppDomainShader, NULL, pNumClassInstances);
		Wrap(ppDomainShader);
	}

	void D3D11ContextDelegate::DSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->DSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void D3D11ContextDelegate::DSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->DSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void D3D11ContextDelegate::GSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->GSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void D3D11ContextDelegate::GSGetShader(ID3D11GeometryShader **ppGeometryShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->GSGetShader(ppGeometryShader, NULL, pNumClassInstances);
		Wrap(ppGeometryShader);
	}

	void D3D11ContextDelegate::GSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->GSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void D3D11ContextDelegate::GSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->GSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void D3D11ContextDelegate::PSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->PSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void D3D11ContextDelegate::PSGetShader(ID3D11PixelShader **ppPixelShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->PSGetShader(ppPixelShader, NULL, pNumClassInstances);
		Wrap(ppPixelShader);
	}

	void D3D11ContextDelegate::PSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->PSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void D3D11ContextDelegate::PSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->PSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void D3D11ContextDelegate::CSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->CSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void D3D11ContextDelegate::CSGetUnorderedAccessViews(UINT StartSlot, UINT NumUAVs, 
														 ID3D11UnorderedAccessView **ppUnorderedAccessViews)
	{
		GetActivePtr()->CSGetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews);
		Wrap(ppUnorderedAccessViews, NumUAVs);
	}

	void D3D11ContextDelegate::CSGetShader(ID3D11ComputeShader **ppComputeShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->CSGetShader(ppComputeShader, NULL, pNumClassInstances);
		Wrap(ppComputeShader);
	}

	void D3D11ContextDelegate::CSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->CSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void D3D11ContextDelegate::CSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->CSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}
#pragma endregion GetShaderState


#pragma region GetPipelineState
	void D3D11ContextDelegate::IAGetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY *pTopology)
	{
		GetActivePtr()->IAGetPrimitiveTopology(pTopology);
	}

	void D3D11ContextDelegate::IAGetInputLayout(ID3D11InputLayout **ppInputLayout)
	{
		GetActivePtr()->IAGetInputLayout(ppInputLayout);
		Wrap(ppInputLayout);
	}

	void D3D11ContextDelegate::IAGetVertexBuffers(
		UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppVertexBuffers, 
		UINT *pStrides, UINT *pOffsets)
	{
		GetActivePtr()->IAGetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
		Wrap(ppVertexBuffers, NumBuffers);
	}

	void D3D11ContextDelegate::IAGetIndexBuffer(ID3D11Buffer **pIndexBuffer, 
												DXGI_FORMAT *Format, UINT *Offset)
	{
		GetActivePtr()->IAGetIndexBuffer(pIndexBuffer, Format, Offset);
		Wrap(pIndexBuffer);
	}

	void D3D11ContextDelegate::SOGetTargets(UINT NumBuffers, ID3D11Buffer **ppSOTargets)
	{
		GetActivePtr()->SOGetTargets(NumBuffers, ppSOTargets);
		Wrap(ppSOTargets, NumBuffers);
	}

	void D3D11ContextDelegate::RSGetState(ID3D11RasterizerState **ppRasterizerState)
	{
		GetActivePtr()->RSGetState(ppRasterizerState);
		Wrap(ppRasterizerState);
	}

	void D3D11ContextDelegate::RSGetViewports(UINT *pNumViewports, D3D11_VIEWPORT *pViewports)
	{
		GetActivePtr()->RSGetViewports(pNumViewports, pViewports);
	}

	void D3D11ContextDelegate::RSGetScissorRects(UINT *pNumRects, D3D11_RECT *pRects)
	{
		GetActivePtr()->RSGetScissorRects(pNumRects, pRects);
	}

	void D3D11ContextDelegate::OMGetRenderTargets(
		UINT NumViews, ID3D11RenderTargetView **ppRenderTargetViews, 
		ID3D11DepthStencilView **ppDepthStencilView)
	{
		GetActivePtr()->OMGetRenderTargets(NumViews, ppRenderTargetViews, ppDepthStencilView);
		Wrap(ppRenderTargetViews, NumViews);
		Wrap(ppDepthStencilView);
	}

	void D3D11ContextDelegate::OMGetRenderTargetsAndUnorderedAccessViews(
		UINT NumRTVs, ID3D11RenderTargetView **ppRenderTargetViews, 
		ID3D11DepthStencilView **ppDepthStencilView, 
		UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView **ppUnorderedAccessViews)
	{
		GetActivePtr()->OMGetRenderTargetsAndUnorderedAccessViews(
			NumRTVs, ppRenderTargetViews, ppDepthStencilView, 
			UAVStartSlot, NumUAVs, ppUnorderedAccessViews);

		Wrap(ppRenderTargetViews, NumRTVs);
		Wrap(ppDepthStencilView);
		Wrap(ppUnorderedAccessViews, NumUAVs);
	}

	void D3D11ContextDelegate::OMGetBlendState(ID3D11BlendState **ppBlendState, FLOAT BlendFactor[4], UINT *pSampleMask)
	{
		GetActivePtr()->OMGetBlendState(ppBlendState, BlendFactor, pSampleMask);
		Wrap(ppBlendState);
	}

	void D3D11ContextDelegate::OMGetDepthStencilState(ID3D11DepthStencilState **ppDepthStencilState, UINT *pStencilRef)
	{
		GetActivePtr()->OMGetDepthStencilState(ppDepthStencilState, pStencilRef);
		Wrap(ppDepthStencilState);
	}

	void D3D11ContextDelegate::GetPredication(ID3D11Predicate **ppPredicate, BOOL *pPredicateValue)
	{
		GetActivePtr()->GetPredication(ppPredicate, pPredicateValue);
		Wrap(ppPredicate);
	}
#pragma endregion GetPipelineState


	void D3D11ContextDelegate::ClearState()
	{
		GetActivePtr()->ClearState();
	}

	void D3D11ContextDelegate::Flush()
	{
		GetActivePtr()->Flush();
	}

	D3D11_DEVICE_CONTEXT_TYPE D3D11ContextDelegate::GetType()
	{
		return GetActivePtr()->GetType();
	}

	UINT D3D11ContextDelegate::GetContextFlags()
	{
		return GetActivePtr()->GetContextFlags();
	}

	HRESULT D3D11ContextDelegate::FinishCommandList(BOOL RestoreDeferredContextState, 
													ID3D11CommandList **ppCommandList)
	{
		return GetActivePtr()->FinishCommandList(RestoreDeferredContextState, ppCommandList);
	}

	ID3D11DeviceChild* D3D11ContextDelegate::CopyToDevice(ID3D11Device* pNewDevice)
	{
		if (GetReal()->GetType() == D3D11_DEVICE_CONTEXT_IMMEDIATE)
		{
			ID3D11DeviceContext* pNewImmediateContext = NULL;
			pNewDevice->GetImmediateContext(&pNewImmediateContext);
			// TODO_wzq copy pipeline state to new immediate context.

			return pNewImmediateContext;
		}
		else
		{
			LogError("Deferred context is not supported by now");
			return NULL;
		}
	}

}
