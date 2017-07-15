#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

#include <neString.h>

#include <neMathVector4.h>
#include <neGraphicsAPI.h>
#include <neGraphicsBuffer.h>
#include <neModule.h>

using namespace neEngineSDK;
//--------------------------------------------------------------------------------------
// Structures
//--------------------------------------------------------------------------------------
struct Vertex
{
  CVector4 m_Pos;
};


//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
HINSTANCE               g_hInst = NULL;
HWND                    g_hWnd = NULL;
D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;

CVertexBuffer<NEVERTEX> m_VertexBuffer;

ID3D11VertexShader*     g_pVertexShader = NULL;
ID3D11PixelShader*      g_pPixelShader = NULL;
ID3D11InputLayout*      g_pVertexLayout = NULL;
ID3D11Buffer*           g_pVertexBuffer = NULL;

//--------------------------------------------------------------------------------------
// Forward declarations
//--------------------------------------------------------------------------------------
HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow);
HRESULT InitDevice();
void CleanupDevice();
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void Render();


//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);

  if (FAILED(InitWindow(hInstance, nCmdShow)))
    return 0;

  if (FAILED(InitDevice()))
  {
    CleanupDevice();
    return 0;
  }

  // Main message loop
  MSG msg = { 0 };
  while (WM_QUIT != msg.message)
  {
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    else
    {
      Render();
    }
  }

  CleanupDevice();

  return (int)msg.wParam;
}


//--------------------------------------------------------------------------------------
// Register class and create window
//--------------------------------------------------------------------------------------
HRESULT InitWindow(HINSTANCE hInstance, int nCmdShow)
{
  // Register class
  WNDCLASSEX wcex;
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = 0;
  wcex.hCursor = 0;
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = NULL;
  wcex.lpszClassName = "TutorialWindowClass";
  wcex.hIconSm = 0;
  if (!RegisterClassEx(&wcex))
    return E_FAIL;

  // Create window
  g_hInst = hInstance;
  RECT rc = { 0, 0, 640, 480 };
  AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
  g_hWnd = CreateWindow("TutorialWindowClass", "Triangle",
    WS_OVERLAPPEDWINDOW,
    0, 0, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
    NULL);
  if (!g_hWnd)
    return E_FAIL;

  ShowWindow(g_hWnd, nCmdShow);

  return S_OK;
}


//--------------------------------------------------------------------------------------
// Helper for compiling shaders with D3DX11
//--------------------------------------------------------------------------------------
HRESULT CompileShaderFromFile(String szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
  HRESULT hr = S_OK;

  DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
  // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
  // Setting this flag improves the shader debugging experience, but still allows 
  // the shaders to be optimized and to run exactly the way they will run in 
  // the release configuration of this program.
  dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

  ID3DBlob* pErrorBlob;
  hr = D3DX11CompileFromFileA(szFileName.c_str(), NULL, NULL, szEntryPoint, szShaderModel,
    dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL);
  if (FAILED(hr))
  {
    if (pErrorBlob != NULL)
      OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
    if (pErrorBlob) pErrorBlob->Release();
    return hr;
  }
  if (pErrorBlob) pErrorBlob->Release();

  return S_OK;
}


