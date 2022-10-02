#include<bits/stdc++.h>
using namespace std;



class Node{
	public:
	int data;
	Node * left;
	Node * right;
};



// create Node 
Node* createNode(int val){
	Node * temp = new Node;
	if(!temp){
		cout<<"Error\n";
		return NULL;
	}
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// build the tree from array 
Node * buildtree(vector<int>&arr){
	if(arr.empty()){
		return NULL;
	}
	Node * root = createNode(arr[0]);
	queue<Node*>q;
	q.push(root);
	int i = 1;
	while(!q.empty() && i < arr.size()){
		Node * temp = q.front();
		q.pop();
	  int val = arr[i];
	  if(val != 0){
	  	temp->left = createNode(val);
	  	q.push(temp->left);
	  }
	  i++;
	  if(i>=arr.size()){
	  	break;
	  }
	  val = arr[i];
	   if(val != 0){
	  	temp->right = createNode(val);
	  	q.push(temp->right);
	  }
	  i++;
	}
	return root;
}



vector<int>ans;
    void helper(Node * root,int & prev ,int curr){
        if(root == NULL){
            return;
        }
      if(prev < curr){
        prev = curr;
          ans.push_back(root->data);
      }
        helper(root->right,prev,curr+1);
        helper(root->left,prev,curr+1);
        return ;
        
   }
    
    
void rightSideView(Node* root) {
        int prev = 0;
        int curr = 1;
        helper(root,prev,curr);
        for(auto x : ans){
        	cout<<x<<" ";
		}
}

int main(){


 int testcase;
     cin>>testcase;
     while(testcase--){
     	int size ;
     	cin>>size;
     	vector<int>arr;
     	for(int i = 0;i<size;i++){
     		int val;
     		cin>>val;
     		arr.push_back(val);
		 }
		 Node * root = buildtree(arr);
		 rightSideView(root);
	 }
	return 0;
}
