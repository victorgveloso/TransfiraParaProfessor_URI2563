#include "Pokemons.h"

int main() {
    std::ostream::sync_with_stdio(false);
    int totalPokemon, maxCapacity;
    while (std::cin >> totalPokemon) {
        std::cin >> maxCapacity;
        int value[totalPokemon], weight[totalPokemon];
        for (int i = 0; i < totalPokemon; i++) {
            std::cin >> value[i];
        }
        for (int i = 0; i < totalPokemon; i++) {
            std::cin >> weight[i];
        }

        std::cout << Pokemons(totalPokemon, maxCapacity, value, weight).calculate() << std::endl;

    }

    return 0;
}
