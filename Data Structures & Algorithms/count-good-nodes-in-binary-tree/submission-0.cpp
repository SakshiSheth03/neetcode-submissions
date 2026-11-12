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
private:
    void countGoodNodes(TreeNode* node, int& count, int maxAtThisStep) {
        if(node==nullptr) return;
        if(node->val>=maxAtThisStep) {
            count++;
            maxAtThisStep = node->val;
        }
        countGoodNodes(node->left, count, maxAtThisStep);
        countGoodNodes(node->right, count, maxAtThisStep);
    }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        if(root==nullptr) return count;
        countGoodNodes(root, count, root->val);
        return count;
    }
};
