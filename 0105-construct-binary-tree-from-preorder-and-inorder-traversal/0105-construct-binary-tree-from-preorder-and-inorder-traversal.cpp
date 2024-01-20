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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pIdx = 0;
        TreeNode* root = recur_help(preorder, inorder, 0, preorder.size()-1);
        return root;
    }
private:
    int pIdx;
    TreeNode* recur_help(vector<int>& preorder, vector<int>& inorder, int lb, int ub){
        if (lb>ub){
            return nullptr;
        }
        int iIdx;
        TreeNode * root = new TreeNode(preorder[pIdx]);
        for (int i=0; i<inorder.size();i++){
            if(preorder[pIdx]==inorder[i]){
                iIdx = i;
                cout<<"\niIdx: "<<iIdx;
                break;
            }
        }
        cout<<"\npreorder[pIdx]: "<<preorder[pIdx];
        pIdx++;
        root->left = recur_help(preorder, inorder, lb, iIdx-1);
        root->right = recur_help(preorder, inorder, iIdx+1, ub);

        return root;
    }
};