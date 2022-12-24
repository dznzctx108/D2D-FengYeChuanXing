#pragma once
#include <wrl/client.h>
#include <dwrite.h>
#include <dxgi1_2.h>
#include <d2d1.h>
#include <d2d1_1.h>
#include <d3d11.h>
#include <dxgi1_2.h>
#include <d2d1_1helper.h>
#include <wincodec.h>
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <mutex>

#include "LogSys.h"
#include "Vec.h"

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "D3D11.lib")
#pragma comment(lib, "Dwrite.lib")
#pragma comment(lib, "Winmm.lib")

namespace shu
{
	using namespace Microsoft::WRL;

	class Direct2dRender
	{
	public:
		Direct2dRender() : m_hwnd(nullptr) {  }
		~Direct2dRender() {}

		bool Init(HWND hwnd);

		// ������һЩ��װ�Ļ�ͼ��������Direct2d�Ļ�ͼ����̫�࣬���Ծ��õ��ķ�װ���İɣ���Ҳ����
		// ���� Direct2dRender::GetDC ������ȡԭʼ���豸������ ID2D1DeviceContext
		void BeginDraw();

		void Clear(const color4f& color);

		void FillRoundedRect(const vec2f& pos, const vec2f& size, float radius, const color4f& color);

		void DrawRect(const vec2f& pos, const vec2f& size, const color4f& color, float strokeWidth = 1.0f);
		void FillRect(const vec2f& pos, const vec2f& size, ID2D1Brush* brush);

		void FillCircle(const vec2f& pos, float radius, const color4f& color);
		void FillCircle(const vec2f& pos, float radius, ID2D1Brush* brush);

		void DrawLine(const vec2f& p1, const vec2f& p2, const color4f& color, float strokeWidth = 1.0f);

		void DrawTextCenter(const std::wstring& text, const vec2f& pos, const vec2f& rect, const color4f& color, float Textsize);
		void DrawText(const std::wstring& text, const vec2f& pos, const vec2f& rect, const color4f& color, float Textsize);

		void DrawBitmap(ID2D1Bitmap1* bitmap, const vec2f& pos, const vec2f& size);

		void EndDraw();

		// ������һЩ�����ຯ������
		bool LoadBitmapFromFile(std::wstring file, ID2D1Bitmap1** Bitmap);

		void ChangeSize(uint32_t width, uint32_t height);

		// ����һЩGet����
		ID2D1DeviceContext& GetDC();		// ��ȡD2d�豸������
		vec2f& GetSize();					// ��ȡ������ȾĿ��Ĵ�С
		ID2D1Bitmap1* GetRenderTarget();	// ��ȡĬ�ϵ���ȾĿ��

	private:
		bool createRenderTarget();
		bool createDwrite();
		bool createWic();

	private:

		HWND m_hwnd;
		vec2f m_size;

		ComPtr<ID2D1SolidColorBrush> m_Brush;

		ComPtr<ID2D1Factory1> m_d2dFactory;
		ComPtr<ID2D1Device> m_d2dDevice;
		ComPtr<ID2D1DeviceContext> m_d2dDeviceContext;
		ComPtr<ID2D1Bitmap1> m_d2dTarget;

		ComPtr<ID3D11Device> m_d3dDevice;
		ComPtr<ID3D11DeviceContext> m_d3dDeviceContext;
		ComPtr<ID3D11RenderTargetView> m_d3dRenderTar;

		ComPtr<IDXGIFactory2> m_dxgiFactory;
		ComPtr<IDXGIDevice1> m_dxgiDevice;
		ComPtr<IDXGISwapChain1> m_dxgiSwapChain;
		ComPtr<IDXGISurface1> m_dxgiSurface;

		ComPtr<IDWriteFactory> m_pDWriteFactory;
		ComPtr<IDWriteTextFormat> m_pTextFormat;
		ComPtr<IDWriteTextLayout> m_pTextLayout;

		ComPtr<IWICImagingFactory> m_wicImgFactory;
	};


}