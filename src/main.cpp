#include "Pokemons.h"

int main() {
    int totalPokemon, maxCapacity;
    std::cin >> totalPokemon >> maxCapacity;
    int value[totalPokemon], weight[totalPokemon];
    for (int i = 0; i < totalPokemon; i++) {
        std::cin >> value[i];
    }
    for (int i = 0; i < totalPokemon; i++) {
        std::cin >> weight[i];
    }

    auto p = Pokemons(totalPokemon, maxCapacity, value, weight);

    return 0;
}
