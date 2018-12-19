#include "inc.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    Inc inc;
    IncTLS inc_tls;
    int count;

    if (2 == argc) {
        count = std::atoi(argv[1]);
    }
    else {
        count = 100000;
    }

    std::cout << "count = " << count << std::endl;

    auto start = std::chrono::system_clock::now();
    for (int i=0; i<count; ++i) {
        inc();
    }
    auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = stop-start;
    std::cout << "static :  " << elapsed_seconds.count() << std::endl;

    start = std::chrono::system_clock::now();
    for (int i=0; i<count; ++i) {
        inc_tls();
    }
    stop = std::chrono::system_clock::now();
    elapsed_seconds = stop-start;
    std::cout << "   tls :  " << elapsed_seconds.count() << std::endl;

    return 0;
}
