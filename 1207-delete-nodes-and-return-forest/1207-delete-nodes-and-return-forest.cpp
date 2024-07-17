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
    void help(TreeNode* &root, vector<int>& t, vector<TreeNode*> & ans){
        if(root==NULL) return;
        if(find(t.begin(), t.end(), root->val) != t.end()){
            help(root->left, t, ans);
            if(root->left && find(t.begin(), t.end(), root->left->val)==t.end()){
                ans.push_back(root->left);
            }
            help(root->right, t, ans);
            if(root->right && find(t.begin(), t.end(), root->right->val)==t.end()){
                ans.push_back(root->right);
            }
            root = NULL;
            
            return;
        }

        help(root->left, t, ans);
        help(root->right, t, ans);   
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& t) {
        vector<TreeNode*> ans;
        if(root!=NULL && find(t.begin(),t.end(),root->val) == t.end()) ans.push_back(root);
        help(root, t, ans);
        return ans;
    }
};