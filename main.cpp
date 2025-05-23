#include "FenvickTree.h"
#include <iostream>
using namespace std;

int main() {
    FenvickTree array(6);

    array.update(0, 1);
    array.update(1, 3);
    array.update(2, 5);
    array.update(3, 7);
    array.update(4, 9);
    array.update(5, 11);
    //C++98 on mac do not supported {}, hardcode!

    cout << "сумма: " << array.query(2) << endl;
    cout << "сумма: " << array.rangeQuery(2, 4) << endl;

    array.update(3, 2);
    cout << "сумма: " << array.query(5) << endl; // 1+3+5+9+9+11 = 38

    return 0;
}