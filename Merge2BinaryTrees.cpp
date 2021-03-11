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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        //IF NEW TREE IS MADE
        
        // if(root1 && root2){
        //     TreeNode* newNode=new TreeNode(root1->val+root2->val);
        //     newNode->left=mergeTrees(root1->left,root2->left);
        //     newNode->right=mergeTrees(root1->right,root2->right);
        //     return newNode;
        // }else{
        //     return root1 ? root1 : root2;
        // }
        
        //NO NEW TREE IS MADE JUST CHANGES ARE MADE TO THE FIRST TREE
        
        // if(root1 && root2){
        //     root1->val+=root2->val;
        //     root1->left=mergeTrees(root1->left,root2->left);
        //     root1->right=mergeTrees(root1->right,root2->right);
        //     return root1;
        // }
        // else{
        //     return root1?root1:root2;
        // }
        
        //ITERATIVE APPROACH BFS
        
        if(root1==NULL && root2==NULL){
            return NULL;
        }
        if(root1==NULL || root2==NULL){
            return root1 ? root1 : root2;
        }
        queue<TreeNode*> q1,q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            TreeNode* f1=q1.front();
            TreeNode* f2=q2.front();
            q1.pop();
            q2.pop();
            f1->val+=f2->val;
            if(!f1->left && f2->left){
                f1->left=f2->left;
            }
            else if(f1->left && f2->left){
                q1.push(f1->left);
                q2.push(f2->left);
            }
            if(!f1->right && f2->right){
                f1->right=f2->right;
            }
            else if(f1->right && f2->right){
                q1.push(f1->right);
                q2.push(f2->right);
            }
        }
        return root1;
    }
};
