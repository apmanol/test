#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>



int main() {
    std::cout << "Hello World!" << std::endl;
    std::vector<std::thread> threads;

    for (auto i =0 ; i < 10; i++)
    {
        std::cout << "starting threads" << std::endl;
        threads.push_back(std::thread([i](){
            std::cout << "starting thread" << i << std::endl;
        }));
    }


    std::for_each(threads.begin(),threads.end(), [](std::thread &t){ 
        t.join();
    });
}
