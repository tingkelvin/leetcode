#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;

mutex m;

void print(string s){
    for (int i = 0; i < 5; i++) {
        m.lock();
        cout<<s<<endl;
        m.unlock();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
int main(){
    thread t1(print, "Hello");
    thread t2(print, "World");
    thread t3(print, "C++");
    return 0;
}
