//Portable Code
//Code that can be compiled and executed on multiple devices, without significant changes//

#include <iostream>
#include <utility>
#include <atomic>

struct MyArray { int z [50]; };
struct MyStr { int a, b; };

int main(){
    std::atomic<MyArray> myArray;
    std::atomic<MyStr> myStr;
    std::cout << std::boolalpha;
    std::cout << "std::atomic<myArray> is lock free? "
                << std::atomic_is_lock_free(&myArray) << std::endl;
    std::cout << "std::atomic<MyStr> is lock free? "
                << std::atomic_is_lock_free(&myStr) << std::endl;
    
    return 0;
}