#include <cstddef>

#include <array>
#include <iostream>
#include <sstream>
#include <string>

using PegNames = std::array<std::string, 3>;

enum class Peg {
    A, B, C
};

static constexpr Peg other(Peg a, Peg b) {
    switch (a) {
        case Peg::A:
            return b == Peg::B ? Peg::C : Peg::B;
        case Peg::B:
            return b == Peg::A ? Peg::C : Peg::A;
        case Peg::C:
            return b == Peg::A ? Peg::B : Peg::A;
    }
}

static void solve(const PegNames &peg_names, unsigned int num_disks, Peg src, Peg dst) {
    if (num_disks == 0 || src == dst) return;
    auto mid = other(src, dst);
    solve(peg_names, num_disks - 1, src, mid);
    std::cout << peg_names[static_cast<std::size_t>(src)] << " -> " << peg_names[static_cast<std::size_t>(dst)] << '\n';
    solve(peg_names, num_disks - 1, mid, dst);
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    PegNames peg_names;
    while (std::getline(std::cin, line)) {
        unsigned int num_disks;

        std::istringstream sstream{line};
        sstream >> num_disks >> peg_names[0] >> peg_names[1] >> peg_names[2];

        std::cout << "Hanoi!\n";
        solve(peg_names, num_disks, Peg::A, Peg::C);
    }
}
