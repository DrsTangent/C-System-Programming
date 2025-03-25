import temperature_engine;
#include <iostream>

int main() {
    std::vector<int> celsiusTemps = {0, 100, -40, 37};
    auto fahrenheitTemps = toFahrenheitFromCelsius(celsiusTemps);

    for (int temp : fahrenheitTemps) {
        std::cout << temp << " ";
    }
    return 0;
}