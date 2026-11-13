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
    int inorder(TreeNode* node, int& cnt, int& k) {
        if(node == nullptr) return -1;
        int left = inorder(node->left, cnt, k);
        if(left>-1) return left;
        cnt++;
        if(cnt == k) return node->val;
        int right = inorder(node->right, cnt, k);
        if(right>-1) return right;
        return -1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return inorder(root, cnt, k);
    }
};
