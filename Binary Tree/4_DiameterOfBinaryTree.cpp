// Solution for finding the diameter of a binary tree on GFG
// Solution Author : Vishvesh Trivedi (@NerdyVisky)
// Problem link : https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return (max(height(root->left), height(root->right))) + 1;
        }
    }
    int diameter(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int dia_root = 1 + height(root->left) + height(root->right);
        int dia_left = diameter(root->left);
        int dia_right = diameter(root->right);
        return (max(dia_root, max(dia_left, dia_right)));
    }
};

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}