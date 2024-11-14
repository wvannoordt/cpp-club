#include <iostream>


template <typename data_t>
struct my_vector
{
    data_t* ptr;
    std::size_t vec_size;
    
    my_vector()
    {
        ptr      = nullptr;
        vec_size = 0;
    }
    
    ~my_vector()
    {
        deallocate(ptr);
    }
    
    std::size_t size() const { return vec_size; }
    
    my_vector(const my_vector& rhs)
    {
        // resize(rhs.size());
        // for (std::size_t j = 0; j < rhs.size(); ++j)
        // {
        //     ptr[j] = rhs.ptr[j];
        // }
    }
    
    my_vector& operator = (const my_vector& rhs)
    {
        resize(rhs.size());
        for (std::size_t j = 0; j < rhs.size(); ++j)
        {
            ptr[j] = rhs.ptr[j];
        }
        return *this;
    }
    
    my_vector (my_vector&& rhs)
    {
        ptr = rhs.ptr;
        vec_size = rhs.size();
        
        rhs.ptr = nullptr;
        rhs.vec_size = 0;
    }
    
    my_vector& operator = (my_vector&& rhs)
    {
        ptr = rhs.ptr;
        vec_size = rhs.size();
        
        rhs.ptr = nullptr;
        rhs.vec_size = 0;
        
        return *this;
    }
    
    data_t* allocate(const std::size_t& size)
    {
        return new data_t[size];
    }
    
    void deallocate(data_t* ptr_in)
    {
        if (ptr != nullptr)
        {
            delete [] ptr_in;
        }
    }
    
    void resize(const std::size_t& new_size, const data_t& new_val = data_t())
    {
        data_t* new_buf = allocate(new_size);
        
        for (std::size_t i = 0; i < new_size; ++i)
        {
            new_buf[i] = new_val;
        }
        
        for (std::size_t i = 0; i < vec_size; ++i)
        {
            new_buf[i] = ptr[i];
        }
        
        deallocate(ptr);
        
        ptr      = new_buf;
        vec_size = new_size;
    }
};

void print_vec()
{
    my_vector<int> vec;
    vec.resize(3, 5);
    for (int i = 0; i < vec.vec_size; ++i) std::cout << vec.ptr[i] << std::endl;
}

int main()
{
    my_vector<int> vec;
    vec.resize(3, 5);
    
    for (int i = 0; i < vec.vec_size; ++i) std::cout << vec.ptr[i] << std::endl;
    
    vec.resize(6, 9);
    std::cout << "=====" << std::endl;
    for (int i = 0; i < vec.vec_size; ++i) std::cout << vec.ptr[i] << std::endl;
    
    print_vec();
    
    
    my_vector<int> data0;
    data0.resize(10);
    
    my_vector<int> data1;
    data1 = data0;
    
    // my_vector<int> data2 = data0;
    
    my_vector<int> data3;
    data3.resize(140000, 5);
    
    my_vector<int> data4;
    
    std::cout << "data 3 size: " << data3.size() << std::endl;
    std::cout << "data 3 addr: " << data3.ptr    << std::endl;
    std::cout << "data 4 size: " << data4.size() << std::endl;
    std::cout << "data 4 addr: " << data4.ptr    << std::endl;
    
    data4 = std::move(data3);
    
    std::cout << "data 3 size: " << data3.size() << std::endl;
    std::cout << "data 3 addr: " << data3.ptr    << std::endl;
    std::cout << "data 4 size: " << data4.size() << std::endl;
    std::cout << "data 4 addr: " << data4.ptr    << std::endl;
    
    my_vector<int> data5 = std::move(data4);
    
	return 0;
}
