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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*>q;
        
        if(root1)
        {
            q.push(root1);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();

                ans.push_back(curr->val);
                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }

        if(root2)
        {
            q.push(root2);
        }


        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();

                ans.push_back(curr->val);

                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};