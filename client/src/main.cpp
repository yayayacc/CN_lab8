#include <iostream>

int main() {
#ifdef WINDOWS
    std::cout << "Windows";
#elif LINUX
    std::cout << "Linux";
#endif
    endl(std::cout);
}