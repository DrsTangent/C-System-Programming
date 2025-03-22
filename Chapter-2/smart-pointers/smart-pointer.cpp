#include <iostream>
#include <memory>

class Test{
    public:
    Test(){
        std::cout << "Test Object Created" << std::endl;
    }
    ~Test(){
        std::cout << "Test object deleted" <<  std::endl;
    }
    void somefunction(){
        std::cout << "Function Called" << std::endl;
    }
};

void singlePtrTest(){
    std::unique_ptr<Test> testPtr = std::make_unique<Test> ();
    testPtr->somefunction();
}

void arrayPointerTest(int size, Test* g){
    std::unique_ptr<Test[]> testArr = std::make_unique<Test[]>(size);

    *g = testArr[0];

    std::cout << g;
    
    for(int i = 0; i<size; i++){
        testArr[i].somefunction();
    }
}

int main(){
    std::cout << "Single Pointer Test starts here: " << std::endl;
    singlePtrTest();
    std::cout << "Single Pointer Test ends here" << std::endl;

    std::cout << "Array Pointer Test starts here: " << std::endl;
    Test* t = nullptr;
    std::cout << t;
    arrayPointerTest(5, t);
    std::cout << t;
    std::cout << "Array Pointer Test ends here" << std::endl;
    return 0;
}