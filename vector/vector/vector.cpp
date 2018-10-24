#include "vector.h"
#include<cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
namespace VECTOR {
	const double Rag_to_deg = 45.0 / atan(1.0);
	void Vector::set_mag() 
	{
		mag = sqrt(x*x + y * y);
	}
	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		ang = atan2(y, x);
	}
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	
	Vector::Vector()
	{
		x = y = mag = ang = 0;
		mode = RECT;//类内定义可以不加限定名Vector
	}
	Vector::Vector(double n1, double n2, Mode form)//定义时不能声明默认函数
	{
		mode = form;
		if (mode == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if(mode==POL)
		{
			ang = n1;
			mag = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;//使用了状态成员
		if (mode == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (mode == POL)
		{
			ang = n1;
			mag = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			mode = RECT;
		}
	}
	Vector::~Vector()
	{
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator +(const Vector &b) const
	{
		return Vector(x + b.x, y + b.y);//创建无名对象，并返回该对象
	}
	Vector Vector::operator -(const Vector &b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator -() const//对已经重载过的运算符再次重载
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator *(double n) const
	{
		return Vector(n*x, n*y);
	}
	//friend
	Vector operator*(double n, const Vector &b)
	{
		return n * b;
	}
	std::ostream& operator<<(std::ostream & os, const Vector &b)
	{
		if (b.mode == Vector::RECT)//友元函数为类外定义，类内的枚举必须指定限定名
		{
			os << "(x,y)=" << "(" << b.x << ',' << b.y << ")" << std::endl;
		}
		else if (b.mode == Vector::POL)
		{
			os << "mag=" << b.mag << ' ' << "ang=" << b.ang << std::endl;
		}
		else
			os << "wrong object mode" << std::endl;
		return os;
	}
}