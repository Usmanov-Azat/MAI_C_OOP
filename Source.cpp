#include<iostream>
#include<windows.h>
#include "Header.h"
#include<string>
extern HDC hdc;      // объявим  контекст устройства

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
using namespace std;
/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА IFunction         */
/*----------------------------------------*/
//конструктор
IFunction::IFunction()
{
}//IFunction
//деструктор
IFunction::~IFunction(void)
{
}//~IFunction
/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА  Function         */
/*----------------------------------------*/
//конструктор
Function::Function()
{
}//Function
//деструктор
Function::~Function(void)
{
}//~Function

//вычисление координаты y для функции
double Function::f(double x)
{
	return x;
}//f(x)

//построение графиков
void Function::DrawGraph(double x0, double y0)
{
	int scale = 50;//Масштаб графика
	double CurrX;//текущие координаты
	double CurrY;
	string num;//переменная для вывода чисел на координатную ось

	HWND hW = GetConsoleWindow();
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN PenG = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//Для графика
	HPEN PenO = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));//Для осей
	
	SelectObject(hdc, PenO);
	//рисуем ось x 
	MoveToEx(hdc, x0 - 10 * scale, y0, NULL);
	LineTo(hdc, x0 + 10 * scale, y0);
	//рисуем ось Y
	MoveToEx(hdc, x0, y0 + 10 * scale, NULL);
	LineTo(hdc, x0, y0 - 10 * scale);
	
	//Рисуем черточки на графике

	//Для оси X
	for (int i = x0 - 10 * scale; i < x0 + 10 * scale; i += 1*scale)
	{
		MoveToEx(hdc, i, y0 + 2, NULL);
		LineTo(hdc, i, y0 + 2);
		num = to_string((i-800)/scale);
		TextOutA(hdc, i , y0 + 15, num.c_str(), num.length());
	}
	//Для оси Y
	for (int j = y0 - 10 * scale; j < y0 + 10 * scale; j += 1*scale)
	{
		MoveToEx(hdc, x0+2, j, NULL);
		LineTo(hdc, x0 + 2, j );
		num = to_string((j-600)/-scale);
		TextOutA(hdc, x0 - 15, j, num.c_str(), num.length());
	}


	//Рисуем график, начинаем с крайней левой точки графика
	CurrX = -10;//текущая координата Х
	CurrY = f(-10);//текущая координата У

	SelectObject(hdc, PenG);
	MoveToEx(hdc, x0 + CurrX * scale, y0 - CurrY * scale, NULL);

	//рисуем и остальные с шагом 0.01
	while (CurrX < 10)
	{
		CurrX += 0.01;
		CurrY = f(CurrX);
		LineTo(hdc, x0 + CurrX * scale, y0 - CurrY * scale);
	}
}//DrawGraph

//-------------------------------------синус(икс)----------------------
//пустой конструктор 
Sinus::Sinus() :Function()
{
};//Sinus

//деструктор
Sinus::~Sinus()
{
};//~Sinus
//сама функция (синус)
double Sinus::f(double x)
{
	return sin(x);
}//f(x)
//-------------------------------------косинус(икс)----------------------
//пустой конструктор 
Cosinus::Cosinus() :Function()
{

}; //Cosinus
//деструктор
Cosinus::~Cosinus()
{
};// ~Cosinus
//сама функция (косинус)
double Cosinus::f(double x)
{
	return cos(x);
}//f(x)
//-------------------------------------экспонента----------------------
//пустой конструктор 
Exponenta::Exponenta() :Function()
{
};//Exponent
//деструктор
Exponenta::~Exponenta()
{
};//~Exponent
//сама функция (экспонента)
double Exponenta::f(double x)
{
	return exp(x);
}//f(x)

//-------------------------------------модуль----------------------
//пустой конструктор 
Modul::Modul() :Function()
{
};// Modul
//деструктор
Modul ::~Modul()
{
};//~Modul
//сама функция (экспонента)
double Modul::f(double x)
{
	return fabs(x);
}//f(x)
