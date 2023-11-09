#include <iostream>
#include <cmath>


struct my_complex_t
{
	double x, y;
	my_complex_t(){}
	my_complex_t (const double& val) : x{val}, y{0.0} {}
	my_complex_t (const double& xx, const double& yy) : x{xx}, y{yy} {}
	
	my_complex_t operator + (const my_complex_t& rhs) const
	{
		return my_complex_t(x + rhs.x, y + rhs.y);
	}
	
	my_complex_t operator - (const my_complex_t& rhs) const
	{
		return my_complex_t(x - rhs.x, y - rhs.y);
	}
	
	my_complex_t operator * (const my_complex_t& rhs) const
	{
		return my_complex_t(x*rhs.x - y*rhs.y, x*rhs.y + y*rhs.x);
	}
	
	my_complex_t operator / (const my_complex_t& rhs) const
	{
		const auto denom = rhs.x*rhs.x + rhs.y*rhs.y;
		return my_complex_t ((x*rhs.x + y*rhs.y) / denom, (y*rhs.x - x*rhs.y) / denom);
	}
};

my_complex_t operator + (const double& dval, const my_complex_t& rhs)
{
	return my_complex_t(dval) + rhs;
}

my_complex_t operator - (const double& dval, const my_complex_t& rhs)
{
	return my_complex_t(dval) - rhs;
}

my_complex_t operator * (const double& dval, const my_complex_t& rhs)
{
	return my_complex_t(dval) * rhs;
}

my_complex_t operator / (const double& dval, const my_complex_t& rhs)
{
	return my_complex_t(dval) / rhs;
}



my_complex_t sqrt(const my_complex_t& a)
{
	const auto theta  = atan2(a.y, a.x);
	const auto r_sqrt = sqrt(sqrt(a.x*a.x + a.y*a.y));
	my_complex_t i(0.0, 1.0);
	return r_sqrt*cos(theta/2.0) + i*r_sqrt*sin(theta/2.0);
}

std::ostream& operator << (std::ostream& output, const my_complex_t& a)
{
	if (a.y < 0.0) output << a.x << " - " << -a.y << "i";
	else           output << a.x << " + " <<  a.y << "i";
	return output;
}

using value_type = my_complex_t;

value_type quadratic_formula(const value_type& a, const value_type& b, const value_type& c)
{
	return (-1.0*b + sqrt(b*b - 4.0*a*c)) / (2.0*a);
}

int main(int argc, char** argv)
{
	
	value_type a0 =  1.0;
	value_type b0 =  2.0;
	value_type c0 = -23.0;
	
	value_type a1 =  1.0;
	value_type b1 = -2.0;
	value_type c1 =  23.0;
	
	std::cout << quadratic_formula(a0, b0, c0) << std::endl;
	std::cout << quadratic_formula(a1, b1, c1) << std::endl;
	return 0;
}