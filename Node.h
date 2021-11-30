#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;
class TreeNode {

public:
	struct Node {
		Node* left, * right;
		string data [2];
	};

	Node* newNodeAppending() {
		Node* node = new Node();
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}

	Node* createNode(string data []);
	Node* addNode(Node* root, string code, string data []);
	string retrieveChar(Node* root, string code, string result);
	string retrieveMorse(Node* root, string result, string letter);
	//string retrieveNode(Node* root, string result, string letter);

};
