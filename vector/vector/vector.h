#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
namespace VECTOR {
	class Vector {
	public:
		enum Mode {RECT,POL};//枚举定义状态成员
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;
	
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);//默认参数为RECT
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();
		//operator override
		Vector operator +(const Vector &b) const;
		Vector operator -(const Vector &b) const;
		Vector operator -() const;
		Vector operator *(double n) const;

		//friend
		friend Vector operator*(double n, const Vector &b);
		friend std::ostream& operator<<(std::ostream & os, const Vector &b);
	};
}
#endif
