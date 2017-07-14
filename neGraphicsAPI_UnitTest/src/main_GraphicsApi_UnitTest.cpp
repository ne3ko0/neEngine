//--------------------------------------------------------------------------------------
// File: Tutorial01.cpp
//
// This application demonstrates creating a Direct3D 11 device
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>

#include <neMathVector4.h>
#include <neGraphicsPrerequisites.h>
#include <neGraphicsDevice.h>
#include <neGraphicsDeviceContext.h>
#include <neGraphicsRenderTargetView.h>
#include <neGraphicsSwapChain.h>

using namespace neEngineSDK;

//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
HINSTANCE               g_hInst = NULL;
HWND                    g_hWnd = NULL;
D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
CGraphicsDevice         m_Device;
CGraphicsDeviceContext  m_DeviceContext;
IDXGISwapChain*         g_pSwapChain = NULL;
CSwapChain              m_SwapChain;
CRenderTargetView       m_pRenderTargetView;
ID3D11VertexShader*     g_pVertexShader = NULL;
ID3D11PixelShader*      g_pPixelShader = NULL;


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
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
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
  g_hWnd = CreateWindow("TutorialWindowClass", "Direct3D 11 Tutorial 1: Direct3D 11 Basics", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
    NULL);
  if (!g_hWnd)
    return E_FAIL;

  ShowWindow(g_hWnd, nCmdShow);

  return S_OK;
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

  ID3D11Device** pDevice = reinterpret_cast<ID3D11Device**>(m_Device.getReference());
  ID3D11DeviceContext** pDeviceContext = reinterpret_cast<ID3D11DeviceContext**>
                        (m_DeviceContext.getReference());
  ID3D11RenderTargetView** pRenderTargetView = reinterpret_cast<ID3D11RenderTargetView**>
                        (m_pRenderTargetView.getReference());
  IDXGISwapChain* pSwapChain = reinterpret_cast<IDXGISwapChain*>
                        (m_SwapChain.getReference());

  for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
  {
    g_driverType = driverTypes[driverTypeIndex];
    hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
      D3D11_SDK_VERSION, &sd, &g_pSwapChain, pDevice, &g_featureLevel, pDeviceContext);
    if (SUCCEEDED(hr))
      break;
  }
  if (FAILED(hr))
    return hr;

  // Create a render target view
  ID3D11Texture2D* pBackBuffer = NULL;
  hr = g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
  if (FAILED(hr))
    return hr;

  hr = (*pDevice)->CreateRenderTargetView(pBackBuffer, NULL, pRenderTargetView);
  pBackBuffer->Release();
  if (FAILED(hr))
    return hr;

  (*pDeviceContext)->OMSetRenderTargets(1, pRenderTargetView, NULL);

  // Setup the viewport
  D3D11_VIEWPORT vp;
  vp.Width = (FLOAT)width;
  vp.Height = (FLOAT)height;
  vp.MinDepth = 0.0f;
  vp.MaxDepth = 1.0f;
  vp.TopLeftX = 0;
  vp.TopLeftY = 0;
  (*pDeviceContext)->RSSetViewports(1, &vp);

  return S_OK;
}

