#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string a = "ali hussain";
    auto b = std::move(a);

    std::cout << "a: " << a.size() << ", value: " << a << std::endl;
    std::cout << "b: " << b.size() << std::endl;
}