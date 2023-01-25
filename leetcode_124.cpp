//Using recursion
//For every node, find the maxpathsum of with that node as an end point
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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        leaf(root);
        return ans;
    }
    int leaf(TreeNode* root)
    {
        if(root == NULL) return 0;
        int l = max(leaf(root->left),0);
        int r = max(leaf(root->right),0);
        ans = max(ans,l+r+root->val);
        return root->val+max(l,r);
    }
};