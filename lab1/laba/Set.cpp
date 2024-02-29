#include "Set.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

Set::Set()
{
    elements.clear();
    sets.clear();
}


Set::Set(const list<char>& elems, const list<Set>& subSets)
{
    elements = elems;
    sets = subSets;
}

Set Set::getPowerSet() const
{
    Set result;
    result.sets.push_back(Set());
    for (const char& element : elements)
    {
        list<Set> newSets;

        for (const Set& subSet : result.sets)
        {
            Set newSubset = subSet;
            newSubset.elements.push_back(element);
            newSets.push_back(newSubset);
        }

        for (const Set& newSet : newSets)
        {
            result.sets.push_back(newSet);
        }
    }

    for (const Set& subset : sets)
    {
        Set subsetPowerSet = subset.getPowerSet();
        result.sets.insert(result.sets.end(), subsetPowerSet.sets.begin(), subsetPowerSet.sets.end());
    }

    return result;
}

Set::Set(const Set& other)
{
    elements.clear();
    sets.clear();

    list<char>::const_iterator it;

    for (it = other.elements.begin(); it != other.elements.end(); ++it)
    {
        this->elements.push_back(*it);
    }

    list<Set>::const_iterator it1;

    for (it1 = other.sets.begin(); it1 != other.sets.end(); ++it1)
    {
        this->sets.push_back(*it1);
    }
}

void Set::add(char el)
{
    elements.push_back(el);
}

void Set::add(string elements)
{
    int k = 0;
    if (elements[0] == '{')
        for (int i = 1; elements[i] != '\0'; i++)
        {
            if (elements[i] == ' ' || elements[i] == ',')
                continue;
            else if (elements[i] == '{')
            {
                Set* Buf = new Set();
                k++;
                Buf->add(elements.substr(i));
                while (k != 0)
                {
                    i++;
                    if (elements[i] == '}')
                        k--;
                    if (elements[i] == '{')
                        k++;
                }

                sets.push_back(*Buf);
            }
            else if (elements[i] == '}')
                return;
            else
                add(elements[i]);
        }
    else
        cout << "ERR";
}

string Set::toString()
{
    list<char>::iterator it;

    string result = "{";

    for (it = elements.begin(); it != elements.end(); ++it)
    {
        result += *it;
        result += ' ';
    }

    list<Set>::iterator it11;

    for (it11 = sets.begin(); it11 != sets.end() && sets.size() != 0; ++it11)
    {
        result += (*it11).toString();
        result += ' ';
    }

    result += '}';

    return result;
}

int Set::emptyCheck()
{
    int count = 0;
    if (elements.size() == 0)
    {
        list<Set>::iterator it1;

        for (it1 = sets.begin(); it1 != sets.end(); ++it1)
        {
            count += (*it1).emptyCheck();
        }

        if (count == 0)
            return 1;
    }

    return 0;
}

int Set::pop(char a)
{
    list<char>::iterator it;

    for (it = elements.begin(); it != elements.end(); ++it)
    {
        if (*it == a)
        {
            elements.erase(it);
            return 1;
        }
    }

    list<Set>::iterator it1;

    for (it1 = sets.begin(); it1 != sets.end(); ++it1)
    {
        if ((*it1).pop(a))
            return 1;
    }
    return 0;
}

int Set::setSize()
{
    int count = 0;
    count += elements.size();

    list<Set>::iterator it1;

    for (it1 = sets.begin(); it1 != sets.end(); ++it1)
    {
        count += (*it1).setSize();
    }

    return count;
}

bool Set::operator[](char el)
{
    list<char>::iterator it;

    for (it = elements.begin(); it != elements.end(); ++it)
    {
        if ((*it) == el)
            return 1;
    }

    list<Set>::iterator it1;

    for (it1 = sets.begin(); it1 != sets.end(); ++it1)
    {
        if ((*it1)[el])
            return 1;
    }

    return 0;
}

