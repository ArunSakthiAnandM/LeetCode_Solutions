//Keep track of min and max elements in a subtree
//Time Complexity -> O(n^2)
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
    int ret_min(TreeNode* root)
    {
        int ret = root->val;
        if(root->left != nullptr)
            ret = min(ret , ret_min(root->left));
        if(root->right != nullptr)
            ret = min(ret , ret_min(root->right));
        return ret;
    }
    int ret_max(TreeNode* root)
    {
        int ret = root->val;
        if(root->left != nullptr)
            ret = max(ret , ret_max(root->left));
        if(root->right != nullptr)
            ret = max(ret , ret_max(root->right));
        return ret;
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        if(root->left != nullptr)
        {
            ans = max(ans , maxAncestorDiff(root->left));
            ans = max(ans , abs(root->val - ret_min(root->left)));
            ans = max(ans , abs(root->val - ret_max(root->left)));
        }
        if(root->right != nullptr)
        {
            ans = max(ans , maxAncestorDiff(root->right));
            ans = max(ans , abs(root->val - ret_min(root->right)));
            ans = max(ans , abs(root->val - ret_max(root->right)));
        }
        return ans;
    }
};