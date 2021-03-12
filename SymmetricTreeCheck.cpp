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
#include<queue>
class Solution {
public:
    
        //RECURSIVE SOLUTION
    
//     static bool helper(TreeNode* l,TreeNode* r){
//         if(l==NULL || r==NULL){
//             return l==r;
//         }
//         if(l->val!=r->val){
//             return false;
//         }
//         return helper(l->left,r->right) && helper(l->right,r->left);
//     }
    
//     bool isSymmetric(TreeNode* root) {
//         if(root==NULL){
//             return true;
//         }
//         return helper(root->left,root->right);
//     }
    
    //ITERATIVE APPROACH USING QUEUES (BFS)
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            TreeNode* f1=q1.front();
            TreeNode* f2=q2.front();
            q1.pop();
            q2.pop();
            if(f1==NULL && f2==NULL){
                continue;
            }
            if(f1==NULL || f2==NULL){
                return false;
            }
            if(f1->val!=f2->val){
                return false;
            }
            q1.push(f1->left);
            q2.push(f2->right);
            q1.push(f1->right);
            q2.push(f2->left);
        }
        return true;
    }
};
