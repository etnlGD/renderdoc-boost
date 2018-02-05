#include "WrappedD3D11Context.h"
#include "WrappedD3D11Resource.h"
#include "WrappedD3D11View.h"
#include "WrappedD3D11State.h"
#include "WrappedD3D11Shader.h"
#include "Log.h"
#include "DeviceContextState.h"
#include "WrappedD3D11Async.h"
#include <d3d11_1.h>

namespace rdcboost
{

	WrappedD3D11Context::WrappedD3D11Context(
		ID3D11DeviceContext* pRealContext, WrappedD3D11Device* pWrappedDevice) :
		WrappedD3D11DeviceChild(pRealContext, pWrappedDevice)
	{
		memset(m_SOOffsets, 0, sizeof(m_SOOffsets));
	}

	HRESULT STDMETHODCALLTYPE WrappedD3D11Context::QueryInterface(REFIID riid, void **ppvObject)
	{
		if (riid == __uuidof(ID3DUserDefinedAnnotation))
		{
			return GetActivePtr()->QueryInterface(riid, ppvObject);
		}

		return WrappedD3D11DeviceChild<ID3D11DeviceContext>::QueryInterface(riid, ppvObject);
	}

	ULONG STDMETHODCALLTYPE WrappedD3D11Context::Release(void)
	{
		unsigned int ret = InterlockedDecrement(&m_Ref);
		if (ret == 1)
		{
			m_pWrappedDevice->TryToRelease();
		}
		else if (ret == 0)
		{
			delete this;
		}

		return ret;
	}

#pragma region SetConstantBuffers
	void WrappedD3D11Context::SetConstantBuffers_imp(
		UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers, 
		void (STDMETHODCALLTYPE ID3D11DeviceContext::* pfn)(UINT, UINT, ID3D11Buffer*const*))
	{
		ID3D11Buffer* pUnwrapped[D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT];
		(GetActivePtr()->*pfn)(StartSlot, NumBuffers, 
							   Unwrap(NumBuffers, ppConstantBuffers, pUnwrapped));
	}

	void WrappedD3D11Context::VSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::VSSetConstantBuffers);
	}

	void WrappedD3D11Context::HSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::HSSetConstantBuffers);
	}

	void WrappedD3D11Context::DSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::DSSetConstantBuffers);
	}

	void WrappedD3D11Context::GSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::GSSetConstantBuffers);
	}

	void WrappedD3D11Context::PSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::PSSetConstantBuffers);
	}

	void WrappedD3D11Context::CSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers)
	{
		SetConstantBuffers_imp(StartSlot, NumBuffers, ppConstantBuffers,
							   &ID3D11DeviceContext::CSSetConstantBuffers);
	}
#pragma endregion SetConstantBuffers


#pragma region SetShaderResources
	void WrappedD3D11Context::SetShaderResources_imp(
		UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews, 
		void (STDMETHODCALLTYPE ID3D11DeviceContext::* pfn)(UINT, UINT, ID3D11ShaderResourceView*const*))
	{
		ID3D11ShaderResourceView* pUnwrapped[D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT];
		(GetActivePtr()->*pfn)(StartSlot, NumViews, 
								Unwrap(NumViews, ppShaderResourceViews, pUnwrapped));
	}

	void WrappedD3D11Context::VSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::VSSetShaderResources);
	}

	void WrappedD3D11Context::HSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::HSSetShaderResources);
	}

	void WrappedD3D11Context::DSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::DSSetShaderResources);
	}

	void WrappedD3D11Context::GSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::GSSetShaderResources);
	}

	void WrappedD3D11Context::PSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::PSSetShaderResources);
	}

	void WrappedD3D11Context::CSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
	{
		SetShaderResources_imp(StartSlot, NumViews, ppShaderResourceViews,
							   &ID3D11DeviceContext::CSSetShaderResources);
	}
#pragma endregion SetShaderResources


