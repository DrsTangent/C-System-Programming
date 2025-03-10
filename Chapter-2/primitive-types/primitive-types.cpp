#include <iostream>
#include <limits>

template <typename T>
void getLimits() {
    std::cout << "Min: " << std::numeric_limits<T>::min() << "\n"
              << "Max: " << std::numeric_limits<T>::max() << "\n"
              << "Size (Bytes): " << sizeof(T) << "\n\n";
}

int main() {
    getLimits<int>();
    getLimits<float>();
    getLimits<double>();
    getLimits<char>();

    return 0;
}