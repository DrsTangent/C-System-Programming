#include <iostream>
#include <vector>
#include <string>
int main(){
    std::vector<std::string> v {"ali", "hussain"};

    for(auto iter = v.begin(); iter != v.end(); ++iter){
        std::cout << *iter;
    }

    auto test = {1, 2, 3};

    for (auto iter = test.begin(); iter != test.end(); iter++){
        std::cout << *iter;
    }
    return 0;
}