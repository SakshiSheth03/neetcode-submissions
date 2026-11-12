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
    void rightSideArr(TreeNode* node, int level, vector<int>& arr) {
        if(node==nullptr) return;
        if(level==arr.size()) arr.push_back(node->val);
        rightSideArr(node->right, level+1, arr);
        rightSideArr(node->left, level+1, arr);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {};
        int level=0;
        vector<int> arr;
        rightSideArr(root, level, arr);
        return arr;
    }
};
