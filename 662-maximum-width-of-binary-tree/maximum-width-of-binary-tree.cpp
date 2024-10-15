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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        //try giving indexing on every level of binary tree
        // width = right-idx - left-idx + 1; 
        //indexing is done as left -> 2i+1 , right-> 2i+2;
        //to make sure 2*i should not overflow 
        //try to index from 0 to n at every level by taking the index i as min(i, min idx at that level)

        //level order traversal
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0}); //node, index
        long long width = 0;
        while(!q.empty()){
            long long sz = q.size();
            long long minidx = q.front().second; //minimum idx of every level 
            long long left_idx = -1, right_idx = -1; // to store the index of leftmost and rightmost node present
           

            for(int i=1; i<=sz; i++){
                TreeNode* curr = q.front().first;
                long long idx = q.front().second - minidx; // curridx - minminum idx of that level 
                q.pop();

                if(i==1) left_idx = idx; //first node
                if(i==sz) right_idx = idx; //last node

                if(curr->left) q.push({curr->left, idx*2+1}); //same formula 
                if(curr->right) q.push({curr->right, idx*2+2});
            }
            
            width = max(width, right_idx - left_idx + 1);
        }
        return width;
    }
};