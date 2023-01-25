//Using recursion
//find max depth and push elements into ans in increasing order of depth
//Time Complexity -> O(n)
//Memory Complexity -> O(n)

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
    int s;
    int maxDepth(TreeNode* node)
    {
        if (node == NULL) return 0;
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        return 1+max(lDepth , rDepth);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        s = maxDepth(root);
        vector<vector<int>> ans(s);
        cout<<s;
        level(root,0,ans);
        return ans;
    }
    void level(TreeNode* root ,int l, vector<vector<int>> &ans){
        if(root == NULL) return;
        ans[l].push_back(root->val);
        level(root->left,l+1,ans);
        level(root->right,l+1,ans);
    }
};