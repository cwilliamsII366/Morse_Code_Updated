#include "Node.h"


	TreeNode::Node* TreeNode::createNode(string data [])
	{	Node* node = new Node();
		node->data[0] = data[0];
		node->data[1] = data[1];
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	TreeNode::Node* TreeNode::addNode(Node* root, string code, string data []){
		if (code.length() == 1) {
			if (code[0] == '.') {
				root->left = createNode(data);
			}
			else {
				root->right = createNode(data);
			}
		}
		else if (code.length() > 1) {
			if (code[0] == '.') {
				root->left = addNode(root->left, code.substr(1), data);
			}
			else {
				root->right = addNode(root->right, code.substr(1), data);
			}
		}
		return root;
	}


	string TreeNode::retrieveChar(Node* root, string code, string result)
	{
		if (code.length() == 1) {
			if (code[0] == '.') {
				return root->left->data[1];
			}
			else {
				return root->right->data[1];
			}
		}
		else if (code.length() > 1) {
			if (code[0] == '.') {
				result = retrieveChar(root->left, code.substr(1),result);
				
			}
			else {
			   result = retrieveChar(root->right, code.substr(1), result);
			}
		}
		return result;
	}

	string TreeNode::retrieveMorse(Node* root, string result, string letter) {
		if (!root) {
			return result;
		}
		else if (root->data[1] == letter) {
			return root->data[0];
		} 
	
		if (root->left) {
			result = retrieveMorse(root->left, result, letter);
		}
		if (root->right) {
			result = retrieveMorse(root->right, result, letter);
		}
		return result;
	}

	

	

