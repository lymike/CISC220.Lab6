/*
 * AVLTree.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Michael Ly
 */

#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

AVLTree::AVLTree(bool flag) {
	root = NULL;
	AVLflag = flag;
}

bool AVLTree::findWord(string s, NodeT* n) {
	if (n->word == s) {
		return true;
	}
	else if (n == NULL) {
		return false;
	}
	else if (n->word < s) {
		return findWord(s, n->left);
	}
	else if (n->word > s){
		return findWord(s, n->right);
	}
	else {
		return false;
	}
}

void AVLTree::addNode(string s, NodeT* r) {
	if (r == NULL) {
		NodeT* newNode = new NodeT(s);
		root = newNode;
	}
	else if (r->word > s) {
		if (r->left != NULL) {
			addNode(s, r->left);
		}
		else {
			NodeT* newNode = new NodeT(s);
			r->left = newNode;
			newNode->parent = r;
		}
	}
	else if (r->word < s) {
		if (r->right != NULL) {
			addNode(s, r->right);
		}
		else {
			NodeT* newNode = new NodeT(s);
			r->right = newNode;
			newNode->parent = r;
		}
	}
	else {
		cout << "Node is already in the tree." << endl;
	}
}

void AVLTree::printIO(NodeT* root) {
	if (root == NULL) {
		return;
	}
	else {
		printIO(root->left);
		cout << root->height << ": " << root->word << endl;
		printIO(root->right);
	}
}

void AVLTree::printPre(NodeT* root) {
	if (root == NULL) {
		return;
	}
	else {
		cout << root->height << ": " << root->word << endl;
		printPre(root->left);
		printPre(root->right);
	}
}

void AVLTree::printPost(NodeT* root) {
	if (root == NULL) {
		return;
	}
	else {
		printPost(root->left);
		printPost(root->right);
		cout << root->height << ": " << root->word << endl;
	}
}

void AVLTree::adjustHeights(NodeT* n) {

}

int AVLTree::getMax(NodeT* n) {
	if (n->left==NULL && n->right==NULL) {
		return 0;
	}
	else {
		int lMax, rMax;
		if (n->left == NULL) {
			lMax = 0;
		}
		else {
			lMax = 1 + getMax(n->left);
		}
		if (n->right == NULL) {
			rMax = 0;
		}
		else {
			rMax = 1 + getMax(n->right);
		}
		if (lMax <= rMax) {
			return lMax;
		}
		else {
			return rMax;
		}
	}
}

NodeT* AVLTree::rotateRight(NodeT* n) {
	return NULL;
}

NodeT* AVLTree::rotateLeft(NodeT* n) {
	return NULL;
}

int AVLTree::getDiff(NodeT* n) {
	return getMax(n->left) - getMax(n->right);
}
