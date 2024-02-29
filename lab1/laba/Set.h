#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Set
{
private:

    mutable list<char> elements;
    mutable list<Set> sets;

public:


    Set(const list<char>& elems, const list<Set>& subSets);

    Set getPowerSet() const;

    Set();

    Set(const Set& other);

    void add(char el);

    void add(string elements);

    string toString();

    int emptyCheck();

    int pop(char a);

    int setSize();

    bool operator[](char el);

    Set operator+(Set& other);

    Set& operator+=(Set& other);

    bool operator==(const Set& other);

    Set& operator*(Set& other);
};