#include <iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>

class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data){
        this->data=data;
    }
};

TreeNode<int>* inputLevelWise(){
    int rootdata;
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* front=q.front();
        q.pop();
        int num;
        cout<<"Enter no of children of "<<front->data<<" ";
        cin>>num;
        for(int i=0;i<num;i++){
            int data;
            cout<<"Enter the data of "<<i<<" child";
            cin>>data;
            TreeNode<int>* child=new TreeNode<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

int maxVal(TreeNode<int>* root){
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans=max(ans,maxVal(root->children[i]));
    }
    return ans;
}

TreeNode<int>* justSmallerThanN(TreeNode<int>* root,int n){
    TreeNode<int>* ans=NULL;
    if(root->data<n){
        ans=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp=justSmallerThanN(root->children[i],n);
        if(ans==NULL){
            ans=temp;
        }
        if(temp!=NULL && temp->data>ans->data){
            ans=temp;
        }
    }
    return ans;
}

TreeNode<int>* secondLargest(TreeNode<int>* root){
    int maxNode=maxVal(root);
    return justSmallerThanN(root,maxNode);
}


int main()
{
    TreeNode<int> *root=inputLevelWise();
    cout<<secondLargest(root)->data;
    return 0;
}
