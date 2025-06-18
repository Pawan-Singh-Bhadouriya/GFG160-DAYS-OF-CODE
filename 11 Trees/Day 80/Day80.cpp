#include <bits/stdc++.h>
using namespace std;
// Day 80 -Solution

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            level.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        res.push_back(level);
    }
    return res;
}