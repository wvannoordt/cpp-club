#include <iostream>
#include <algorithm>
#include <vector>
// a_i = i*i
int sequence0(int i)
{
	return i*i;
}

// a_i = i*(k - i);
int k = 9;
int sequence1(int i, int k)
{
	return i*(k - i);
}
int sequence2(int i)
{
	return sequence1(i, k);
}

// \sum_{i = i0}^{i1-1} a_i
// int compute_partial_sum(int i0, int i1, int(*sequence)(int))
int compute_partial_sum(int i0, int i1, const auto& sequence)
{
	std::cout << "summing from " << i0 << " to " << i1 << "..." << std::endl;
	int result = 0;
	for (int i = i0; i < i1; ++i)
	{
		const int element = sequence(i);
		result += element;
	}
	return result;
}

// functors
struct my_seq_t
{
	int k;
	int operator() (const int& i) const
	{
		return i*(k - i);
	}
};

bool double_greater_than(const double a, const double b)
{
	return a > b;
}

void print_vec(const auto& data)
{
	std::cout << "======" << std::endl;
	for (const auto& d: data) std::cout << d << " ";
	std::cout << std::endl;
	std::cout << "======" << std::endl;
}

template <typename vec_t>
void print_vec_T(const vec_t& data)
{
	std::cout << "======" << std::endl;
	for (const auto& d: data) std::cout << d << " ";
	std::cout << std::endl;
	std::cout << "======" << std::endl;
}

template <const int i, const int j>
void add()
{
	std::cout << i+j << std::endl;
}

template <typename data_t>
struct my_template_t
{
	data_t data;
	int u;
	std::string name;
};

template <typename data_t>
struct my_vector
{
	data_t data[9];
};

int main()
{
	std::vector<std::string> names{"will", "joel", "sparsh"};
	std::vector<double> stuff{1.0, 1.9};
	
	my_vector<int> i0;
	my_vector<float> i1;
	my_vector<char> i2;
	
	print_vec(names);
	print_vec(stuff);
	
	add<2,3>();
	
	print_vec_T<std::vector<std::string>>(names);
	print_vec_T(names);
	
	int sum = compute_partial_sum(0, 10, sequence0);
	k = 9;
	int sum2 = compute_partial_sum(0, 10, sequence2);
	std::cout << sum  << std::endl;
	std::cout << sum2 << std::endl;
	
	int k2 = 9;
	my_seq_t my_seq{k2};
	//equivalent to 
	// my_seq_t my_seq;
	// my_seq.k = 9;
	int sum3 = compute_partial_sum(0, 10, my_seq);
	std::cout << sum3 << std::endl;
	
	// Lambdas
	const auto my_lambda = [k2](const int i){ return i*(k2 - i); };
	int sum4 = compute_partial_sum(0, 10, my_lambda);
	std::cout << sum4 << std::endl;
	
	
	const auto my_lambda2 = [&k2](const int i){ return i*(k2 - i); };
	int sum5 = compute_partial_sum(0, 10, my_lambda2);
	std::cout << sum5 << std::endl;
	
	const auto my_lambda3 = [&](const int i){ return i*(k2 - i); };
	int sum6 = compute_partial_sum(0, 10, my_lambda3);
	std::cout << sum6 << std::endl;
	
	const auto my_lambda4 = [=](const int i){ return i*(k2 - i); };
	int sum7 = compute_partial_sum(0, 10, my_lambda4);
	std::cout << sum7 << std::endl;
	
	int k3 = 1;
	const auto my_lambda5 = [=, &k3](const int i){ return k3 + i*(k2 - i); };
	int sum8 = compute_partial_sum(0, 10, my_lambda5);
	std::cout << sum8 << std::endl;
	
	const auto my_lambda6 = [&, k3](const int i){ return k3 + i*(k2 - i); };
	int sum9 = compute_partial_sum(0, 10, my_lambda6);
	std::cout << sum9 << std::endl;
	
	const auto lam0 = [&, k3, internal = 8](const int i){ return internal + k3 + i*(k2 - i); };
	
	std::vector<double> data{1.3, 1.2, 5.6, 1.43, 8.7, 9.8, -1.0};
	
	const auto print_data = [&]()
	{
		std::cout << "======" << std::endl;
		for (const auto& d: data) std::cout << d << " ";
		std::cout << std::endl;
		std::cout << "======" << std::endl;
	};
	
	print_data();
	std::sort(data.begin(), data.end(), [](const double a, const double b) { return a > b; });
	// std::sort(data.begin(), data.end(), double_greater_than);
	print_data();
	
	
	
	return 0;
}
