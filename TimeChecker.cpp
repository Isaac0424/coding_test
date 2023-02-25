#include <chrono>
#include <iostream>
#include <functional>


class TimeChecker{
    public:
    static void checkTimeForQuiz(void (*fnPtr) ()){
        auto start= std::chrono::high_resolution_clock::now();
        (*fnPtr)();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Time for test = " << diff.count() << std::endl;
    }
        static void checkTimeForQuiz(const std::function<void()> fn){
        auto start= std::chrono::high_resolution_clock::now();
        fn();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Time for test = " << diff.count() << std::endl;

    }
};

void test(){
    for(auto i=0; i < 10000;i++){
        for(auto i=0; i < 1000;i++){
             std::cout<<i/7<<std::endl;
        }
    }
}
int main(){
    void (*fnPtr)();
    fnPtr=test;
    TimeChecker::checkTimeForQuiz(fnPtr);
}