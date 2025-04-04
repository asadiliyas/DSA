/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root, int depth, int& maxDepth, TreeNode*& ans) {
        if (!root) {
            return depth-1;
        }

        maxDepth = max(maxDepth, depth);

        int leftDepth = find(root->left,depth+1,maxDepth,ans);
        int rightDepth = find(root->right,depth+1,maxDepth,ans);

        if(leftDepth==maxDepth && rightDepth==maxDepth){
            ans=root;
        }

        return max(leftDepth,rightDepth);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans = NULL;
        int maxDepth = -1;
        find(root, 0, maxDepth, ans);
        return ans;
    }
};
