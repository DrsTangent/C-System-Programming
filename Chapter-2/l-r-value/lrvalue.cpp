#include <iostream>
#include <vector>
#include <string>

//Printing Functions for L and R Values//

void print(std::string & s){
    std::string str (std::move(s));

    std::cout << "value of str = " << str << std::endl;
    std::cout << "value of s= " << s << std::endl;

    s = (std::move(str));
}

void print(std::string && s){

}

// Testing//

void test1(){
    std::cout << "Test 1" << std::endl;

    std::string a = "ali hussain";
    auto b = std::move(a);

    std::cout << "a: " << a.size() << ", value: " << a << std::endl;
    std::cout << "b: " << b.size() << std::endl;
}

void test2(){
    std::cout << "Test 2" << std::endl;

    std::string str = "string value in test 2";

    print(str);

    std::cout << " Value of parameter after function execution: " << str << std::endl;
}

int main(){
    test1();
    test2();
}