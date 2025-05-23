#ifndef FENVICKTREE_H
#define FENVICKTREE_H

#include "FenvickNode.h"
#include <vector>

using namespace std;

class FenvickTree {
public:
	FenvickTree(int size);
	~FenvickTree(); // как я понял - это обязательный деструктор, если я буду использовать new()

	void update(int i, int d); // d — data (новые данные)
	int query(int i);
	int rangeQuery(int l, int r);

private:
	vector<FenvickNode*> nodes;
	int size;
};

#endif // FENVICKTREE_H