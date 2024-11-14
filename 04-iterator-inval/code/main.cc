#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>

int main()
{
    int  i = 0;
    int& j = i;
    
    std::cout << "before: " << i << std::endl;
    
    j++;
    
    std::cout << "after: " << i << std::endl;
    
    std::vector<int> my_data;
    
    my_data.push_back(9);
    
    std::cout << "data:     " << my_data.data() << std::endl;
    std::cout << "size:     " << my_data.size() << std::endl;
    std::cout << "capacity: " << my_data.capacity() << std::endl;
    
    my_data.push_back(3);
    
    std::cout << "data:     " << my_data.data() << std::endl;
    std::cout << "size:     " << my_data.size() << std::endl;
    std::cout << "capacity: " << my_data.capacity() << std::endl;
    
    my_data.push_back(2);
    
    std::cout << "data:     " << my_data.data() << std::endl;
    std::cout << "size:     " << my_data.size() << std::endl;
    std::cout << "capacity: " << my_data.capacity() << std::endl;
    
    my_data.push_back(4);
    
    std::cout << "data:     " << my_data.data() << std::endl;
    std::cout << "size:     " << my_data.size() << std::endl;
    std::cout << "capacity: " << my_data.capacity() << std::endl;
    
    my_data.push_back(8);
    
    std::cout << "data:     " << my_data.data() << std::endl;
    std::cout << "size:     " << my_data.size() << std::endl;
    std::cout << "capacity: " << my_data.capacity() << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    
    std::vector<std::string> my_strings;
    my_strings.push_back("string 0");
    my_strings.push_back("string 1");
    my_strings.push_back("string 2");
    my_strings.push_back("string 3");
    my_strings.push_back("string 4");
    
    std::string& element_2 = my_strings[2];
    
    std::cout << element_2     << std::endl;
    std::cout << my_strings[2] << std::endl;
    std::cout << "size:     " << my_strings.size() << std::endl;
    std::cout << "capacity: " << my_strings.capacity() << std::endl;
    
    my_strings.push_back("string 5");
    my_strings.push_back("string 6");
    my_strings.push_back("string 7");
    
    std::cout << "====="       << std::endl;
    std::cout << element_2     << std::endl;
    std::cout << my_strings[2] << std::endl;
    std::cout << "size:     "  << my_strings.size() << std::endl;
    std::cout << "capacity: "  << my_strings.capacity() << std::endl;
    
    my_strings.push_back("string 8");
    
    std::cout << "====="       << std::endl;
    std::cout << element_2     << std::endl;
    std::cout << my_strings[2] << std::endl;
    std::cout << "size:     "  << my_strings.size() << std::endl;
    std::cout << "capacity: "  << my_strings.capacity() << std::endl;
    
    
    std::vector<int> temp{1, 5, 4, 6, 3, 5, 6, 761, 24, 14, 0};
    
    // for (const auto i: temp)
    const auto end = temp.end();
    for (auto i = temp.begin(); i != end; i++)
    {
        std::cout << *i << std::endl;
        temp.push_back(2*(*i));
    }
    
    std::unique_ptr<std::string> my_ptr(new std::string("my_string"));
    
    
    
	return 0;
}
