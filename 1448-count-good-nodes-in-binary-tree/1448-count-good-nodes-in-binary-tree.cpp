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
// const int MINNUM = -100000;

// class Solution {
// public:
//     int goodNodes(TreeNode* root) {
//         priority_queue<int> pq;
//         pq.push(MINNUM);
//         DFS(root, pq);
//         return count;
//     }
// private:
//     void DFS(TreeNode* Node, priority_queue<int> pq){
//         count++;
//         if(Node==nullptr){
//             count --;
//             return ;
//         }
//         if(Node->val < pq.top()){
//             count--;
//         }
//         pq.push(Node->val);
//         DFS(Node->left, pq);
//         DFS(Node->right, pq);        
//     }
//     int count;
// };

class Solution {
public:
    int goodNodes(TreeNode* root) {
        const int MINNUM = -100000;
        DFS(root, MINNUM);
        return count;
    }
private:
    void DFS(TreeNode* Node, int maxVal){
        count++;
        if(Node==nullptr){
            count --;
            return ;
        }
        if(Node->val < maxVal){
            count--;
        }
        maxVal = max(maxVal, Node->val);
        DFS(Node->left, maxVal);
        DFS(Node->right, maxVal);        
    }
    int count;
};