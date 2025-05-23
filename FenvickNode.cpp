#include "FenvickNode.h"
/*
1)�� ������� ����� ���������� ������� ������� ������ ����� ������
2)��� ������������ ���� ������������ "����" ��� �������� ������������ ���������������������
3)� ������� �������� ����
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
