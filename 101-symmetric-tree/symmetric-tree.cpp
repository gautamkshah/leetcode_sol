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
    bool solve(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL) return true;
        if(node1==NULL || node2==NULL) return false;

        return (node1->val == node2->val && solve(node1->left, node2->right) && solve(node1->right, node2->left) );
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};