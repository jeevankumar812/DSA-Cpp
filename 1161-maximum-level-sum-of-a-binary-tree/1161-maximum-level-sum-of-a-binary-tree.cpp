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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*>q;
        int lvl=1;
        q.push(root);
        int maxi=INT_MIN;
        int ans=1;
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();

                sum+=curr->val; 

                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }
            }

             if(sum>maxi)
                {
                    maxi=sum;
                    ans=lvl;
                }  

            lvl++;
        }
        return ans;
    }
};