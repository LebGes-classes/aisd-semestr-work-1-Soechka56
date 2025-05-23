#include "FenvickTree.h"

FenvickTree::FenvickTree(int size) : size(size) {
	nodes.resize(size + 1, nullptr); // 1-based

	for (int i = 1; i <= size; i++)
		nodes[i] = new FenvickNode(i);

	for (int i = 1; i <= size; i++) {
		int p = i + (i & -i);
		if (p <= size) {
			nodes[i]->parent = nodes[p];
			nodes[p]->children.push_back(nodes[i]);
		}
	}
}

FenvickTree::~FenvickTree() {
	for (auto node : nodes)
		delete node;
}// vs studio предложила сама так память чистить :_)

void FenvickTree::update(int i, int d) {
	i++;
	if (i < 1 || i > size) {
		return;
	}

	FenvickNode* cur = nodes[i];
	while (cur != nullptr) {
		cur->value += d;
		cur = cur->parent;
	}
}

int FenvickTree::query(int i) {
	i++;
	if (i < 1 || i > size) {
		return 0;
	}

	int sum = 0;
	FenvickNode* cur = nodes[i];
	while (cur != nullptr) {
		sum += cur->value;
		int parentIdx = cur->index - (cur->index & -cur->index);

		if (parentIdx > 0) {
			cur = nodes[parentIdx];
		} else {
			cur = nullptr;
		}

	}
	return sum;
}
//удаление элемента предполагает создание дерева с 0 и не может быть описано как метод!
//+ в литературе такого метода у фенвика нет

int FenvickTree::rangeQuery(int l, int r) {
	if (l == 0) {
		return query(r);
	}
	else {
		return query(r) - query(l - 1);
	}
}