#pragma region SetSamplers
	void WrappedD3D11Context::SetSamplers_imp(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers, void (STDMETHODCALLTYPE ID3D11DeviceContext::* pfn)(UINT, UINT, ID3D11SamplerState*const*))
	{
		ID3D11SamplerState* pUnwrapped[D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT];
		(GetActivePtr()->*pfn)(StartSlot, NumSamplers,
								Unwrap(NumSamplers, ppSamplers, pUnwrapped));
	}

	void WrappedD3D11Context::VSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		SetSamplers_imp(StartSlot, NumSamplers, ppSamplers, &ID3D11DeviceContext::VSSetSamplers);
	}

	void WrappedD3D11Context::HSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		SetSamplers_imp(StartSlot, NumSamplers, ppSamplers, &ID3D11DeviceContext::HSSetSamplers);
	}

	void WrappedD3D11Context::DSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		SetSamplers_imp(StartSlot, NumSamplers, ppSamplers, &ID3D11DeviceContext::DSSetSamplers);
	}

	void WrappedD3D11Context::GSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		SetSamplers_imp(StartSlot, NumSamplers, ppSamplers, &ID3D11DeviceContext::GSSetSamplers);
	}

	void WrappedD3D11Context::PSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		SetSamplers_imp(StartSlot, NumSamplers, ppSamplers, &ID3D11DeviceContext::PSSetSamplers);
	}

	void WrappedD3D11Context::CSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers)
	{
		SetSamplers_imp(StartSlot, NumSamplers, ppSamplers, &ID3D11DeviceContext::CSSetSamplers);
	}
#pragma endregion SetSamplers


#pragma region SetShader
	template <typename WrappedShaderType, typename ShaderType>
	inline static void SetShader_imp(
		ID3D11DeviceContext* pActive, ShaderType* pShader,
		void (STDMETHODCALLTYPE ID3D11DeviceContext::*pfn)(ShaderType*, ID3D11ClassInstance*const*, UINT))
	{
		if (pShader == NULL)
		{
			(pActive->*pfn)(NULL, NULL, 0);
		}
		else
		{
			ShaderType* pUnwrapped = UnwrapSelf(pShader);
			(pActive->*pfn)(pUnwrapped, NULL, 0);
		}
	}

	void WrappedD3D11Context::VSSetShader(ID3D11VertexShader *pVertexShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11VertexShader>(GetActivePtr(), pVertexShader, 
												&ID3D11DeviceContext::VSSetShader);
	}

	void WrappedD3D11Context::HSSetShader(ID3D11HullShader *pHullShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11HullShader>(GetActivePtr(), pHullShader, 
												&ID3D11DeviceContext::HSSetShader);
	}

	void WrappedD3D11Context::DSSetShader(ID3D11DomainShader *pDomainShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11DomainShader>(GetActivePtr(), pDomainShader, 
												&ID3D11DeviceContext::DSSetShader);
	}

	void WrappedD3D11Context::GSSetShader(ID3D11GeometryShader *pShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11GeometryShader>(GetActivePtr(), pShader, 
												&ID3D11DeviceContext::GSSetShader);
	}

	void WrappedD3D11Context::PSSetShader(ID3D11PixelShader *pPixelShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11PixelShader>(GetActivePtr(), pPixelShader, 
												&ID3D11DeviceContext::PSSetShader);
	}

	void WrappedD3D11Context::CSSetShader(ID3D11ComputeShader *pComputeShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances)
	{
		SetShader_imp<WrappedD3D11ComputeShader>(GetActivePtr(), pComputeShader, 
												&ID3D11DeviceContext::CSSetShader);
	}
