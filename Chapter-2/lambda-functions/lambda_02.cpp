#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::vector<int> v {1,2,3,4,5};

    for(int i = 0; i<v.size(); i++){
        std::cout << "Address of " << v.at(i) << " is " <<  &v.at(i) << std::endl;
    }
    for_each( begin(v), end(v), [&](int& x){
        std::cout << "Address of " << x << " is " <<  &x << std::endl;
    });

    return 0;
}