#include <iostream>

using namespace std;

int increaseSpeed(int speed){
    return speed+1;
}

int increaseSpeed(char* a){
    return 0;
}

int main(){
    //increaseSpeed(NULL); more than one function matches the argument list
    int ok = increaseSpeed(nullptr);
    cout << "ok: " << ok << endl;
    return 0;
}