#pragma endregion SetShader


	void WrappedD3D11Context::DrawIndexed(UINT IndexCount, UINT StartIndexLocation, 
										   INT BaseVertexLocation)
	{
		GetActivePtr()->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
	}

	void WrappedD3D11Context::Draw(UINT VertexCount, UINT StartVertexLocation)
	{
		GetActivePtr()->Draw(VertexCount, StartVertexLocation);
	}

	void WrappedD3D11Context::DrawIndexedInstanced(
		UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation,
		INT BaseVertexLocation, UINT StartInstanceLocation)
	{
		GetActivePtr()->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount,
											 StartIndexLocation, BaseVertexLocation,
											 StartInstanceLocation);
	}

	void WrappedD3D11Context::DrawInstanced(UINT VertexCountPerInstance, UINT InstanceCount,
											UINT StartVertexLocation,
											UINT StartInstanceLocation)
	{
		GetActivePtr()->DrawInstanced(VertexCountPerInstance, InstanceCount,
									  StartVertexLocation, StartInstanceLocation);
	}

	void WrappedD3D11Context::DrawAuto()
	{
		GetActivePtr()->DrawAuto();
	}

	void WrappedD3D11Context::DrawIndexedInstancedIndirect(
		ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		GetActivePtr()->DrawIndexedInstancedIndirect(Unwrap(pBufferForArgs), AlignedByteOffsetForArgs);
	}

	void WrappedD3D11Context::DrawInstancedIndirect(ID3D11Buffer *pBufferForArgs,
													UINT AlignedByteOffsetForArgs)
	{
		GetActivePtr()->DrawInstancedIndirect(Unwrap(pBufferForArgs), AlignedByteOffsetForArgs);
	}

	void WrappedD3D11Context::Dispatch(UINT ThreadGroupCountX, UINT ThreadGroupCountY,
									   UINT ThreadGroupCountZ)
	{
		GetActivePtr()->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
	}

	void WrappedD3D11Context::DispatchIndirect(ID3D11Buffer *pBufferForArgs,
											   UINT AlignedByteOffsetForArgs)
	{
		GetActivePtr()->DispatchIndirect(Unwrap(pBufferForArgs), AlignedByteOffsetForArgs);
	}

	HRESULT WrappedD3D11Context::Map(ID3D11Resource *pResource, UINT Subresource, 
									 D3D11_MAP MapType, UINT MapFlags, 
									 D3D11_MAPPED_SUBRESOURCE *pMappedResource)
	{
		return GetActivePtr()->Map(Unwrap(pResource), Subresource, 
								   MapType, MapFlags, pMappedResource);
	}

	void WrappedD3D11Context::Unmap(ID3D11Resource *pResource, UINT Subresource)
	{
		GetActivePtr()->Unmap(Unwrap(pResource), Subresource);
	}

	void WrappedD3D11Context::IASetInputLayout(ID3D11InputLayout *pInputLayout)
	{
		GetActivePtr()->IASetInputLayout(Unwrap(pInputLayout));
	}

	void WrappedD3D11Context::IASetVertexBuffers(UINT StartSlot, UINT NumBuffers, 
												  ID3D11Buffer *const *ppVertexBuffers, 
												  const UINT *pStrides, const UINT *pOffsets)
	{
		ID3D11Buffer* pUnwrappedBuffers[D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT];
		GetActivePtr()->IASetVertexBuffers(
			StartSlot, NumBuffers, Unwrap(NumBuffers, ppVertexBuffers, pUnwrappedBuffers), 
			pStrides, pOffsets);
	}

	void WrappedD3D11Context::IASetIndexBuffer(ID3D11Buffer *pIndexBuffer, DXGI_FORMAT Format, 
											   UINT Offset)
	{
		GetActivePtr()->IASetIndexBuffer(Unwrap(pIndexBuffer), Format, Offset);
	}

	void WrappedD3D11Context::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
	{
		GetActivePtr()->IASetPrimitiveTopology(Topology);
	}

	void WrappedD3D11Context::Begin(ID3D11Asynchronous *pAsync)
	{
		do {
			if (pAsync == NULL)
				break;

			ID3D11Query* pQuery = NULL;
			pAsync->QueryInterface<ID3D11Query>(&pQuery);
			if (pQuery != NULL)
			{
				WrappedD3D11Query* pWrappedQuery = static_cast<WrappedD3D11Query*>(pQuery);
				pWrappedQuery->Begin();
				break;
			}

			ID3D11Counter* pCounter = NULL;
			pAsync->QueryInterface<ID3D11Counter>(&pCounter);
			if (pCounter != NULL)
			{
				WrappedD3D11Counter* pWrappedCounter = static_cast<WrappedD3D11Counter*>(pCounter);
				pWrappedCounter->Begin();
				break;
			}

			ID3D11Predicate* pPredicate = NULL;
			pAsync->QueryInterface<ID3D11Predicate>(&pPredicate);
			if (pPredicate != NULL)
			{
				WrappedD3D11Predicate* pWrappedPredicate = static_cast<WrappedD3D11Predicate*>(pPredicate);
				pWrappedPredicate->Begin();
				break;
			}
		} while (0);

		GetActivePtr()->Begin(Unwrap(pAsync));
	}

	void WrappedD3D11Context::End(ID3D11Asynchronous *pAsync)
	{
		do {
			if (pAsync == NULL)
				break;

			ID3D11Query* pQuery = NULL;
			pAsync->QueryInterface<ID3D11Query>(&pQuery);
			if (pQuery != NULL)
			{
				WrappedD3D11Query* pWrappedQuery = static_cast<WrappedD3D11Query*>(pQuery);
				pWrappedQuery->End();
				break;
			}

			ID3D11Counter* pCounter = NULL;
			pAsync->QueryInterface<ID3D11Counter>(&pCounter);
			if (pCounter != NULL)
			{
				WrappedD3D11Counter* pWrappedCounter = static_cast<WrappedD3D11Counter*>(pCounter);
				pWrappedCounter->End();
				break;
			}

			ID3D11Predicate* pPredicate = NULL;
			pAsync->QueryInterface<ID3D11Predicate>(&pPredicate);
			if (pPredicate != NULL)
			{
				WrappedD3D11Predicate* pWrappedPredicate = static_cast<WrappedD3D11Predicate*>(pPredicate);
				pWrappedPredicate->End();
				break;
			}
		} while (0);

		GetActivePtr()->End(Unwrap(pAsync));
	}

	HRESULT WrappedD3D11Context::GetData(ID3D11Asynchronous *pAsync, void *pData, 
										 UINT DataSize, UINT GetDataFlags)
	{
		return GetActivePtr()->GetData(Unwrap(pAsync), pData, DataSize, GetDataFlags);
	}

	void WrappedD3D11Context::SetPredication(ID3D11Predicate *pPredicate, BOOL PredicateValue)
	{
		GetActivePtr()->SetPredication(Unwrap(pPredicate), PredicateValue);
	}

	void WrappedD3D11Context::OMSetRenderTargets(
		UINT NumViews, ID3D11RenderTargetView *const *ppRenderTargetViews, 
		ID3D11DepthStencilView *pDepthStencilView)
	{
		ID3D11RenderTargetView* pUnwrappedRTViews[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];
		GetActivePtr()->OMSetRenderTargets(NumViews, 
										   Unwrap(NumViews, ppRenderTargetViews, pUnwrappedRTViews),
										   Unwrap(pDepthStencilView));
	}

	void WrappedD3D11Context::OMSetRenderTargetsAndUnorderedAccessViews(
		UINT NumRTVs, ID3D11RenderTargetView *const *ppRenderTargetViews, 
		ID3D11DepthStencilView *pDepthStencilView, 
		UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, 
		const UINT *pUAVInitialCounts)
	{
		ID3D11RenderTargetView* pUnwrappedRTViews[D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];
		ID3D11UnorderedAccessView* pUnwrappedUAViews[D3D11_1_UAV_SLOT_COUNT];

		ID3D11RenderTargetView** ppRTVs = NULL;
		ID3D11UnorderedAccessView** ppUAVs = NULL;
		if (NumRTVs != D3D11_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL)
			ppRTVs = Unwrap(NumRTVs, ppRenderTargetViews, pUnwrappedRTViews);

		if (NumUAVs != D3D11_KEEP_UNORDERED_ACCESS_VIEWS)
			ppUAVs = Unwrap(NumUAVs, ppUnorderedAccessViews, pUnwrappedUAViews);

		GetActivePtr()->OMSetRenderTargetsAndUnorderedAccessViews(
			NumRTVs, ppRTVs, Unwrap(pDepthStencilView),
			UAVStartSlot, NumUAVs, ppUAVs, pUAVInitialCounts);
	}

	void WrappedD3D11Context::OMSetBlendState(ID3D11BlendState *pBlendState, 
											  const FLOAT BlendFactor[4], UINT SampleMask)
	{
		GetActivePtr()->OMSetBlendState(Unwrap(pBlendState), BlendFactor, SampleMask);
	}

	void WrappedD3D11Context::OMSetDepthStencilState(
		ID3D11DepthStencilState *pDepthStencilState, UINT StencilRef)
	{
		GetActivePtr()->OMSetDepthStencilState(Unwrap(pDepthStencilState), StencilRef);
	}

	void WrappedD3D11Context::SOSetTargets(
		UINT NumBuffers, ID3D11Buffer *const *ppSOTargets, const UINT *pOffsets)
	{
		ID3D11Buffer* pUnwrappedSOTargets[D3D11_SO_BUFFER_SLOT_COUNT];
		for (UINT i = 0; i < D3D11_SO_BUFFER_SLOT_COUNT; ++i)
			m_SOOffsets[i] = (pOffsets && i < NumBuffers) ? pOffsets[i] : 0;

		GetActivePtr()->SOSetTargets(NumBuffers, 
									 Unwrap(NumBuffers, ppSOTargets, pUnwrappedSOTargets), 
									 pOffsets);
	}

	void WrappedD3D11Context::CSSetUnorderedAccessViews(
		UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, 
		const UINT *pUAVInitialCounts)
	{
		ID3D11UnorderedAccessView* pUnwrappedUAViews[D3D11_1_UAV_SLOT_COUNT];
		GetActivePtr()->CSSetUnorderedAccessViews(
			StartSlot, NumUAVs, Unwrap(NumUAVs, ppUnorderedAccessViews, pUnwrappedUAViews), 
			pUAVInitialCounts);
	}

	void WrappedD3D11Context::RSSetState(ID3D11RasterizerState *pRasterizerState)
	{
		GetActivePtr()->RSSetState(Unwrap(pRasterizerState));
	}

	void WrappedD3D11Context::RSSetViewports(UINT NumViewports, const D3D11_VIEWPORT *pViewports)
	{
		GetActivePtr()->RSSetViewports(NumViewports, pViewports);
	}

	void WrappedD3D11Context::RSSetScissorRects(UINT NumRects, const D3D11_RECT *pRects)
	{
		GetActivePtr()->RSSetScissorRects(NumRects, pRects);
	}

	void WrappedD3D11Context::CopySubresourceRegion(
		ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, 
		ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox)
	{
		GetActivePtr()->CopySubresourceRegion(
			Unwrap(pDstResource), DstSubresource, DstX, DstY, DstZ, 
			Unwrap(pSrcResource), SrcSubresource, pSrcBox);
	}

	void WrappedD3D11Context::CopyResource(ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource)
	{
		GetActivePtr()->CopyResource(Unwrap(pDstResource), Unwrap(pSrcResource));
	}

	void WrappedD3D11Context::UpdateSubresource(
		ID3D11Resource *pDstResource, UINT DstSubresource, const D3D11_BOX *pDstBox, 
		const void *pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
	{
		GetActivePtr()->UpdateSubresource(Unwrap(pDstResource), DstSubresource, pDstBox, 
										  pSrcData, SrcRowPitch, SrcDepthPitch);
	}

	void WrappedD3D11Context::CopyStructureCount(ID3D11Buffer *pDstBuffer, UINT DstAlignedByteOffset, 
												  ID3D11UnorderedAccessView *pSrcView)
	{
		GetActivePtr()->CopyStructureCount(
			Unwrap(pDstBuffer), DstAlignedByteOffset, Unwrap(pSrcView));
	}

	void WrappedD3D11Context::ClearRenderTargetView(ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4])
	{
		GetActivePtr()->ClearRenderTargetView(Unwrap(pRenderTargetView), ColorRGBA);
	}

	void WrappedD3D11Context::ClearUnorderedAccessViewUint(ID3D11UnorderedAccessView *pUnorderedAccessView, const UINT Values[4])
	{
		GetActivePtr()->ClearUnorderedAccessViewUint(Unwrap(pUnorderedAccessView), Values);
	}

	void WrappedD3D11Context::ClearUnorderedAccessViewFloat(ID3D11UnorderedAccessView *pUnorderedAccessView, const FLOAT Values[4])
	{
		GetActivePtr()->ClearUnorderedAccessViewFloat(Unwrap(pUnorderedAccessView), Values);
	}

	void WrappedD3D11Context::ClearDepthStencilView(ID3D11DepthStencilView *pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil)
	{
		GetActivePtr()->ClearDepthStencilView(Unwrap(pDepthStencilView), ClearFlags, Depth, Stencil);
	}

	void WrappedD3D11Context::GenerateMips(ID3D11ShaderResourceView *pShaderResourceView)
	{
		GetActivePtr()->GenerateMips(Unwrap(pShaderResourceView));
	}

	void WrappedD3D11Context::SetResourceMinLOD(ID3D11Resource *pResource, FLOAT MinLOD)
	{
		GetActivePtr()->SetResourceMinLOD(Unwrap(pResource), MinLOD);
	}

	FLOAT WrappedD3D11Context::GetResourceMinLOD(ID3D11Resource *pResource)
	{
		return GetActivePtr()->GetResourceMinLOD(Unwrap(pResource));
	}

	void WrappedD3D11Context::ResolveSubresource(
		ID3D11Resource *pDstResource, UINT DstSubresource, 
		ID3D11Resource *pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format)
	{
		GetActivePtr()->ResolveSubresource(Unwrap(pDstResource), DstSubresource, 
										   Unwrap(pSrcResource), SrcSubresource, Format);
	}

	void WrappedD3D11Context::ExecuteCommandList(ID3D11CommandList *pCommandList, 
												 BOOL RestoreContextState)
	{
		LogError("ExecuteCommandList is not suppported by now.");
	}


