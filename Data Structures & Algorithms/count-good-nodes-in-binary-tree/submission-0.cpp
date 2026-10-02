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
    int count = 0;
    int isgood(TreeNode* root, int maxi=INT_MIN, int count = 0){
        if(!root)return count;
        if(root->val >= maxi){
            maxi = root->val;
            count++;
        }
        count = isgood(root->left, maxi,count);
        count = isgood(root->right, maxi, count);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return isgood(root);
    }
};
