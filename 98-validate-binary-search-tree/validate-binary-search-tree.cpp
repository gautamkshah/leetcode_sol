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
    bool solve(long high ,long low,TreeNode* root){

        if(root==NULL) return true;
        if(root->val<=low || root->val>=high) return false;
        return solve(high,root->val,root->right) && solve(root->val,low,root->left);
    }
    bool isValidBST(TreeNode* root) {
       return solve(LONG_MAX,LONG_MIN, root); 
    }
};