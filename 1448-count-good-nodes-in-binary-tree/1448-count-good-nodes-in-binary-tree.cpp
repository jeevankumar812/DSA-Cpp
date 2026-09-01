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
    int goodNodes(TreeNode* root) {
        

        if(!root)
        return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});

        int c=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();

                TreeNode*currNode=curr.first;
                int cnt=curr.second;

                if(currNode->val>=cnt)
                {
                    c++;
                }

                if(currNode->left)
                {
                    if(currNode->left->val <cnt)
                    {
                        q.push({currNode->left,cnt});
                    }
                    else
                    {
                        q.push({currNode->left,currNode->left->val});
                    }
                }

                if(currNode->right)
                {
                    if(currNode->right->val<cnt)
                    {
                        q.push({currNode->right,cnt});
                    }
                    else
                    {
                        q.push({currNode->right,currNode->right->val});
                    }
                }
            }
        }
        return c;
    }
};