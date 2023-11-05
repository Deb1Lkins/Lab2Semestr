#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
using std::cout;
using std::cin;
using std::vector;
using std::function;
void CheckBorders(double& min, double& max)
{
	if (min > max)
	{
		std::swap(min, max);
	}
}
void CheckChoice(const int& choice)
{
	if (choice <= 0 || choice > 5)
	{
		throw"неверное значение";
	}
}
void CheckFoo(const int& foo)
{
	if (foo <= 0 || foo > 3)
	{
		throw"неверное значение";
	}
}
double functional1(const double& x)
{
	return sqrt(pow(2, x) - 1); // 0.3 - 1
}
double functional2(const double& x)
{
	return (x * x - 1) * pow(10, -2 * x); //0 - 0.4
}
double functional3(const double& x)
{
	return tan(x/2 + M_PI/4) * tan(x/2 + M_PI/4) * tan(x/2 + M_PI/4); //0 - pi/4(0.785)
}
double LeftRectangle(const int& n, double& step, double x, vector<function<double(const double&)>>& func_vector, const int& foo)
{
	double sum = 0;
	for (size_t i = 0; i <= n; i++)
	{
		x += step; 
		sum += func_vector[foo](x) * step;
	}
	return sum;
}
double RightRectangle(const int& n, double& step, double x, vector<function<double(const double&)>>& func_vector, const int& foo)
{
	double sum = 0;
	x += step;
	for (size_t i = 0; i <= n; i++)
	{
		x += step;
		sum += func_vector[foo](x) * step;
	}
	return sum;
}
double MidRectangle(const int& n, double& step, double x, vector<function<double(const double&)>>& func_vector, const int& foo)
{
	double sum = 0;
	x += step / 2;
	for (size_t i = 0; i <= n; i++)
	{
		x += step;
		sum += func_vector[foo](x) * step;
	}
	return sum;
}
double Trapezoid(const int& n, double& step, double x, vector<function<double(const double&)>>& func_vector, const int& foo)
{
	double sum = 0, x2;
	x += step / 2;
	for (size_t i = 0; i <= n; i++)
	{
		x += step;
		x2 = x + step;
		sum += (func_vector[foo](x) + func_vector[foo](x2)) / 2 * step;
	}
	return sum;
}
double SimpsonInt(const int& n, double& step, double x, vector<function<double(const double&)>>& func_vector, const int& foo)
{
	double sum = 0;
	double x1, x2, x3;
	x += step / 2;
	for (size_t i = 0; i < n; i += 2)
	{
		x1 = x + step * i;
		double x2 = x + step * (i + 1);
		double x3 = 0.5 * (x1 + x2);
		sum += (x2 - x1) / 3.0 * (func_vector[foo](x1) + 4 * func_vector[foo](x3) + func_vector[foo](x2));

	}
	return sum;
}
double Form(double& min, const double& max, double& eps, int& n, vector<function<double(const int&, double&, double, vector<function<double(const double&)>>&, const int&)>> formule_vc, const int& choice)
{
	vector<function<double(const double&)>> func_vector;
	func_vector.emplace_back(functional1);
	func_vector.emplace_back(functional2);
	func_vector.emplace_back(functional3);
	int foo;
	cout << "введите формулу:\n"
		<< "1) sqrt(pow(2, x) - 1);\n"
		<< "2) (x * x - 1) * pow(10, -2 * x);\n"
		<< "3) tan(x/2 + 3.14/4)* tan(x / 2 + 3.14 / 4)* tan(x / 2 + 3.14 / 4); - ";
	cin >> foo;
	CheckFoo(foo);
	foo--;
	double s1 = 1, s2 = 0;
	double step = (max - min) / n;
	while (abs(s1 - s2) >= eps)
	{
		s1 = s2;
		s2 = formule_vc[choice](n, step, min, func_vector, foo);
		n *= 2;
		step = (max - min) / n;

	}
	return s2;
}
int main()
{
	try
	{
		setlocale(LC_ALL,"ru");
		int n = 4; //начальное количество разбиений
		double result;
		double min, max;
		cout << "введите левую границу - ";
		cin >> min;
		cout << "введите правую границу - ";
		cin >> max;
		CheckBorders(min, max);
		double eps;
		cout << "введите точность - ";
		cin >> eps;
		int choice;
		cout <<"введите метод:\n"
			 <<"1) левых прямоугольников;\n"
			 <<"2) правых прямоугольников;\n"
			 <<"3) средних прямоугольников;\n"
			 <<"4) трапеций;\n"
			 <<"5) Симпсона(параболических трапеций). - ";
		cin >> choice;
		CheckChoice(choice);
		choice--;
		vector<function<double(const int&, double&, double, vector<function<double(const double&)>>&, const int&)>> formule_vc;
		formule_vc.emplace_back(LeftRectangle);
		formule_vc.emplace_back(RightRectangle);
		formule_vc.emplace_back(MidRectangle);
		formule_vc.emplace_back(Trapezoid);
		formule_vc.emplace_back(SimpsonInt);
		result = Form(min, max, eps, n, formule_vc, choice);
		cout.precision(10);
		cout << std::fixed << "\nсвои вычисления = " << result;
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	return 0;
}