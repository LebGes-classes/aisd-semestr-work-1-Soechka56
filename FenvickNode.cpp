#include "FenvickNode.h"
/*
1)по большей части реализацию фенвика прин€то делать через массив
2)дл€ разнообрази€ буду использовать "ноды" дл€ хранени€ формировани€ подпоследовательности
3)и большей гибкости кода
*/

#include <vector>
using namespace std;

struct FenvickNode {
    int value;
    int index;
    vector<FenvickNode*> children;
    FenvickNode* parent;

    FenvickNode(int i) : value(0), index(i), parent(nullptr) {}
};