#pragma region GetShaderState
	void WrappedD3D11Context::VSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->VSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void WrappedD3D11Context::VSGetShader(ID3D11VertexShader **ppVertexShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->VSGetShader(ppVertexShader, NULL, pNumClassInstances);
		Wrap(ppVertexShader);
	}

	void WrappedD3D11Context::VSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->VSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void WrappedD3D11Context::VSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->VSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void WrappedD3D11Context::HSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->HSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void WrappedD3D11Context::HSGetShader(ID3D11HullShader **ppHullShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->HSGetShader(ppHullShader, NULL, pNumClassInstances);
		Wrap(ppHullShader);
	}

	void WrappedD3D11Context::HSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->HSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void WrappedD3D11Context::HSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->HSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void WrappedD3D11Context::DSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->DSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void WrappedD3D11Context::DSGetShader(ID3D11DomainShader **ppDomainShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->DSGetShader(ppDomainShader, NULL, pNumClassInstances);
		Wrap(ppDomainShader);
	}

	void WrappedD3D11Context::DSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->DSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void WrappedD3D11Context::DSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->DSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void WrappedD3D11Context::GSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->GSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void WrappedD3D11Context::GSGetShader(ID3D11GeometryShader **ppGeometryShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->GSGetShader(ppGeometryShader, NULL, pNumClassInstances);
		Wrap(ppGeometryShader);
	}

	void WrappedD3D11Context::GSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->GSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void WrappedD3D11Context::GSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->GSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void WrappedD3D11Context::PSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->PSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void WrappedD3D11Context::PSGetShader(ID3D11PixelShader **ppPixelShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->PSGetShader(ppPixelShader, NULL, pNumClassInstances);
		Wrap(ppPixelShader);
	}

	void WrappedD3D11Context::PSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->PSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}

	void WrappedD3D11Context::PSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, 
													ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->PSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void WrappedD3D11Context::CSGetShaderResources(UINT StartSlot, UINT NumViews, 
													ID3D11ShaderResourceView **ppShaderResourceViews)
	{
		GetActivePtr()->CSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
		Wrap(ppShaderResourceViews, NumViews);
	}

	void WrappedD3D11Context::CSGetUnorderedAccessViews(
		UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView **ppUnorderedAccessViews)
	{
		GetActivePtr()->CSGetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews);
		Wrap(ppUnorderedAccessViews, NumUAVs);
	}

	void WrappedD3D11Context::CSGetShader(ID3D11ComputeShader **ppComputeShader, 
										   ID3D11ClassInstance **ppClassInstances, 
										   UINT *pNumClassInstances)
	{
		GetActivePtr()->CSGetShader(ppComputeShader, NULL, pNumClassInstances);
		Wrap(ppComputeShader);
	}

	void WrappedD3D11Context::CSGetSamplers(UINT StartSlot, UINT NumSamplers, 
											 ID3D11SamplerState **ppSamplers)
	{
		GetActivePtr()->CSGetSamplers(StartSlot, NumSamplers, ppSamplers);
		Wrap(ppSamplers, NumSamplers);
	}