Set Set::operator+(Set& other)
{
    Set result;

    list<char>::iterator it;

    for (it = other.elements.begin(); it != other.elements.end(); ++it)
    {
        result.elements.push_back(*it);
    }

    for (it = elements.begin(); it != elements.end(); ++it)
    {
        result.elements.push_back(*it);
    }

    list<Set>::iterator it1;

    for (it1 = other.sets.begin(); it1 != other.sets.end(); ++it1)
    {
        result.sets.push_back(*it1);
    }

    for (it1 = sets.begin(); it1 != sets.end(); ++it1)
    {
        result.sets.push_back(*it1);
    }

    return result;

}

Set& Set::operator+=(Set& other)
{
    list<char>::iterator it;

    for (it = other.elements.begin(); it != other.elements.end(); ++it)
    {
        this->elements.push_back(*it);
    }

    list<Set>::iterator it1;

    for (it1 = other.sets.begin(); it1 != other.sets.end(); ++it1)
    {
        this->sets.push_back(*it1);
    }

    return *this;
}

bool Set::operator==(const Set& other)
{
    elements.sort();
    other.elements.sort();

    if (elements.size() != other.elements.size())
        return 0;

    if (sets.size() != other.sets.size())
        return 0;

    list<char>::iterator it1, it2;

    for (it1 = other.elements.begin(), it2 = elements.begin(); it1 != other.elements.end() && it2 != elements.end(); ++it1, ++it2)
    {
        if ((*it1) != (*it2))
            return 0;
    }

    if (it1 == other.elements.end() && it2 == elements.end())
    {

        list<Set>::iterator it11, it22;

        Set a = *this;
        Set b = other;

        for (it11 = a.sets.begin(); it11 != a.sets.end(); ++it11)
        {
            for (it22 = b.sets.begin(); it22 != b.sets.end(); ++it22)
            {
                if ((*it22) == (*it11))
                {
                    a.sets.erase(it11);
                    b.sets.erase(it22);
                }

                if (a.sets.size() == 0 && b.sets.size() == 0)
                    return 1;
            }
        }

        if (a.sets.size() == 0 && b.sets.size() == 0)
            return 1;

    }

    return 0;

}

Set& Set::operator*(Set& other)
{
    Set* res = new Set();

    list<char>::iterator it1, it2, buf1;

    Set a = *this;
    Set b = other;

    int maxi = a.elements.size(), maxj = b.elements.size();
    int i, j;
    for (i = 0, it1 = a.elements.begin(); (i < maxi) && (it1 != a.elements.end()); ++i, ++it1)
    {
        for (j = 0, it2 = b.elements.begin(); (j < maxj) && it2 != b.elements.end(); ++j, ++it2)
        {
            if ((*it2) == (*it1))
            {
                maxi--;
                maxj--;
                res->elements.push_back(*it1);
                list<char>::iterator del = it1;
                buf1 = a.elements.end();
                ++it1;
                a.elements.erase(del);
                del = it2;
                ++it2;
                b.elements.erase(del);
                break;
            }
        }
        if (i == maxi)
        {
            break;
        }
    }

    list<Set>::iterator it11, it22, buf;

    maxi = a.sets.size(), maxj = b.sets.size();
    for (i = 0, it11 = a.sets.begin(); (i < maxi) && (it11 != a.sets.end()); ++i, ++it11)
    {
        for (j = 0, it22 = b.sets.begin(); (j < maxj) && it22 != b.sets.end(); ++j, ++it22)
        {
            if ((*it22) == (*it11))
            {
                maxi--;
                maxj--;
                res->sets.push_back(*it11);
                list<Set>::iterator del = it11;
                buf = a.sets.end();
                ++it11;
                a.sets.erase(del);
                del = it22;
                ++it22;
                b.sets.erase(del);
                break;
            }
        }
        if (i == maxi)
        {
            break;
        }
    }


    return (*res);
}