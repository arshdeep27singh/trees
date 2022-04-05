class Solution
{

private:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // code here
        if (node == NULL)
            return 0;

        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if (root == NULL)
            return true;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if (left && right && diff)
            return 1;

        return false;
    }
};