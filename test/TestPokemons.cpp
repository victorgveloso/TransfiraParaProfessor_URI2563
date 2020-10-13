//
// Created by victor on 12/10/2020.
//

#include <gtest/gtest.h>
#include <Pokemons.h>

TEST(TestPokemons, FirstExample) {
    int value[] = {1,8,14,22};
    int weight[] = {4,12,20,30};
    auto p = Pokemons(4, 52, value, weight);
    ASSERT_EQ(p.calculate(), 36);
}

TEST(TestPokemons, SecondExample) {
    int value[] = {9,5,2};
    int weight[] = {12,8,42};
    auto p = Pokemons(3, 2, value, weight);
    ASSERT_EQ(p.calculate(), 0);
}