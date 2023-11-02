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
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        check(root,cnt);
        return cnt;
    }
    vector<int>check(TreeNode*root,int&cnt)
    {
        if(!root)
        {
            return {0,0};
        }
        vector<int>lt=check(root->left,cnt);
        vector<int>rt=check(root->right,cnt);
        int totalsum=lt[0]+rt[0]+root->val;
        int nodes=lt[1]+rt[1]+1;
        int avg=totalsum/nodes;
        if(avg==root->val)
            cnt++;
        return {totalsum+root->val,nodes+1};
    }
};