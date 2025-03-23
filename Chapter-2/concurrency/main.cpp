#include <iostream>
#include <thread>
#include <future>
using namespace std;

//Basic Concurrency Problem 1:
//Three threads print numbers in sequence (Thread 1 prints 1, Thread 2 prints 2, Thread 3 prints 3, then repeat).

auto retFun(int x)
{
    return [x]() { 
        for (int i = 0; i<50; i++){
            cout<<x<<endl; 
        }
    };
}

void program1(){
    std::thread t1 {retFun(11)};
    std::thread t2 {retFun(22)};
    std::thread t3 {retFun(33)};

    t1.join();
    t2.join();
    t3.join();
}

//Testing for async function//

int asyncFunction1(){
    int total = 0;
    for (int i = 0; i < 1000000; i++){
        if(i%100000 == 0)
            cout << "i increased by 100000 from Func1" << endl;
        total = total + i;
    }
    return total;
}

int asyncFunction2(){
    int total = 0; 
    for (int i = 1000000; i< 1000000*2; i++){
        if(i%100000 == 0)
            cout << "i increased by 100000 from Func2" << endl;
        total = total + i;
    }
    return total;
}
void program2(){
    std::future<int> fut = std::async(asyncFunction1); // Function Start Execution from Here//
    std::future<int> fut2 = std::async(asyncFunction2);
    for(int i = 0; i<10000000; i++){
        //Running sync code for 10 times as async code in stread //
        //Try Commenting it out and check different between output//
    }
    std::cout << "Future Value 1: " << fut.get() << endl; //fut put a break, and will not execute until fut is resolved//
    std::cout << "Future Value 2: " << fut2.get() << endl; 
}

//Consumer Producer Problem//
void asyncProducer(promise<int> &prom){
    cout << "releasing value from producer" << endl;
    prom.set_value(10);
}

void asyncConsumer(future<int> &fut){
    cout << "waiting..." <<endl;
    cout<< "getting value from producer: " << fut.get() <<endl;
}

void program3(){
    promise<int> prom;
    future<int> fut = prom.get_future();


   // Force async execution instead of deferred execution

   auto consumerThread = async(launch::async, asyncConsumer, ref(fut));
   auto producerThread = async(launch::async, asyncProducer, ref(prom));

    
}

int main(){
    // program1();

    //  program2();

    program3();
    return 0;
}

