#include<iostream>
#include<windows.h>
#include "Header.h"
#include<string>
extern HDC hdc;      // �������  �������� ����������

//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
using namespace std;
/*----------------------------------------*/
/*        ������ ������ IFunction         */
/*----------------------------------------*/
//�����������
IFunction::IFunction()
{
}//IFunction
//����������
IFunction::~IFunction(void)
{
}//~IFunction
/*----------------------------------------*/
/*        ������ ������  Function         */
/*----------------------------------------*/
//�����������
Function::Function()
{
}//Function
//����������
Function::~Function(void)
{
}//~Function

//���������� ���������� y ��� �������
double Function::f(double x)
{
	return x;
}//f(x)

//���������� ��������
void Function::DrawGraph(double x0, double y0)
{
	int scale = 50;//������� �������
	double CurrX;//������� ����������
	double CurrY;
	string num;//���������� ��� ������ ����� �� ������������ ���

	HWND hW = GetConsoleWindow();
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN PenG = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));//��� �������
	HPEN PenO = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));//��� ����
	
	SelectObject(hdc, PenO);
	//������ ��� x 
	MoveToEx(hdc, x0 - 10 * scale, y0, NULL);
	LineTo(hdc, x0 + 10 * scale, y0);
	//������ ��� Y
	MoveToEx(hdc, x0, y0 + 10 * scale, NULL);
	LineTo(hdc, x0, y0 - 10 * scale);
	
	//������ �������� �� �������

	//��� ��� X
	for (int i = x0 - 10 * scale; i < x0 + 10 * scale; i += 1*scale)
	{
		MoveToEx(hdc, i, y0 + 2, NULL);
		LineTo(hdc, i, y0 + 2);
		num = to_string((i-800)/scale);
		TextOutA(hdc, i , y0 + 15, num.c_str(), num.length());
	}
	//��� ��� Y
	for (int j = y0 - 10 * scale; j < y0 + 10 * scale; j += 1*scale)
	{
		MoveToEx(hdc, x0+2, j, NULL);
		LineTo(hdc, x0 + 2, j );
		num = to_string((j-600)/-scale);
		TextOutA(hdc, x0 - 15, j, num.c_str(), num.length());
	}


	//������ ������, �������� � ������� ����� ����� �������
	CurrX = -10;//������� ���������� �
	CurrY = f(-10);//������� ���������� �

	SelectObject(hdc, PenG);
	MoveToEx(hdc, x0 + CurrX * scale, y0 - CurrY * scale, NULL);

	//������ � ��������� � ����� 0.01
	while (CurrX < 10)
	{
		CurrX += 0.01;
		CurrY = f(CurrX);
		LineTo(hdc, x0 + CurrX * scale, y0 - CurrY * scale);
	}
}//DrawGraph

//-------------------------------------�����(���)----------------------
//������ ����������� 
Sinus::Sinus() :Function()
{
};//Sinus

//����������
Sinus::~Sinus()
{
};//~Sinus
//���� ������� (�����)
double Sinus::f(double x)
{
	return sin(x);
}//f(x)
//-------------------------------------�������(���)----------------------
//������ ����������� 
Cosinus::Cosinus() :Function()
{

}; //Cosinus
//����������
Cosinus::~Cosinus()
{
};// ~Cosinus
//���� ������� (�������)
double Cosinus::f(double x)
{
	return cos(x);
}//f(x)
//-------------------------------------����������----------------------
//������ ����������� 
Exponenta::Exponenta() :Function()
{
};//Exponent
//����������
Exponenta::~Exponenta()
{
};//~Exponent
//���� ������� (����������)
double Exponenta::f(double x)
{
	return exp(x);
}//f(x)

//-------------------------------------������----------------------
//������ ����������� 
Modul::Modul() :Function()
{
};// Modul
//����������
Modul ::~Modul()
{
};//~Modul
//���� ������� (����������)
double Modul::f(double x)
{
	return fabs(x);
}//f(x)
