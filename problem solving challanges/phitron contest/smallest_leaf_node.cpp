#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            tmp->left = new Node(l);
            q.push(tmp->left);
        }
        if (r != -1)
        {
            tmp->right = new Node(r);
            q.push(tmp->right);
        }
    }
    return root;
}

int Smallest_leaf_node(Node *root)
{
    if (!root->left && !root->right)
    {
        return root->val;
    }

    int leftSmallest = Smallest_leaf_node(root->left);
    int rightSmallest = Smallest_leaf_node(root->right);

    return min(leftSmallest, rightSmallest);
}

int main()
{
    Node *root = input_tree();
    int smallest = Smallest_leaf_node(root);

    cout << smallest;

    return 0;
}
