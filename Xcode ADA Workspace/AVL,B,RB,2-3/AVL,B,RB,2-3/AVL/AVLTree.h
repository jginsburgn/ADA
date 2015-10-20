#ifndef AVLTree_h
#define AVLTree_h

#include <algorithm>
#include "BinaryTree.h"

template <class T>
class AVLTree : public BinaryTree<T> {
private:
	void balance(BNode<T>* n, BNode<T>* p);
	void balanceRemove(BNode<T>* n, BNode<T>* p, int side);
	void rotateLeft(BNode<T>* node);
	void rotateRight(BNode<T>* node);
	int calculateFactor(BNode<T>* node);
	BNode<T>* findPredecessor(BNode<T>* node);
	int destroy(BNode<T>* node);
	int connectChild(BNode<T>* node);
	void printDesc(BNode<T>* node);
public:
	void insert(BNode<T>* node, BNode<T>* parent, T value);
	void remove(BNode<T>* node);
	int height(BNode<T>* node);
	BNode<T>* search(BNode<T>* node, T value);
	void printAsc();
	void printDesc();
	int depth(BNode<T>* node);
	int level(BNode<T>* node);
	bool isAVL(BNode<T>* node, bool result = true);
};

template <class T>
void AVLTree<T>::insert(BNode<T>* node, BNode<T>* parent, T value) {	
	if (!node && !parent) {
		BNode<T> * n = new BNode<T>(value);	
		this->setRoot(n);
		return;
	}

	else if (!node) {
		node = new BNode<T>(value);
		node->setParent(parent);
		if (parent->getInfo() > value)
			parent->setLeft(node);
		else
			parent->setRight(node);
		
		balance(node, parent);
		return;
	}

	else if (node->getInfo() > value)
		insert(node->getLeft(), node, value);
	else 
		insert(node->getRight(), node, value);
}

template <class T>
void AVLTree<T>::balance(BNode<T>* n, BNode<T>* p) {
	do {
		if (n == p->getLeft()) {
			if (p->getFactor() == -1) {
				p->setFactor(-2);
				if (n->getFactor() == 1)
					rotateLeft(n);
				rotateRight(p);
				break;
			}
			if (p->getFactor() == 1) {
				p->setFactor(0);
				break;
			}
			p->setFactor(-1);
		}

		else {
			if (p->getFactor() == 1) {
				p->setFactor(2);
				if (n->getFactor() == -1)
					rotateRight(n);
				rotateLeft(p);
				break;
			}
			if (p->getFactor() == -1) {
				p->setFactor(0);
				break;
			}
			p->setFactor(1);
		}
		
		n = p;
		p = n->getParent();
	} while (p);
}

template <class T>
void AVLTree<T>::rotateLeft(BNode<T>* node) {
	BNode<T>* pivot = node->getRight();
	BNode<T>* left = pivot->getLeft();
	BNode<T>* parent = node->getParent();
	pivot->setLeft(node);
	node->setParent(pivot);
	node->setRight(left);

	if (node == this->getRoot())
		this->setRoot(pivot);
	if (left)
		left->setParent(node);
	if (parent) {
		pivot->setParent(parent);
		if (parent->getLeft() == node)
			parent->setLeft(pivot);
		else
			parent->setRight(pivot);
	}
	else
		pivot->setParent(nullptr);

	node->setFactor(node->getFactor() - 1 - std::max(pivot->getFactor(), 0));
	pivot->setFactor(pivot->getFactor() - 1 + std::min(node->getFactor(), 0));
}

template <class T>
void AVLTree<T>::rotateRight(BNode<T>* node) {
	BNode<T>* pivot = node->getLeft();
	BNode<T>* right = pivot->getRight();
	BNode<T>* parent = node->getParent();
	pivot->setRight(node);
	node->setParent(pivot);
	node->setLeft(right);

	if (node == this->getRoot())
		this->setRoot(pivot);
	if (right)
		right->setParent(node);
	if (parent) {
		pivot->setParent(parent);
		if (parent->getLeft() == node)
			parent->setLeft(pivot);
		else
			parent->setRight(pivot);
	}
	else
		pivot->setParent(nullptr);
	
	node->setFactor(node->getFactor() + 1 - std::min(pivot->getFactor(), 0));
	pivot->setFactor(pivot->getFactor() + 1 + std::max(node->getFactor(), 0));
}