void SetInfoToRender()
{
  //ID3DBlob* MyShaderCompileInfoCode ;

  //ID3D11InputLayout* ILayOut;

  //D3D11_INPUT_ELEMENT_DESC layout[] =
  //{
  //  { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
  //};


  ////To Do: compilar shader
  //ID3DBlob* pErrorBlob;
  //HRESULT hr;
  //  hr =  D3DCompileFromFile("C:\Motorsisimo\NekoEngine2\bin\Resourse\Shaders", NULL, NULL, "VS", "VS_M_5.0",
  //  D3DCOMPILE_DEBUG, 0, MyShaderCompileInfoCode, &pErrorBlob);
    //(*pDevice)->CreateInputLayout(layout, 0, MyShaderCompileInfoCode->GetBufferPointer(), MyShaderCompileInfoCode->GetBufferSize(), &ILayOut);


  ID3D11Buffer* pVertexB;
  ID3D11Buffer* pIndexB;

  //Create VertexBuffer

  struct Vertex
  {
    neEngineSDK::CVector4 m_Pos;
  };

  Vertex VerToRender[3]
  {
    CVector4(0.0f, 0.5f, 0.5f, 0.f),
    CVector4(0.5f, -0.5f,   0.5f, 0.f),
    CVector4(-0.5f, -0.5f,  0.5f, 0.f)
  };


  D3D11_BUFFER_DESC DesVerBuffer;
  DesVerBuffer.BindFlags = D3D11_BIND_VERTEX_BUFFER;
  DesVerBuffer.ByteWidth = sizeof(Vertex) * 3; //Tamaño quw tendrá el buffer  
  DesVerBuffer.CPUAccessFlags = 0;
  DesVerBuffer.MiscFlags = 0;
  DesVerBuffer.Usage = D3D11_USAGE_DEFAULT;

  D3D11_SUBRESOURCE_DATA InitData;
  ZeroMemory(&InitData, sizeof(InitData));
  InitData.pSysMem = VerToRender;
  ID3D11Device** pDevice = reinterpret_cast<ID3D11Device**>(m_Device.getReference());
  (*pDevice)->CreateBuffer(&DesVerBuffer, &InitData, &pVertexB);


  //Reate Index Buffer
  struct INDEX
  {
    float m_Pos;

  };

  INDEX IndexToRender[3]
  {
    float(1.0f),
    float(2.0f),
    float(3.0f)
  };

  
  D3D11_BUFFER_DESC DesIndBuffer;
  DesIndBuffer.BindFlags = D3D11_BIND_INDEX_BUFFER;
  DesIndBuffer.ByteWidth = sizeof(INDEX) * 3; //Tamaño quw tendrá el buffer
  DesIndBuffer.CPUAccessFlags = 0;
  DesIndBuffer.MiscFlags = 0;
  DesIndBuffer.Usage = D3D11_USAGE_DEFAULT;

  //D3D11_SUBRESOURCE_DATA InitData;
  //ZeroMemory(&InitData, sizeof(InitData));
  //InitData.pSysMem = IndexToRender;

  (*pDevice)->CreateBuffer(&DesIndBuffer, &InitData, &pIndexB);

  

  UINT  stride = sizeof(Vertex);
  ID3D11DeviceContext** pDeviceContext = reinterpret_cast<ID3D11DeviceContext**>
    (m_DeviceContext.getReference());
  (*pDeviceContext)->IASetVertexBuffers(0, 1, &pVertexB, &stride, 0);


  (*pDeviceContext)->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

}
//--------------------------------------------------------------------------------------
// Render the frame
//--------------------------------------------------------------------------------------
void Render()
{
  ID3D11DeviceContext* pDeviceContext = reinterpret_cast<ID3D11DeviceContext*>
                                        (m_DeviceContext.getObject());
  ID3D11RenderTargetView** pRenderTargetView = reinterpret_cast<ID3D11RenderTargetView**>
                                               (m_pRenderTargetView.getReference());
  IDXGISwapChain* pSwapChain = reinterpret_cast<IDXGISwapChain*>
                                (m_SwapChain.getReference());

  // Just clear the backbuffer
  float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; //red,green,blue,alpha
  pDeviceContext->ClearRenderTargetView(*pRenderTargetView, ClearColor);
  g_pSwapChain->Present(0, 0);

  // Render a triangle
  pDeviceContext->VSSetShader(g_pVertexShader, NULL, 0);
  pDeviceContext->PSSetShader(g_pPixelShader, NULL, 0);
  pDeviceContext->Draw(3, 0);
}


//--------------------------------------------------------------------------------------
// Clean up the objects we've created
//--------------------------------------------------------------------------------------
void CleanupDevice()
{
  m_pRenderTargetView.destroy();
  m_SwapChain.destroy();
  m_DeviceContext.destroy();
  m_Device.destroy();
}
