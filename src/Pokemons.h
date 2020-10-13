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

    int calculate(int size, int capacity) {
        if (size == 0) {
            return 0;
        }
        if (cache[biToUni(capacity, size - 1)] == -1) {
            cache[biToUni(capacity, size - 1)] = calculate(size - 1, capacity);
        }
        int unplacedPkm = calculate(size - 1, capacity);
        if (pkms[size - 1].weight > capacity) {
            return unplacedPkm;
        }
        if (cache[biToUni(capacity - pkms[size - 1].weight, size - 1)] == -1) {
            cache[biToUni(capacity - pkms[size - 1].weight, size - 1)] = calculate(size - 1,
                                                                                   capacity - pkms[size - 1].weight);
        }
        int placedPkm = cache[biToUni(capacity - pkms[size - 1].weight, size - 1)] + pkms[size - 1].price;
        cache[biToUni(capacity, size)] = std::max(placedPkm, unplacedPkm);
        return cache[biToUni(capacity, size)];
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
            for (int cap = 1; cap <= maxCapacity; ++cap) {
                int w = pkms[pk].weight;
                int p = pkms[pk].price;
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
