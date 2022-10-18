Problem Statement:

Given a Binary Tree, check if all leaves are at same level or not. 

Code:

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int data){
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int checkLevelLeafNode(Node* root){
	if (!root)
		return 1;

	queue<Node*> q;
	q.push(root);

	int result = INT_MAX;
	int level = 0;

	while (!q.empty()) {
		int size = q.size();
		level += 1;

		while(size > 0){
			Node* temp = q.front();
			q.pop();
		
			if (temp->left) {
				q.push(temp->left);

				if(!temp->left->right && !temp->left->left){

					if (result == INT_MAX)
						result = level;
	
					else if (result != level)
						return 0;				
				}
			}
			
			if (temp->right){
				q.push(temp->right);

				if (!temp->right->left && !temp->right->right)
					if (result == INT_MAX)
						result = level;
					else if(result != level)
						return 0;
					
			}
			size -= 1;
		}
	}
	
	return 1;
}

int main(){
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);

	int result = checkLevelLeafNode(root);
	if (result)
		cout << "All leaf nodes are at same level\n";
	else
		cout << "Leaf nodes not at same level\n";
	return 0;
}


Time Complexity : O(N)

