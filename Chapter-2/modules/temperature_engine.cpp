export module temperature_engine;

import std;

export
std::vector<int> toFahrenheitFromCelsius(std::vector<int> &celsius) {
    return celsius | std::views::transform([](int c) { return (c * 9 / 5) + 32; }) 
                   | std::ranges::to<std::vector<int>>();
}