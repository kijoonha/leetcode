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
    TreeNode* invertTree(TreeNode* root) {
        Dfs(root);
        return root;
    }
private:
    void Swap(TreeNode* Node){
        TreeNode* temp = Node->left;
        Node->left = Node->right;
        Node->right = temp;
    }
    void Dfs(TreeNode * Node){
        if(Node ==nullptr){
            return ;
        }
        Swap(Node);
        Dfs(Node->left);
        Dfs(Node->right);
    }
};