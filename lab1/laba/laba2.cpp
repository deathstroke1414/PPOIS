#include <iostream>
#include "Set.h"
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    Set set1, set2;

    set1.add('A');
    set1.add('B');
    set1.add('C');

    set2.add('B');
    set2.add('C');
    set2.add('D');

    Set unionSet = set1 + set2;
    Set intersectionSet = set1 * set2;

    cout << "Set 1: " << set1.toString() << endl;
    cout << "Set 2: " << set2.toString() << endl;
    cout << "Union Set: " << unionSet.toString() << endl;
    cout << "Intersection Set: " << intersectionSet.toString() << endl;

    return 0;

}

