#include <iostream>
#include <string>

struct cfd_code_t
{
    using real_t = double;
    std::string name;
    double      speed;
    int         num_devs;
    
    void print()
    {
        std::cout << name << " "
            << speed << " "
            << num_devs << std::endl;
    }
};

void print_code(cfd_code_t code)
{
    std::cout << code.name << " "
        << code.speed << " "
        << code.num_devs << std::endl;
}

void print_code(std::string code_name)
{
    std::cout << code_name << " "
        << "?" << " "
        << "?" << std::endl;
}

namespace champs
{
    using champs_real_t = double;
    struct grid_t
    {
        int ncells;
        champs_real_t dx;
        champs_real_t x0;
        champs_real_t x1;
        
        grid_t(champs_real_t x0_in, champs_real_t x1_in, int ncells_in)
        {
            ncells = ncells_in;
            x0     = x0_in;
            x1     = x1_in;
            dx     = (x1 - x0) / ncells;
        }
        
        grid_t(champs_real_t x0_in, champs_real_t x1_in, champs_real_t dx_in)
        {
            x0     = x0_in;
            x1     = x1_in;
            ncells = int((x1 - x0) / dx_in);
            dx     = (x1 - x0) / ncells;
        }
    };
}

int main()
{
    champs::grid_t grid(0.0, 1.0, 50);
    std::cout << grid.dx << std::endl;
    
    champs::grid_t grid2(0.0, 1.0, 0.023);
    std::cout << grid2.dx     << std::endl;
    std::cout << grid2.ncells << std::endl;
    
    using precision_type = double;
    precision_type val = 0.0;
    
    cfd_code_t::real_t val2 = 1.0;
    
    char p = 'a';
    bool b = true;
    double d = 0.0;
    int a = 1;
    float f = 0.0f;
    std::string str = "hello";
    
    cfd_code_t code0;
    code0.name     = "CHAMPS";
    code0.speed    = 1e40; //higher is better
    code0.num_devs = 15;
    
    print_code(code0);
    print_code("CharLES");
    code0.print();
    
    std::cout << code0.name << std::endl;
    
    std::cout << "hello world" << std::endl;
    std::cout << p   << std::endl;
    std::cout << b   << std::endl;
    std::cout << d   << std::endl;
    std::cout << a   << std::endl;
    std::cout << f   << std::endl;
    std::cout << str << std::endl;
    
    return 0;
}