template <class T>
void AVLTree<T>::remove(BNode<T>* node) {
	int side = 0;
	BNode<T>* parent = node->getParent();
	if (!node->getLeft() && !node->getRight())
		side = destroy(node);
	else if (node->getLeft() && node->getRight()) {
		BNode<T>* predecessor = findPredecessor(node);
		parent = predecessor->getParent();
		node->setInfo(predecessor->getInfo());
		if (predecessor->getLeft()) {
			node->setLeft(predecessor->getLeft());
			predecessor->getLeft()->setParent(node);
			node->setFactor(node->getFactor() + 1);
		}
		side = destroy(predecessor);
	}
	else
		side = connectChild(node);

	if (parent)
		balanceRemove(nullptr, parent, side);
}

template <class T>
void AVLTree<T>::balanceRemove(BNode<T>* n, BNode<T>* p, int side) {
	int i = 1;	
	do {
		if ((n == p->getLeft() && i > 1) || side == -1) {
			side = 0;
			if (p->getFactor() == 1) {
				//std::cout << "lolz";
				p->setFactor(2);
				BNode<T>* s = p->getRight();
				if (s->getFactor() == -1)
					rotateRight(s);
				rotateLeft(p);
				if (s->getFactor() == 0)
					break;
			}
			if (p->getFactor() == 0) {
				p->setFactor(1);
				break;
			}
			p->setFactor(0);
		}

		else if ((n == p->getLeft() && i > 1) || side == 1) {
			side = 0;
			if (p->getFactor() == -1) {
				p->setFactor(-2);
				BNode<T>* s = p->getLeft();
				if (s->getFactor() == 1)
					rotateLeft(s);
				rotateRight(p);
				if (s->getFactor() == 0)
					break;
			}
			if (p->getFactor() == 0) {
				p->setFactor(-1);
				break;
			}
			p->setFactor(0);
		}
		
		n = p;
		p = n->getParent();
		++i;
	} while(p);
}

template <class T>
BNode<T>* AVLTree<T>::findPredecessor(BNode<T>* node) {
	BNode<T>* p = node->getLeft();
	while (p->getRight())
		p = p->getRight();	
	return p;
}

template <class T>
int AVLTree<T>::connectChild(BNode<T>* node) {
	int side = 0;	
	BNode<T>* child = node->getLeft();
	if (!child)
		child = node->getRight();

	BNode<T>* parent = node->getParent();
	child->setParent(parent);
	if (parent) {
        if (parent->getLeft() == node) {
			parent->setLeft(child);
			side = -1;
		}
		else {
			parent->setRight(child);
			side = 1;
		}
    }
	else
		this->setRoot(child);
	delete node;
	return side;
}

template <class T>
int AVLTree<T>::destroy(BNode<T>* node) {
	int side = 0;
	BNode<T>* parent = node->getParent();
	if (parent) {
        if (parent->getLeft() == node) {
			parent->setLeft(nullptr);
			side = -1;
		}
		else if (parent->getRight() == node) {
			parent->setRight(nullptr);
			side = 1;
		}
    }
	else
		this->setRoot(nullptr);
	delete node;
	return side;
}

template <class T>
BNode<T>* AVLTree<T>::search(BNode<T>* node, T value) {
	if (!node)
		return nullptr;	
	if (node->getInfo() == value)
		return node;
	else if (node->getInfo() > value)
		search(node->getLeft(), value);
	else
		search(node->getRight(), value);
}

template <class T>
int AVLTree<T>::height(BNode<T>* node) {
	if (!node)
		return -1;
	else
		return std::max(height(node->getLeft()), height(node->getRight())) + 1;
}

template <class T>
void AVLTree<T>::printAsc() {
	this->inOrder();
	std::cout << std::endl;
}

template <class T>
void AVLTree<T>::printDesc() {
	printDesc(this->getRoot());
	std::cout << std::endl;
}

template <class T>
void AVLTree<T>::printDesc(BNode<T>* node) {
	if (node) {
        printDesc(node->getRight());
        std::cout << *node << " ";
        printDesc(node->getLeft());
    }
}

template <class T>
int AVLTree<T>::depth(BNode<T>* node) {
	if (!node->getParent())
		return 0;
	return depth(node->getParent()) + 1;
}

template <class T>
int AVLTree<T>::level(BNode<T>* node) {
	return depth(node) + 1;
}

template <class T>
bool AVLTree<T>::isAVL(BNode<T>* node, bool result) {
	if (node) {	
		isAVL(node->getLeft(), result);
		isAVL(node->getRight(), result);	
		int factor = calculateFactor(node);
		if (!(factor <= 1 && factor >= -1))
			result = false;
		if (node == this->getRoot())
			return result;
	}
}

template <class T>
int AVLTree<T>::calculateFactor(BNode<T>* node) {
	if (node->getLeft() && node->getRight())
		return height(node->getRight()) - height(node->getLeft());
	else if (node->getLeft())
		return -(height(node->getLeft()));
	else if (node->getRight())
		return height(node->getRight());
	else
		return 0;
}

#endif
