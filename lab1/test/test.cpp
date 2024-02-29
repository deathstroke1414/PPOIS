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
    EXPECT_EQ("{A }", set.toString());
}

TEST(SetTest, UnionSets) {
    Set set1, set2;
    set1.add('A');
    set2.add('B');
    Set result = set1 + set2;
    EXPECT_TRUE(result['A']);
    EXPECT_TRUE(result['B']);
}

TEST(SetTest, UnionOtherOperatorTest) {
    Set set1, set2;
    set1.add('A');
    set2.add('B');
    set1 += set2;
    EXPECT_TRUE(set1['A']);
    EXPECT_TRUE(set1['B']);
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

TEST(SetTest, UnionTest) {
    Set set1, set2;

    set1.add('A');
    set1.add('B');
    set1.add('C');

    set2.add('B');
    set2.add('C');
    set2.add('D');

    Set unionSet = set1 + set2;
    EXPECT_EQ("{B C D A B C }", unionSet.toString());
}

TEST(SetTest, IntersectionTest) {
    Set set1, set2;

    set1.add('A');
    set1.add('B');
    set1.add('C');

    set2.add('B');
    set2.add('C');
    set2.add('D');

    Set intersectionSet = set1 * set2;
    EXPECT_EQ("{B }", intersectionSet.toString());
}

TEST(SetTest, PowerSetTest) {
    Set set1, set2;

    set1.add('A');
    set1.add('B');
    set1.add('C');

    Set powerSet;
    powerSet = set1.getPowerSet();

    EXPECT_EQ("{{} {A } {B } {A B } {C } {A C } {B C } {A B C } }", powerSet.toString());
}

TEST(SetTest, ConstructSet) {
    Set set1, set2;

    set1.add('A');
    set1.add('B');
    set1.add('C');

    set2.add('B');
    set2.add('C');
    set2.add('D');
    Set set({ 'a', 'b' }, { set1, set2 });

    EXPECT_EQ("{a b {A B C } {B C D } }", set.toString());
}

TEST(SetTest, PopTest) {
    Set set1;

    set1.add('A');
    set1.add('B');
    set1.add('C');

    set1.pop('A');

    EXPECT_EQ("{B C }", set1.toString());
}

TEST(SetTest, OperatorSquareBrackets) {
    Set set;
    set.add('a');
    set.add('b');
    set.add('c');

    ASSERT_TRUE(set['a']);
    ASSERT_TRUE(set['b']);
    ASSERT_TRUE(set['c']);

    ASSERT_FALSE(set['x']);
    ASSERT_FALSE(set['y']);
    ASSERT_FALSE(set['z']);
}

TEST(SetTest, PopFunctionality) {
    Set set;
    set.add('a');
    set.add('b');
    set.add('c');

    ASSERT_EQ(set.pop('a'), 1);
    ASSERT_FALSE(set['a']);

    ASSERT_EQ(set.pop('x'), 0);
    ASSERT_FALSE(set['x']);
}

TEST(SetTest, OperatorPlusFunctionality) {
    Set set1;
    set1.add('a');
    set1.add('b');
    Set set2;
    set2.add('c');
    set2.add('d');

    Set result = set1 + set2;

    
    ASSERT_TRUE(result['a']);
    ASSERT_TRUE(result['b']);
    ASSERT_TRUE(result['c']);
    ASSERT_TRUE(result['d']);
}