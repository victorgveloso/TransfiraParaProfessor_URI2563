//
// Created by victor on 12/10/2020.
//

#ifndef TRANSFIRAPARAPROFESSOR_URI2563_POKEMONS_H
#define TRANSFIRAPARAPROFESSOR_URI2563_POKEMONS_H

#include "bits/stdc++.h"

struct Pokemon {
    int weight;
    int price;

    Pokemon(int w, int p) : weight(w), price(p) {}
    bool operator < (const Pokemon& other) const
    {
        return weight < other.weight;
    }
};

class Pokemons {
    int totalPokemon, maxCapacity;
    std::vector<Pokemon> pkms;
    int *cache;
    int calculate(int size, int capacity) {
        if (size == 0 || pkms[size - 1].weight > capacity) {
            return 0;
        }
        return std::max(calculate(size - 1,capacity - pkms[size - 1].weight) + pkms[size - 1].price,
                        calculate(size - 1,capacity));
    }
public:
    int biToUni(int capacity, int pokemonIdx) const {
        return (capacity * totalPokemon) + pokemonIdx;
    }

    Pokemons(int nPokemons, int capacity, const int *value, const int *weight) : totalPokemon(nPokemons),
                                                                                 maxCapacity(capacity) {
        pkms = std::vector<Pokemon>(nPokemons,Pokemon(0,0));
        for (int i = 0; i < nPokemons; ++i) {
            pkms[i].weight = weight[i];
            pkms[i].price = value[i];
        }
        std::sort(pkms.rbegin(),pkms.rend()); // Descending sorting
        cache = new int[nPokemons * capacity];
    }
    int calculate() {
        return calculate(totalPokemon, maxCapacity);
    }

};


#endif //TRANSFIRAPARAPROFESSOR_URI2563_POKEMONS_H
