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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(!root)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int curr=INT_MIN;
            for(int i=0;i<n;i++)
            {
                TreeNode*currnode=q.front();
                q.pop();
                curr=max(curr,currnode->val);
                if(currnode->left)
                    q.push(currnode->left);
                if(currnode->right)
                    q.push(currnode->right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};