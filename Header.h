#pragma once
class IFunction
{
public:
	IFunction();
	~IFunction();
	virtual double f(double x) = 0; //сама функция
	virtual void DrawGraph(double x0, double y0) = 0;//Функция отрисовки графика
	
};//IFunction

class Function : public IFunction
{
public:
	Function();
	~Function();
	virtual double f(double x); //сама функция
	void DrawGraph(double x0, double y0);
};//Function

class Sinus : public Function
{
public:
	Sinus();
	~Sinus();
	double f(double x);

};//Sinus

class Cosinus : public Function
{
public:
	Cosinus();
	~Cosinus();
	double f(double x);
};//Cosinus

class Exponenta : public Function
{
public:
	Exponenta();
	~Exponenta();
	double f(double x);
};//Exponent

class Modul : public Function
{
public:
	Modul();
	~Modul();
	double f(double x);
};//Modul