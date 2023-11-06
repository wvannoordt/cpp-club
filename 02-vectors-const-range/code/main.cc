#include <iostream>
#include <vector>

void print_vector(std::vector<double> v)
{
    std::cout << "vector of size " << v.size() << std::endl;
    for (double x: v)
    {
        std::cout << x << std::endl;
    }
}

void print_vector_ref(std::vector<double>& v)
{
    std::cout << "vector& of size " << v.size() << std::endl;
    for (double& x: v)
    {
        std::cout << x << std::endl;
        //some kind of logic requires modification of x
        x = x+1;
    }
}

void print_vector_const_ref(const std::vector<double>& v)
{
    std::cout << "vector& of size " << v.size() << std::endl;
    for (const double& x: v)
    {
        std::cout << x << std::endl;
    }
}

void print_vector_generic(const auto& v)
{
    std::cout << "vector of size " << v.size() << std::endl;
    for (const auto& x: v)
    {
        std::cout << x << std::endl;
    }
}


struct person_t
{
    std::string name;
    int age;
    
    void grow_up()
    {
        age ++;
    }
    
    void print_person() const
    {
        std::cout << name << ", " << age << std::endl;
    }
};

struct my_struct_t
{
    int value0;
    int value1;
};

class my_class_t
{
    private:
        int value0;
    public:
        int value1;
};

void birthday(person_t& person)
{
    person.grow_up();
}

void print_person_vec(const std::vector<person_t>& people)
{
    for (const auto& person: people)
    {
        person.print_person();
    }
}

void something(const int& a, int& b)
{
    b++;
}

int main()
{
    my_struct_t struct_val;
    struct_val.value0 = 1;
    struct_val.value1 = 1;
    
    my_class_t class_val;
    // class_val.value0 = 1; // forbidden
    class_val.value1 = 1;
    
    std::vector<double> v;
    
    v.push_back(1.2);
    v.push_back(2.3);
    v.push_back(3.4);
    
    std::cout << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    
    for (double x: v)
    {
        std::cout << x << std::endl;
    }
    
    print_vector(v);
    
    // value vs. reference
    int v0 = 10;
    std::cout << v0 << std::endl;
    v0++;
    std::cout << v0 << std::endl;
    
    int v1 = v0;
    std::cout << v1 << std::endl;
    v1++;
    std::cout << v1 << std::endl;
    
    // v0 = 11
    int& v2 = v0;
    std::cout << v2 << ", " << v0 << std::endl;
    v2++;
    std::cout << v2 << ", " << v0 << std::endl;
    
    int& v3 = v2;
    std::cout << v3 << ", " << v0 << std::endl;
    v3++;
    std::cout << v3 << ", " << v0 << std::endl;
    
    print_vector_ref(v);
    print_vector(v);
    
    const int v_const = v1;
    // v_const++; //forbidden!
    // int& v_const_ref = v_const; // Also forbidden!
    const int& v_const_ref = v_const;
    
    //Quick talk on pointers
    int c0 = 10;
    int& c0_ref = c0;
    int* c0_ptr = &c0;
    
    std::cout <<  c0     << std::endl;
    std::cout <<  c0_ref << std::endl;
    std::cout <<  c0_ptr << std::endl;
    std::cout << *c0_ptr << std::endl;
    
    int* dangle_ptr; //scary
    // int& dangle_ref; //illegal
    
    
    
    
    
    
    
    
    auto  element = v[0];
    auto& element_ref = v[0];
    const auto& const_elem_ref = v[0];
    
    const auto& const_vec_ref = v;
    
    decltype(v) vec2;
    
    std::cout << const_elem_ref << std::endl;
    
    print_vector_generic(v);
    
    std::vector<std::string> string_vec;
    string_vec.push_back("hello");
    string_vec.push_back("world");
    
    print_vector_generic(string_vec);
    
    person_t mystery_student;
    mystery_student.name = "Sparsh";
    mystery_student.age  = 21;
    
    std::cout << mystery_student.age << std::endl;
    birthday(mystery_student);
    std::cout << mystery_student.age << std::endl;
    
    mystery_student.print_person();
    
    std::vector<person_t> people;
    people.push_back(mystery_student);
    print_person_vec(people);
    
    int int0 = 9;
    int& r0 = int0;
    const int& r1 = int0;
    
    std::cout << int0 << std::endl;
    std::cout << r0   << std::endl;
    std::cout << r1   << std::endl;
    
    int0++;
    
    std::cout << int0 << std::endl;
    std::cout << r0   << std::endl;
    std::cout << r1   << std::endl;
    
    r0++;
    
    std::cout << int0 << std::endl;
    std::cout << r0   << std::endl;
    std::cout << r1   << std::endl;
    
    something(int0, int0);
    
    return 0;
}
