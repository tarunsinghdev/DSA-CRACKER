Approach #1: Recursive Method

The recursive Approach is the straight forward and classical approach.

If the current node is not empty :
1. Traverse the left subtree
2. Traverse the right subtree
3.  Print the node

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
private:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        postorder(root -> left, nodes);
        postorder(root -> right, nodes);
        nodes.push_back(root -> val);
    }
};


Approach #2: Iterative Method.

The key to the solution lies in:

Use root to denote the current node under process;
Use stack to save nodes;
A node is added to the result list before pushing into the stack(DRL).
    
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> ans;
        stack<TreeNode*> stk;
        //Postorder(LRD) --> Reverse(DRL) --> DRL is similar to Preorder(DLR)
        while(root or !stk.empty()){
            while(root){
                ans.push_back(root->val);
                stk.push(root);
                root=root->right;
            }
            root= stk.top();
            stk.pop();
            root=root->left;
        }
        //Reverse(DRL)
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
