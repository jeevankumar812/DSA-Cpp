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

    int solve(TreeNode*root)
    {
         if (root == NULL)
        return 0;

        return 1 + max(solve(root->left), solve(root->right));
    }

    int deepestLeavesSum(TreeNode* root) {
        int level=solve(root);

        int lvl=1;
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();

                if(lvl==level)
                {
                    sum+=curr->val;
                }
                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }
            }

            lvl++;
        }

        return sum;
    }
};