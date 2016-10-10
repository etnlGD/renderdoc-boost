#include "RenderdocBoost.h"
#include "WrappedDXGISwapChain.h"
#include "WrappedD3D11Device.h"
#include "WrappedD3D11Context.h"
#include "DeviceCreateParams.h"

namespace rdcboost
{
	HRESULT D3D11CreateDeviceAndSwapChain(
		IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, 
		UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, 
		UINT SDKVersion, const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc, 
		IDXGISwapChain** ppSwapChain, ID3D11Device** ppDevice, 
		D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext)
	{
		SDeviceCreateParams params(pAdapter, DriverType, Software, Flags, 
								   pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc);
		
		IDXGISwapChain* pRealSwapChain = NULL;
		ID3D11Device* pRealDevice = NULL;
		HRESULT res = ::D3D11CreateDeviceAndSwapChain(
							pAdapter, DriverType, Software, Flags, pFeatureLevels,
							FeatureLevels, SDKVersion, pSwapChainDesc, &pRealSwapChain,
							&pRealDevice, pFeatureLevel, NULL);

		WrappedD3D11Device* wrappedDevice = new WrappedD3D11Device(pRealDevice, params);
		WrappedDXGISwapChain* wrappedSwapChain = new WrappedDXGISwapChain(pRealSwapChain, wrappedDevice);
		wrappedDevice->InitSwapChain(wrappedSwapChain);
		pRealDevice->Release();
		pRealSwapChain->Release();

		*ppDevice = wrappedDevice;
		*ppSwapChain = wrappedSwapChain;
		wrappedDevice->GetImmediateContext(ppImmediateContext);

		return res;
	}

	void TriggerCapture(ID3D11Device* pDevice)
	{
		WrappedD3D11Device* pWrappedDevice = static_cast<WrappedD3D11Device*>(pDevice);
		const SDeviceCreateParams& params = pWrappedDevice->GetDeviceCreateParams();

		IDXGISwapChain* pRealSwapChain = NULL;
		ID3D11Device* pRealDevice = NULL;
		HRESULT res = ::D3D11CreateDeviceAndSwapChain(
						params.pAdapter, params.DriverType, params.Software,
						params.Flags, params.pFeatureLevels, params.FeatureLevels,
						params.SDKVersion, &params.SwapChainDesc, 
						&pRealSwapChain, &pRealDevice, NULL, NULL);

		pWrappedDevice->SwitchToDevice(pRealDevice, pRealSwapChain);
	}

}

