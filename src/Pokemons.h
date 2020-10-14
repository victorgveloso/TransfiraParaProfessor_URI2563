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

    bool operator<(const Pokemon &other) const {
        return weight < other.weight;
    }
};

class Pokemons {
    int totalPokemon, maxCapacity;
    std::vector<Pokemon> pkms;
    std::vector<int> cache;

    int biToUni(int capacity, int pokemonIdx) const {
        return (capacity * totalPokemon) + pokemonIdx;
    }

public:

    Pokemons(int nPokemons, int capacity, const int *value, const int *weight) : totalPokemon(nPokemons),
                                                                                 maxCapacity(capacity) {
        pkms = std::vector<Pokemon>(nPokemons, Pokemon(0, 0));
        for (int i = 0; i < nPokemons; ++i) {
            pkms[i].weight = weight[i];
            pkms[i].price = value[i];
        }
        cache = std::vector<int>((nPokemons + 1) * (capacity + 1), 0);
    }

    int calculate() {

        for (int pk = 1; pk <= totalPokemon; ++pk) {
            int w = pkms[pk-1].weight;
            int p = pkms[pk-1].price;
            for (int cap = 1; cap <= maxCapacity; ++cap) {
                if (w > cap) {
                    cache[biToUni(cap, pk)] = cache[biToUni(cap, pk - 1)];
                } else {
                    cache[biToUni(cap, pk)] = std::max(cache[biToUni(cap, pk - 1)],
                                                       cache[biToUni(cap - w, pk - 1)] + p);
                }
            }
        }
        return cache[biToUni(maxCapacity, totalPokemon)];
    }

};


#endif //TRANSFIRAPARAPROFESSOR_URI2563_POKEMONS_H
