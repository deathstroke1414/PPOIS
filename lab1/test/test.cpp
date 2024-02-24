#include "gtest/gtest.h"
#include "C:\PPOIS\testlaba2\laba2\Set.cpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

TEST(SetTest, AddElement) {
    Set set;
    set.add('A');
    EXPECT_TRUE(set['A']);
}

TEST(SetTest, UnionSets) {
    Set set1, set2;
    set1.add('A');
    set2.add('B');
    Set result = set1 + set2;
    EXPECT_TRUE(result['A']);
    EXPECT_TRUE(result['B']);
}

TEST(SetTest, EmptySetCheck) {
    Set set;
    EXPECT_TRUE(set.emptyCheck());
}

TEST(SetTest, SetSize) {
    Set set;
    set.add('A');
    set.add('B');
    EXPECT_EQ(set.setSize(), 2);
}

TEST(SetTest, EqualSets) {
    Set set1, set2;
    set1.add('A');
    set2.add('A');
    EXPECT_TRUE(set1 == set2);
}

TEST(SetTest, StringSet) {
    Set set;
    string input = "{a, {b, c}}";
    set.add(input);
    EXPECT_TRUE(set['a']);
}