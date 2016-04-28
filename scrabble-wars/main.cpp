#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

static const std::unordered_map<char, unsigned int> POINT_DISTRIBUTION = {
    {'E', 1}, {'A', 1}, {'I', 1}, {'O', 1}, {'N', 1}, {'R', 1}, {'T', 1}, {'L', 1}, {'S', 1}, {'U', 1},
    {'D', 2}, {'G', 2},
    {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
    {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
    {'K', 5},
    {'J', 8}, {'X', 8},
    {'Q', 10}, {'Z', 10},
};

enum class Fate {
    DRAW = 0, MEL, JESSE, TIE,
};

int main() {
    Fate fate = Fate::DRAW;
    auto won_round = 0u;
    auto mel_win_score = 0u, jesse_win_score = 0u;
    auto mel_score = 0u, jesse_score = 0u;

    std::string line;
    std::string mel_word, jesse_word;
    std::unordered_multiset<char> mel_characters, jesse_characters;
    for (auto round = 1u; std::getline(std::cin, line); ++round) {
        auto mel_gains = 0u;
        auto jesse_gains = 0u;

        std::istringstream sstream{line};
        sstream >> mel_word >> jesse_word;

        mel_characters.reserve(mel_word.size());
        mel_characters.clear();
        for (auto c : mel_word) {
            mel_characters.insert(c);
        }
        for (auto c : jesse_word) {
            mel_characters.erase(c);
        }
        for (auto c : mel_characters) {
            mel_gains += POINT_DISTRIBUTION.at(c);
        }

        jesse_characters.reserve(jesse_word.size());
        jesse_characters.clear();
        for (auto c : jesse_word) {
            jesse_characters.insert(c);
        }
        for (auto c : mel_word) {
            jesse_characters.erase(c);
        }
        for (auto c : jesse_characters) {
            jesse_gains += POINT_DISTRIBUTION.at(c);
        }

        std::cout << "Round: " << round << ": " << mel_gains << " " << jesse_gains << '\n';

        mel_score += mel_gains;
        jesse_score += jesse_gains;

        if (fate == Fate::DRAW) {
            fate = mel_score >= 100
                ? jesse_score >= 100 ? Fate::TIE : Fate::MEL
                : jesse_score >= 100 ? Fate::JESSE : Fate::DRAW;
            if (fate != Fate::DRAW) {
                won_round = round;
                mel_win_score = mel_score;
                jesse_win_score = jesse_score;
            }
        }
    }

    switch (fate) {
        case Fate::DRAW:
            std::cout << "No winner!\n";
            break;
        case Fate::MEL:
            std::cout << "Uncle Mel wins during round " << won_round << ", " << mel_win_score << "-" << jesse_win_score << "!\n";
            break;
        case Fate::JESSE:
            std::cout << "Jesse wins during round " << won_round << ", " << jesse_win_score << "-" << mel_win_score << "!\n";
            break;
        case Fate::TIE:
            std::cout << "Cheater caught in round " << won_round << "!\n";
            break;
    }
}
