#include "Resource.h"

shu::Resource* shu::Resource::ptr = nullptr;

shu::Resource::Resource(shu::Direct2dRender& rt)
	: m_rt(rt)
{
	ptr = this;
}

shu::Resource::~Resource()
{
	std::cout << "��Դ�ͷ�...\n";
	m_Bitmaps.clear();
	m_Jsons.clear();
}

ID2D1Bitmap1* shu::Resource::GetBitmap(std::wstring file)
{
	auto it = ptr->m_Bitmaps.find(file);

	if (it == ptr->m_Bitmaps.end())
	{
		// û�ҵ�������
		ptr->m_Bitmaps[file] = ComPtr<ID2D1Bitmap1>();
		ptr->m_rt.LoadBitmapFromFile(file, &ptr->m_Bitmaps[file]);
		if (ptr->m_Bitmaps[file].Get() == nullptr) std::wcout << L"��Դ����ʧ�ܣ�" << file << std::endl;
		return ptr->m_Bitmaps[file].Get();
	}
	else
	{
		// �ҵ���
		return it->second.Get();
	}

	return nullptr;
}

Json::Value* shu::Resource::GetJson(std::wstring file)
{
	auto it = ptr->m_Jsons.find(file);

	if (it == ptr->m_Jsons.end())
	{
		// û�ҵ�������
		ptr->m_Jsons.insert(std::make_pair( file, std::make_unique<Json::Value>() ));
		
		char buf[256] = { 0 };
		std::ifstream in;
		in.open(file);
		if (in.fail()) return nullptr;
		Json::CharReaderBuilder ReaderBuilder;
		ReaderBuilder["emitUTF8"] = true;
		std::string strerr;
		bool ok = Json::parseFromStream(ReaderBuilder, in, ptr->m_Jsons[file].get(), &strerr);
		if (!ok) { std::wcout << L"��Դ����ʧ�ܣ�" << file << std::endl; return nullptr; }
		in.close();

		return ptr->m_Jsons[file].get();
	}
	else
	{
		// �ҵ���
		return it->second.get();
	}

	return nullptr;
}

void shu::Resource::ReleaseBitmap(const std::wstring& file)
{
	auto it = ptr->m_Bitmaps.find(file);
	if (it != ptr->m_Bitmaps.end())
	{
		ptr->m_Bitmaps.erase(it);
	}
}
