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
    int max_all = INT_MIN;

    int max_sum(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int sum_left = std::max(max_sum(root->left), 0);
        int sum_right = std::max(max_sum(root->right), 0);

        int all_max = root->val + sum_left + sum_right;
        max_all = std::max(max_all, all_max);

        return root->val + std::max(sum_left, sum_right);
    }

    int maxPathSum(TreeNode* root) {
        max_sum(root);
        return max_all;
    }
};