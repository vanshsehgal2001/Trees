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
    
    static void helper(TreeNode* root,vector<string>& arr,string s){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            arr.push_back(s+to_string(root->val));
            return;
        }
        helper(root->left,arr,s+to_string(root->val));
        helper(root->right,arr,s+to_string(root->val));
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<string> arr;
        string s="";
        helper(root,arr,s);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            string temp=arr[i];
            int n=temp.size();
            int sum=0;
            for(int j=0;j<temp.size();j++){
                if(temp[j]=='0'){
                    n--;
                    continue;
                }
                sum= sum + pow(2,n-1);
                n--;
            }
            ans+=sum;
        }
        return ans;
    }
    
//     static int helper(TreeNode* root,int ans){
//         if(root==NULL){
//             return 0;
//         }
//         ans= 2*ans + root->val;
//         if(root->left==NULL && root->right==NULL){
//             return ans;
//         }
//         return helper(root->left,ans) + helper(root->right,ans);
//     }
    
//     int sumRootToLeaf(TreeNode* root) {
//         int ans=0;
//         return helper(root,ans);
//     }
};
