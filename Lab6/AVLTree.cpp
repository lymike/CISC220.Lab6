/*
 * AVLTree.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: Michael Ly
 */

#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

AVLTree::AVLTree(bool flag){
	root = NULL;
	AVLflag = flag;
}

bool AVLTree::findWord(string s, NodeT *n) {
	if (n == NULL) {
		return false;
	}
	else if (n->word == s) {
		return true;
	}
	else if (n->word > s) {
		return findWord(s, n->left);
	}
	else {
		return findWord(s, n->right);
	}
}

void AVLTree::addNode(string s, NodeT *r) {
	if (r == NULL) {
		cout << "Made root" << endl;
		NodeT* newNode = new NodeT(s);
		root = newNode;
	}
	else if (r->word > s) {
		if (r->left != NULL) {
			cout << "Looking left of " << r->word << endl;
			addNode(s, r->left);
		}
		else {
			cout << "Inserting to the left of " << r->word << endl;
			NodeT* newNode = new NodeT(s);
			r->left = newNode;
			newNode->parent = r;
			adjustHeights(newNode);
			cout << endl;
		}
	}
	else if (r->word < s) {
		if (r->right != NULL) {
			cout << "Looking right of " << r->word << endl;
			addNode(s, r->right);
		}
		else {
			cout << "Inserting to the right of " << r->word << endl;
			NodeT* newNode = new NodeT(s);
			r->right = newNode;
			newNode->parent = r;
			adjustHeights(newNode);
			cout << endl;
		}
	}
	else {
		cout << "Node is already in the tree." << endl;
	}
}

void AVLTree::printIO(NodeT *root) {
	if (root == NULL) {
		return;
	}
	printIO(root->left);
	cout << "|" << root->height << ":" << root->word << "|" << endl;
	printIO(root->right);
}

void AVLTree::printPre(NodeT *root) {
	if (root == NULL) {
		return;
	}
	cout << "|" << root->height << ":" << root->word << "|" << endl;
	printPre(root->left);
	printPre(root->right);
}

void AVLTree::printPost(NodeT *root) {
	if (root == NULL) {
		return;
	}
	printPost(root->left);
	printPost(root->right);
	cout << "|" << root->height << ":" << root->word << "|" << endl;
}

void AVLTree::adjustHeights(NodeT *n) {
	if (AVLflag == true) {
		n->height = getMax(n);
		int bal = getDiff(n);
		if (bal == 2){
			if (getDiff(n->left) == 1) {
				cout << "Rotating right around " << n->word << endl;
				rotateRight(n);
				adjustHeights(n);
			}
			else {
				cout << "Left-right rotation on " << n->word << endl;
				cout << "First rotating left around " << n->left->word << endl;
				rotateLeft(n->left);
				cout << "Rotating right around " << n->word << endl;
				rotateRight(n);
				adjustHeights(n);
			}
		}
		else if (bal == -2) {
			if (getDiff(n->right) == -1) {
				cout << "Rotating left around " << n->word << endl;
				rotateLeft(n);
				adjustHeights(n);
			}
			else {
				cout << "Right-left rotation on " << n->word << endl;
				cout << "First rotating right around " << n->right->word << endl;
				rotateRight(n->right);
				cout << "Rotating left around " << n->word << endl;
				rotateLeft(n);
				adjustHeights(n);
			}
		}
	}
	else {
		n->height = getMax(n);
	}
	if (n->parent != NULL) {
		adjustHeights(n->parent);
	}
}

int AVLTree::getMax(NodeT *n) {
	int lMax, rMax;
	if (n->left == NULL) {
		lMax = 1;
	}
	else {
		lMax = 1 + getMax(n->left);
	}
	if (n->right == NULL) {
		rMax = 1;
	}
	else {
		rMax = 1 + getMax(n->right);
	}
	if (lMax >= rMax) {
		return lMax;
	}
	else {
		return rMax;
	}
}

NodeT *AVLTree::rotateRight(NodeT *n) {
	NodeT *x = n->left;
	NodeT *tmp = x->right;
	cout << "Height of node before: " << n->word << ":" << n->height << endl;
	cout << "Height of left child before: " << x->word << ":" << x->height << endl;
	x->right = n;
	n->left = tmp;
	x->height = getMax(x);
	n->height = getMax(n);
	cout << "Height of " << n->word << " now " << n->height << endl;
	cout << "Height of " << x->word << " now " << x->height << endl;
	if (root->word == n->word) {
		root = x;
		cout << x->word << " is new root" << endl;
	}
	else if(n->parent->right!=NULL && n->parent->right->word==n->word) {
		cout << "Resetting " << n->parent->word << "'s right to " << x->word << endl;
		n->parent->right = x;
	}
	else {
		cout << "Resetting " << n->parent->word << "'s left to " << x->word << endl;
		n->parent->left = x;
	}
	x->parent = n->parent;
	n->parent = x;
	if(tmp != NULL) {
		tmp->parent = n;
		tmp->height = getMax(tmp);
	}
	return x;
}

NodeT *AVLTree::rotateLeft(NodeT *n) {
	NodeT *x = n->right;
	NodeT *tmp = x->left;
	cout << "Height of node before: " << n->word << ":" << n->height << endl;
	cout << "Height of left child before: " << x->word << ":" << x->height << endl;
	x->left = n;
	n->right = tmp;
	x->height = getMax(x);
	n->height = getMax(n);
	cout << "Height of " << n->word << " now " << n->height << endl;
	cout << "Height of " << x->word << " now " << x->height << endl;
	if (root->word == n->word) {
		root = x;
		cout << x->word << " is new root" << endl;
	}
	else if (n->parent->right != NULL && n->parent->right->word == n->word) {
		cout << "Resetting " << n->parent->word << "'s right to " << x->word << endl;
		n->parent->right = x;
	}
	else {
		cout << "Resetting " << n->parent->word << "'s left to " << x->word << endl;
		n->parent->left = x;
	}
	x->parent = n->parent;
	n->parent = x;
	if (tmp != NULL) {
		tmp->parent = n;
		tmp->height = getMax(tmp);
	}
	return x;
}

int AVLTree::getDiff(NodeT *n) {
	int lHeight, rHeight;
	if (n->left == NULL) {
		lHeight = 0;
	}
	else {
		lHeight = n->left->height;
	}

	if (n->right == NULL) {
		rHeight = 0;
	}
	else {
		rHeight = n->right->height;
	}
	return lHeight - rHeight;
}