//--------------------------------------------------------------------------------------
// Create Direct3D device and swap chain
//--------------------------------------------------------------------------------------
HRESULT InitDevice()
{
  HRESULT hr = S_OK;

  RECT rc;
  GetClientRect(g_hWnd, &rc);
  UINT width = rc.right - rc.left;
  UINT height = rc.bottom - rc.top;

  UINT createDeviceFlags = 0;
#ifdef _DEBUG
  createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

  D3D_DRIVER_TYPE driverTypes[] =
  {
    D3D_DRIVER_TYPE_HARDWARE,
    D3D_DRIVER_TYPE_WARP,
    D3D_DRIVER_TYPE_REFERENCE,
  };
  UINT numDriverTypes = ARRAYSIZE(driverTypes);

  D3D_FEATURE_LEVEL featureLevels[] =
  {
    D3D_FEATURE_LEVEL_11_0,
    D3D_FEATURE_LEVEL_10_1,
    D3D_FEATURE_LEVEL_10_0,
  };
  UINT numFeatureLevels = ARRAYSIZE(featureLevels);

  DXGI_SWAP_CHAIN_DESC sd;
  ZeroMemory(&sd, sizeof(sd));
  sd.BufferCount = 1;
  sd.BufferDesc.Width = width;
  sd.BufferDesc.Height = height;
  sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  sd.BufferDesc.RefreshRate.Numerator = 60;
  sd.BufferDesc.RefreshRate.Denominator = 1;
  sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  sd.OutputWindow = g_hWnd;
  sd.SampleDesc.Count = 1;
  sd.SampleDesc.Quality = 0;
  sd.Windowed = TRUE;

  g_GraphicsAPI().startUp();

  ID3D11Device** pRefDevice = reinterpret_cast<ID3D11Device**>(g_GraphicsAPI().m_Device.getReference());
  ID3D11DeviceContext** pRefDeviceContext = reinterpret_cast<ID3D11DeviceContext**>(g_GraphicsAPI().m_DeviceContext.getReference());
  IDXGISwapChain** pRefSwapChain = reinterpret_cast<IDXGISwapChain**>(g_GraphicsAPI().m_SwapChain.getReference());
  
  for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
  {


    g_driverType = driverTypes[driverTypeIndex];
    hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
      D3D11_SDK_VERSION, &sd, pRefSwapChain, pRefDevice, &g_featureLevel, pRefDeviceContext);
    if (SUCCEEDED(hr))
      break;
  }
  if (FAILED(hr))
    return hr;

  ID3D11Device* pDevice = *pRefDevice;
  ID3D11DeviceContext* pDeviceContext = *pRefDeviceContext;
  IDXGISwapChain* pSwapChain = *pRefSwapChain;

  // Create a render target view
  ID3D11Texture2D* pBackBuffer = NULL;
  hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
  if (FAILED(hr))
    return hr;

  ID3D11RenderTargetView** pRefRenderTargetView = reinterpret_cast<ID3D11RenderTargetView**>(g_GraphicsAPI().m_pRenderTargetView.getReference());

  hr = pDevice->CreateRenderTargetView(pBackBuffer, NULL, pRefRenderTargetView);
  pBackBuffer->Release();
  if (FAILED(hr))
    return hr;

  ID3D11RenderTargetView* pRenderTargetView = *pRefRenderTargetView;
  pDeviceContext->OMSetRenderTargets(1, &pRenderTargetView, NULL);

  // Setup the viewport
  D3D11_VIEWPORT vp;
  vp.Width = (FLOAT)width;
  vp.Height = (FLOAT)height;
  vp.MinDepth = 0.0f;
  vp.MaxDepth = 1.0f;
  vp.TopLeftX = 0;
  vp.TopLeftY = 0;
  pDeviceContext->RSSetViewports(1, &vp);

  // Compile the vertex shader
  ID3DBlob* pVSBlob = NULL;
  hr = CompileShaderFromFile("resource/shader.hlsl", "VS", "vs_4_0", &pVSBlob);
  if (FAILED(hr))
  {
    MessageBox(NULL,
      "The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", "Error", MB_OK);
    return hr;
  }

  // Create the vertex shader
  hr = pDevice->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), NULL, &g_pVertexShader);
  if (FAILED(hr))
  {
    pVSBlob->Release();
    return hr;
  }

  // Define the input layout
  D3D11_INPUT_ELEMENT_DESC layout[] =
  {
    { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
  };
  UINT numElements = ARRAYSIZE(layout);

  // Create the input layout
  hr = pDevice->CreateInputLayout(layout, numElements, pVSBlob->GetBufferPointer(),
    pVSBlob->GetBufferSize(), &g_pVertexLayout);
  pVSBlob->Release();
  if (FAILED(hr))
    return hr;

  // Set the input layout
  pDeviceContext->IASetInputLayout(g_pVertexLayout);

  // Compile the pixel shader
  ID3DBlob* pPSBlob = NULL;
  hr = CompileShaderFromFile("resource/shader.hlsl", "PS", "ps_4_0", &pPSBlob);
  if (FAILED(hr))
  {
    MessageBox(NULL,
      "The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", "Error", MB_OK);
    return hr;
  }

  // Create the pixel shader
  hr = pDevice->CreatePixelShader(pPSBlob->GetBufferPointer(), pPSBlob->GetBufferSize(), NULL, &g_pPixelShader);
  pPSBlob->Release();
  if (FAILED(hr))
    return hr;

  // Create vertex buffer
  NEVERTEX VerToRender[3]
  {
    CVector4(0.0f, 0.5f, 0.5f, 0.f),
    CVector4(0.5f, -0.5f,   0.5f, 0.f),
    CVector4(-0.5f, -0.5f,  0.5f, 0.f)
  };

  m_VertexBuffer.Add(VerToRender, 3);
  m_VertexBuffer.CreateHardwareBuffer();
  m_VertexBuffer.SetHardwareBuffer();

  // Set primitive topology
  pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

  return S_OK;
}


//--------------------------------------------------------------------------------------
// Clean up the objects we've created
//--------------------------------------------------------------------------------------
void CleanupDevice()
{
  if (g_pVertexBuffer) g_pVertexBuffer->Release();
  if (g_pVertexLayout) g_pVertexLayout->Release();
  if (g_pVertexShader) g_pVertexShader->Release();
  if (g_pPixelShader) g_pPixelShader->Release();
}


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  HDC hdc;

  switch (message)
  {
  case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);
    EndPaint(hWnd, &ps);
    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
  }

  return 0;
}


//--------------------------------------------------------------------------------------
// Render a frame
//--------------------------------------------------------------------------------------
void Render()
{
  // Clear the back buffer 
  float ClearColor[4] = { 2.0f, 0.125f, 0.3f, 1.0f }; // red,green,blue,alpha
  ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>(g_GraphicsAPI().m_DeviceContext.getObject());
  ID3D11RenderTargetView* pRenderTargetView = reinterpret_cast<ID3D11RenderTargetView*>(g_GraphicsAPI().m_pRenderTargetView.getObject());
  IDXGISwapChain* pSwapChain = reinterpret_cast<IDXGISwapChain*>(g_GraphicsAPI().m_SwapChain.getObject());

  pDeviceContext->ClearRenderTargetView(pRenderTargetView, ClearColor);

  // Render a triangle
  pDeviceContext->VSSetShader(g_pVertexShader, NULL, 0);
  pDeviceContext->PSSetShader(g_pPixelShader, NULL, 0);
  pDeviceContext->Draw(3, 0);

  // Present the information rendered to the back buffer to the front buffer (the screen)
  pSwapChain->Present(0, 0);
}
