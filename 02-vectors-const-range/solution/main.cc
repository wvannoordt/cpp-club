#include <iostream>
#include <vector>

struct my_type_t
{
	std::vector<double>      d_data;
	std::vector<std::string> s_data;
	
	my_type_t(const int n)
	{
		for (int i = 0; i < n; ++i)
		{
			d_data.push_back(2.0*i);
			s_data.push_back("hello");
		}
	}
	
	void print_data(const auto& d) const
	{
		for (const auto& v: d)
		{
			std::cout << v << std::endl;
		}
	}
	
	void print() const
	{
		print_data(d_data);
		print_data(s_data);
	}
};

int main()
{
	my_type_t data(10);
	data.print();
	return 0;
}
