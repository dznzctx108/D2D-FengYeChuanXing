#pragma once
#include <Windows.h>

class Clock
{
public:
	Clock();
	~Clock();
	double GetTime();
	void Reset();

private:
	double sysFre;		// ��ʱ��Ƶ��
	double baseTime;	// ����ʱ��
};

