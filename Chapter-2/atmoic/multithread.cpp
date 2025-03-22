#include <thread>
#include <iostream>
#include <mutex>

long Cat = 0;
long Dog = 0;
std::mutex CatMutex;
std::mutex DogMutex;
void incrementCatsAndDogs(){
    for(int i = 0; i<3000000; i++){
        CatMutex.lock();
        DogMutex.lock();

        Cat = Cat + 1;
        Dog = Dog + 1;

        CatMutex.unlock();
        DogMutex.unlock();
    }
}

void decrementCatsAndDogs(){   
    for(int i = 0; i<3000000; i++){
        CatMutex.lock();
        DogMutex.lock();

        Dog = Dog - 1;
        Cat = Cat - 1;

        CatMutex.unlock();
        DogMutex.unlock();
    }
}

int main(){
    std::thread t1(incrementCatsAndDogs);
    std::thread t2(decrementCatsAndDogs);

    t1.join();
    t2.join();

    std::cout << "Cats: " << Cat << ", Dogs: " << Dog << std::endl;
}