#pragma endregion GetShaderState


#pragma region GetPipelineState
	void WrappedD3D11Context::IAGetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY *pTopology)
	{
		GetActivePtr()->IAGetPrimitiveTopology(pTopology);
	}

	void WrappedD3D11Context::IAGetInputLayout(ID3D11InputLayout **ppInputLayout)
	{
		GetActivePtr()->IAGetInputLayout(ppInputLayout);
		Wrap(ppInputLayout);
	}

	void WrappedD3D11Context::IAGetVertexBuffers(
		UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppVertexBuffers, 
		UINT *pStrides, UINT *pOffsets)
	{
		GetActivePtr()->IAGetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
		Wrap(ppVertexBuffers, NumBuffers);
	}

	void WrappedD3D11Context::IAGetIndexBuffer(ID3D11Buffer **pIndexBuffer, 
												DXGI_FORMAT *Format, UINT *Offset)
	{
		GetActivePtr()->IAGetIndexBuffer(pIndexBuffer, Format, Offset);
		Wrap(pIndexBuffer);
	}

	void WrappedD3D11Context::SOGetTargets(UINT NumBuffers, ID3D11Buffer **ppSOTargets)
	{
		GetActivePtr()->SOGetTargets(NumBuffers, ppSOTargets);
		Wrap(ppSOTargets, NumBuffers);
	}

	void WrappedD3D11Context::RSGetState(ID3D11RasterizerState **ppRasterizerState)
	{
		GetActivePtr()->RSGetState(ppRasterizerState);
		Wrap(ppRasterizerState);
	}

	void WrappedD3D11Context::RSGetViewports(UINT *pNumViewports, D3D11_VIEWPORT *pViewports)
	{
		GetActivePtr()->RSGetViewports(pNumViewports, pViewports);
	}

	void WrappedD3D11Context::RSGetScissorRects(UINT *pNumRects, D3D11_RECT *pRects)
	{
		GetActivePtr()->RSGetScissorRects(pNumRects, pRects);
	}

	void WrappedD3D11Context::OMGetRenderTargets(
		UINT NumViews, ID3D11RenderTargetView **ppRenderTargetViews, 
		ID3D11DepthStencilView **ppDepthStencilView)
	{
		GetActivePtr()->OMGetRenderTargets(NumViews, ppRenderTargetViews, ppDepthStencilView);
		Wrap(ppRenderTargetViews, NumViews);
		Wrap(ppDepthStencilView);
	}

	void WrappedD3D11Context::OMGetRenderTargetsAndUnorderedAccessViews(
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

	void WrappedD3D11Context::OMGetBlendState(ID3D11BlendState **ppBlendState, FLOAT BlendFactor[4], UINT *pSampleMask)
	{
		GetActivePtr()->OMGetBlendState(ppBlendState, BlendFactor, pSampleMask);
		Wrap(ppBlendState);
	}

	void WrappedD3D11Context::OMGetDepthStencilState(ID3D11DepthStencilState **ppDepthStencilState, UINT *pStencilRef)
	{
		GetActivePtr()->OMGetDepthStencilState(ppDepthStencilState, pStencilRef);
		Wrap(ppDepthStencilState);
	}

	void WrappedD3D11Context::CSGetConstantBuffers(UINT StartSlot, UINT NumBuffers,
												   ID3D11Buffer **ppConstantBuffers)
	{
		GetActivePtr()->CSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
		Wrap(ppConstantBuffers, NumBuffers);
	}

	void WrappedD3D11Context::GetPredication(ID3D11Predicate **ppPredicate, BOOL *pPredicateValue)
	{
		GetActivePtr()->GetPredication(ppPredicate, pPredicateValue);
		Wrap(ppPredicate);
	}
#pragma endregion GetPipelineState


	void WrappedD3D11Context::ClearState()
	{
		GetActivePtr()->ClearState();
	}

	void WrappedD3D11Context::Flush()
	{
		GetActivePtr()->Flush();
	}

	D3D11_DEVICE_CONTEXT_TYPE WrappedD3D11Context::GetType()
	{
		return GetActivePtr()->GetType();
	}

	UINT WrappedD3D11Context::GetContextFlags()
	{
		return GetActivePtr()->GetContextFlags();
	}

	HRESULT WrappedD3D11Context::FinishCommandList(BOOL RestoreDeferredContextState, 
												   ID3D11CommandList **ppCommandList)
	{
		LogError("FinishCommandList is not supported by now");
		return E_FAIL;
	}

	void WrappedD3D11Context::SaveState(SDeviceContextState* pState)
	{
		// TODO_wzq ID3D11AsynchronousµÄ×´Ì¬ÎÞ·¨copy
		pState->GetFromContext(this, m_SOOffsets);
	}

	void WrappedD3D11Context::RestoreState(const SDeviceContextState* pState)
	{
		pState->SetToContext(this);
	}

	ID3D11DeviceChild* WrappedD3D11Context::CopyToDevice(ID3D11Device* pNewDevice)
	{
		if (GetReal()->GetType() == D3D11_DEVICE_CONTEXT_IMMEDIATE)
		{
			ID3D11DeviceContext* pNewImmediateContext = NULL;
			pNewDevice->GetImmediateContext(&pNewImmediateContext);
			return pNewImmediateContext;
		}
		else
		{
			LogError("Deferred context is not supported by now");
			return NULL;
		}
	}

}
