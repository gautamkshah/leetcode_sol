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
    void solve(TreeNode* root, int k, int& counter, int& small){
        if(!root || counter>=k) return;

        solve(root->left, k, counter, small);

        counter++;

        if(counter==k){
           small = root->val;
           return;
        }

        solve(root->right, k, counter, small);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0, small=0;
        solve(root, k, counter, small);
        return small;
    }
};