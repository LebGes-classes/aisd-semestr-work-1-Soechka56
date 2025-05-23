#pragma once

#include <vector>

using namespace std;

struct FenvickNode {
	int value;
	int index;
	std::vector<FenvickNode*> children; // для случая, если по формуле (которая ищет родителя) у отца может быть более чем два ребенка
	FenvickNode* parent;

	FenvickNode(int i) {
		index = i;
		value = 0;
		parent = nullptr;
	}
};