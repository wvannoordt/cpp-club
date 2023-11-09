#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct prim_t
{
	using value_type = double;
	value_type p, T, u, v, w;
	
	prim_t operator + (const prim_t& rhs) const
	{
		prim_t sum{
		p + rhs.p,
		T + rhs.T,
		u + rhs.u,
		v + rhs.v,
		w + rhs.w
		};
		return sum;
	}
	
	prim_t operator * (const double& coeff) const
	{
		prim_t result{
		coeff*p,
		coeff*T,
		coeff*u,
		coeff*v,
		coeff*w
		};
		return result;
	}
};

//left mult. by double
prim_t operator * (const double& coeff, const prim_t& q)
{
	prim_t result{
		coeff*q.p,
		coeff*q.T,
		coeff*q.u,
		coeff*q.v,
		coeff*q.w
		};
	return result;
}

std::ostream& operator << (std::ostream& output, const prim_t& q)
{
	output << "P:" << q.p << ", T:" << q.T << ", u:" << q.u << ", v:" << q.v << ", w:" << q.w;
	return output;
}

prim_t compute_avg(const prim_t& q0, const prim_t& q1)
{
	prim_t avg{
		0.5*(q0.p + q1.p),
		0.5*(q0.T + q1.T),
		0.5*(q0.u + q1.u),
		0.5*(q0.v + q1.v),
		0.5*(q0.w + q1.w)
		};
	return avg;
}

void iprint(const int& i)
{
	std::cout << i << std::endl;
}

void gen_print(const auto& thing)
{
	std::cout << thing << std::endl;
}

struct ode_t
{
	std::vector<double> solution;
};

namespace ode_methods
{
	struct newton_t  {};
	struct diagjac_t {};
	newton_t  newton;
	diagjac_t diagjac;
}

//tag dispatch
void solve_ode(ode_t& system, const ode_methods::newton_t& input)
{
	
}

void solve_ode(ode_t& system, const ode_methods::diagjac_t& input)
{
	
}

void solve_many_odes(auto& list_of_odes)
{
	for (auto& ode: list_of_odes)
	{
		solve_ode(ode, list_of_odes.method);
	}
}

int main()
{
	iprint(9);
	
	prim_t q0 {500.0, 75.0, 100.0, 0.0, 0.0};
	prim_t q1 {510.0, 77.0, 101.0, 0.0, 0.0};
	
	prim_t q_avg = compute_avg(q0, q1);
	
	std::cout << q_avg.p << std::endl;
	
	prim_t q_sum = q0 + q1;
	
	std::cout << q_sum.p << std::endl;
	
	prim_t q_avg2 = 0.5*q_sum;
	
	std::cout << q_avg2.p << std::endl;
	
	std::cout << q_avg2 << std::endl;
	
	//   A*q
	//   q*A
	
	prim_t zero{0.0, 0.0, 0.0, 0.0, 0.0};
	std::cout << zero << std::endl;
	
	gen_print(zero);
	
	std::ofstream file("file.txt");
	
	file << "hello world" << std::endl;
	file << zero << std::endl;
	
	gen_print("=========================");
	std::stringstream string_str;
	string_str << "hello world" << std::endl;
	string_str << zero << std::endl;
	gen_print(string_str.str());
	gen_print("=========================");
	
	return 0;
}
