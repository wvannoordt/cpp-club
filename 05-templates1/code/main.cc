#include <iostream>
#include <vector>

template <typename obj_t>
void print_thing(const obj_t& param)
{
	std::cout << param << std::endl;
}

template <typename obj_t>
void print(const obj_t& param)
{
	std::cout << param << std::endl;
}

struct point_t
{
	double x, y, z;
	constexpr static double pi = 3.14159265355;
};

template <typename data_t>
struct my_template_t
{
	using value_type = data_t;
	data_t something;
	std::vector<data_t> vec;
};

template <const int i0>
struct example_t
{
	constexpr static int value = i0;
};

template <const int i0, const int i1>
struct arith_t
{
	constexpr static int sum = i0 + i1;
	constexpr static int dif = i0 - i1;
};

template <typename data_t, const int ar_size>
struct my_array_t
{
	data_t data[ar_size];
	constexpr static int size() { return ar_size; }
	data_t& operator[] (int i) { return data[i]; }
};

template <typename data_t, const int n_row, const int n_col>
struct matrix_t
{
	data_t raw[n_row*n_col];
	
	constexpr static int rows() { return n_row; }
	constexpr static int cols() { return n_col; }
	
	data_t& operator() (const int i, const int j)
	{
		return raw[i + n_row*j];
	}
	
	template <const int rhs_col>
	matrix_t<data_t, n_row, rhs_col> operator *(const matrix_t<data_t, n_col, rhs_col>& rhs)
	{
		return matrix_t<data_t, n_row, rhs_col>();
	}
	
	data_t det() // ugly and bad!
	{
		return data_t();
	}
};

template <typename data_t, const int sz>
data_t ex_det(const matrix_t<data_t, sz, sz>& matr)
{
	return data_t();
}


int main()
{
	print(sizeof(arith_t<4, 3>));
	matrix_t<double, 3, 3> matr
	{
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0
	};
	
	print(matr.det());
	print(ex_det(matr));
	
	print(matr(0,0));
	print(matr(0,1));
	
	matrix_t<double, 3, 2>  matr0;
	matrix_t<double, 2, 10> matr1;
	
	print(matr0.det());
	// print(ex_det(matr0)); //invalid
	
	auto result = matr0*matr1;
	print("========");
	print(result.rows());
	print(result.cols());
	print("========");
	
	my_array_t<double, 3> v3{0.2, 1.2, 2.2};
	v3[1] = 100.3;
	for (int i = 0; i < v3.size(); ++i)
	{
		print(v3[i]);
	}

	std::vector<double> data;
	data.resize(100);
	
	example_t<3> e3;
	example_t<2> e2;
	
	print(arith_t<5, 4>::sum);
	print(arith_t<5, 4>::sum);
	
	print(e3.value);
	print(e2.value);
	
	print(sizeof(double));
	print(sizeof(point_t));
	
	point_t zero{0.0, 0.0, 0.0};
	print(zero.pi);
	print(point_t::pi);
	
	print_thing("hello");
	print_thing("world");
	print_thing(1);
	
	my_template_t<double> my_double;
	my_template_t<int>    my_int;
	
	my_template_t<double>::value_type p = 3.14;
	
	return 0;
}
