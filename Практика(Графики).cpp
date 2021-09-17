#include <Windows.h>
#include <iostream>
#include<stdio.h>
#include"GetColWind.h"
#include"Header.h"


//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;
HWND   hwnd;     //  Объявим дескриптор (описатель) окна
HDC    hdc;      // объявим  контекст устройства

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int Num;

	cout << "Введите цифру соответствующего графика\n";
	cout << "0)Синус\n1)Косинус\n2)Експонента\n3)Модуль\n\t";
	cin >> Num;

			Sinus Sin;
			Cosinus Cos;
			Exponenta Exp;
			Modul Mod;
//строим график в зависимости от выбранной цифры
			Function* func[4];
			func[0] = &Sin;
			func[1] = &Cos;
			func[2] = &Exp;
			func[3] = &Mod;
			
			if (Num == 0)
			Sin.DrawGraph(800, 600);
			
			if (Num == 1)
			Cos.DrawGraph(800, 600);
			
			if (Num == 2)
			Exp.DrawGraph(800, 600);

			if (Num == 3)
			Mod.DrawGraph(800, 600);

			

	return 0;
}