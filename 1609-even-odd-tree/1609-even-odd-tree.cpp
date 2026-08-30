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
    bool isEvenOddTree(TreeNode* root) {
        int lvl=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int prev=-1;
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();


                if(lvl%2==0)
                {
                    if(curr->val%2==0)
                    return false;

                    if(prev!=-1 && curr->val<=prev)
                    {
                        return false;
                    }
                }
                
                else
                {
                    if(curr->val%2!=0)
                    return false;

                    if(prev!=-1 && curr->val>=prev)
                    return false;

                }

                if(curr->left)
                {
                    q.push(curr->left);
                }
                
                if(curr->right)
                {
                    q.push(curr->right);
                }

                prev=curr->val;
            }
            lvl++;
        }
        return true;
    }
};