#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::cout << std::setprecision(2) << std::fixed;

    std::string line;
    std::getline(std::cin, line);
    for (auto n = 1u; std::getline(std::cin, line); ++n) {
        static constexpr auto IN_TO_MI = 5280ul * 12ul;
        static constexpr auto S_TO_H = 60u * 60u;
        static const double PI = std::acos(-1);

        double diameter_in;
        unsigned int revolutions;
        double time_s;

        std::istringstream sstream{line};
        sstream >> diameter_in >> revolutions >> time_s;

        auto circumference_in = PI * diameter_in;
        auto distance_mi = revolutions * circumference_in / IN_TO_MI;
        auto hours = time_s / S_TO_H;
        auto mph = distance_mi / hours;

        std::cout << n << ' ' << distance_mi << ' ' << mph << '\n';
    }
}
