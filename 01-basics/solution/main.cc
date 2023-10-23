#include <iostream>


struct prim_t
{
    using real_t = double;
    
    real_t p, T, u, v, w;
    
    prim_t(real_t p_in, real_t T_in, real_t u_in, real_t v_in, real_t w_in)
    {
        p = p_in;
        T = T_in;
        u = u_in;
        v = v_in;
        w = w_in;
    }
    
    prim_t(real_t val)
    {
        p = val;
        T = val;
        u = val;
        v = val;
        w = val;
    }
    
    void print()
    {
        std::cout
            << "P=" << p
            << ", T=" << T
            << ", u=" << u
            << ", v=" << v
            << ", w=" << w << std::endl;
    }
};

int main()
{
    prim_t q(1.0, 2.0, 3.0, 4.0, 5.0);
    q.print();
    prim_t p(3.0);
    p.print();
    
    return 0;
}