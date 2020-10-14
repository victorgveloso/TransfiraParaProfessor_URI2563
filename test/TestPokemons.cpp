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

TEST(uDebugSecond, SecondExample) {
    int value[] = { 725, 412, 640, 111, 974, 955, 789, 180, 27, 272, 345, 749, 835, 401, 204, 985, 853, 594, 100, 88, 666, 510, 561, 42, 862, 490, 712, 683, 503, 372, 116, 370, 245, 948, 450, 179, 747, 99, 244, 273, 516, 313, 225, 240, 450, 923, 122, 578, 171, 477, 16, 800, 645, 555, 444, 979, 276, 551, 551, 875, 753, 246, 371, 704, 549, 91, 545, 239, 710, 489, 741, 816, 769, 123, 183, 734, 729 };
    int weight[] = { 46, 604, 374, 958, 554, 316, 524, 154, 76, 853, 858, 376, 160, 760, 674, 182, 653, 26, 981, 357, 729, 990, 901, 606, 855, 128, 921, 407, 629, 397, 199, 422, 99, 90, 479, 558, 985, 714, 316, 448, 961, 244, 966, 419, 901, 548, 183, 439, 2, 977, 403, 870, 525, 143, 435, 436, 548, 470, 587, 393, 72, 874, 338, 380, 337, 4, 115, 954, 475, 217, 506, 807, 792, 58, 712, 141, 135 };
    auto p = Pokemons(77, 4437, value, weight);
    ASSERT_EQ(p.calculate(), 14808);
}

TEST(uDebugFirst, ForthExample) {
    int value[] = {57,54,76};
    int weight[] = {74,81,12};
    auto p = Pokemons(3, 135, value, weight);
    ASSERT_EQ(p.calculate(), 133);
}
