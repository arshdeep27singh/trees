class Solution
{
private:
    // code here
    if (node == NULL)
        return 0;

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;

public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        if (node == NULL)
            return 0;

        int op1 = diameter(node->left);
        int op2 = diameter(node->right);
        int op3 = height(node->left) + height(node->right) + 1;

        int ans = max(op1, max(op2, op3));
        return ans;
    }
};

// the above solution will take O(n^2) time to execute

// we will solve the same problem in O(n) time using below approach

class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    // Your code here
    pair<int, int> diameterFast(Node *root)
    {

        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameter(Node *root)
    {
        return diameterFast(root).first;
    }
};