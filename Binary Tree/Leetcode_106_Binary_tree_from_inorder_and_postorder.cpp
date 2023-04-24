// Leetcode solution for the problem no. 106 which is Construct a binary tree from inorder and postorder travsersal 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int, int> pos;
        int n = post.size();
        for (int i = 0; i < n; i++) {
            pos[in[i]] = i;
        }
        TreeNode* root = NULL;
        for (int i = n - 1; i >= 0; i--) {
            int num = post[i], p = pos[num];
            //cout << num << ":" << p << endl;
            TreeNode* tr = new TreeNode(num);
            if (i == n - 1) {
                root = tr;
                continue;
            }
            TreeNode* node = root, *prev = NULL;
            while (node) {
                prev = node;
                if (pos[node->val] > p) node = node->left;
                else  node = node->right;
            }
            node = tr;
            if (pos[prev->val] > p) prev->left = tr;
            else    prev->right = tr;
        }
        return root;
    }
};
// This code is contributed by - Swapnil0803
