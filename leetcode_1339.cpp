//calculate total value sum of every subtree
//Time Complexity -> O(n)
//Memory Complexity -> O(1)


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
    long maxsum = 0;
    long maxprod = 0;

    long dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return root->val + dfs(root->left) + dfs(root->right);
    }

    long fun(TreeNode* root)
    {
        if(root == nullptr) return 0;
        long temp = root->val + fun(root->left) + fun(root->right);
        maxprod = max(maxprod , (maxsum-temp)*(temp));
        return temp;
    }

    int maxProduct(TreeNode* root)
    {
        maxsum = dfs(root);
        long k = fun(root);
        long t = 1e9+7;
        return (int)(maxprod%t);
    }
};