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
    int idx=0;
    TreeNode* solve(vector<int> & pre,int low,int high){
        if(idx==pre.size() || pre[idx]<low || pre[idx]>high) return NULL;
        TreeNode * node=new TreeNode(pre[idx++]);
        node->left=solve(pre,low,node->val);
        node->right=solve(pre,node->val,high);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return solve(pre,INT_MIN,INT_MAX);
    }
};