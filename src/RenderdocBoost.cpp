#include "RenderdocBoost.h"
#include "WrappedDXGISwapChain.h"
#include "WrappedD3D11Device.h"
#include "WrappedD3D11Context.h"
#include "DeviceCreateParams.h"
#include <set>

namespace rdcboost
{
	static bool rdcPresent = false;
	static RENDERDOC_API_1_0_1* rdcAPI = NULL;
	static bool InitRenderDoc()
	{
		printf("Loading renderdoc.dll ...\n");
		HMODULE rdcModule = LoadLibrary("renderdoc.dll");
		if (rdcModule == 0)
		{
			DWORD errorCode = GetLastError();
			LogError("Load renderdoc.dll failed(ERROR CODE: %d).", (int) errorCode);
			return false;
		}

		rdcPresent = true;
		pRENDERDOC_GetAPI pRenderDocGetAPIFn = (pRENDERDOC_GetAPI) GetProcAddress(rdcModule, "RENDERDOC_GetAPI");
		if (pRenderDocGetAPIFn == NULL)
		{
			LogError("Can't find RENDERDOC_GetAPI in renderdoc.dll.");
			return true;
		}

		if (pRenderDocGetAPIFn(eRENDERDOC_API_Version_1_0_1, (void**)&rdcAPI) == 0 ||
			rdcAPI == NULL)
		{
			LogError("Get API from renderdoc failed.");
			return true;
		}

		// TODO_wzq when to free?
// 		FreeLibrary(rdcModule);
		return true;
	}

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
		wrappedDevice->SetAsRenderDocDevice(rdcPresent);

		return res;
	}

	void EnableRenderDoc(ID3D11Device* pDevice)
	{
		if (!rdcPresent && !InitRenderDoc())
		{
			LogError("Can't enable renderdoc because renderdoc is not present.");
			return;
		}

		WrappedD3D11Device* pWrappedDevice = static_cast<WrappedD3D11Device*>(pDevice);
		if (pDevice == NULL || pWrappedDevice->IsRenderDocDevice())
			return;

		const SDeviceCreateParams& params = pWrappedDevice->GetDeviceCreateParams();

		IDXGISwapChain* pRealSwapChain = NULL;
		ID3D11Device* pRealDevice = NULL;
		HRESULT res = ::D3D11CreateDeviceAndSwapChain(
							params.pAdapter, params.DriverType, params.Software,
							params.Flags, params.pFeatureLevels, params.FeatureLevels,
							params.SDKVersion, &params.SwapChainDesc,
							&pRealSwapChain, &pRealDevice, NULL, NULL);

		if (FAILED(res))
		{
			LogError("Create RenderDoc device failed.");
			return;
		}

		pWrappedDevice->SwitchToDevice(pRealDevice, pRealSwapChain);
		pRealSwapChain->Release();
		pRealDevice->Release();
		pWrappedDevice->SetAsRenderDocDevice(true);
	}

	RENDERDOC_API_1_0_1* GetRenderdocAPI()
	{
		return rdcAPI;
	}

}

