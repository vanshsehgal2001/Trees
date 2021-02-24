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

TreeNode<int>* justLargerThanN(TreeNode<int>* root,int n){
    TreeNode<int>* ans=NULL;
    if(root->data>n){
        ans=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp=justLargerThanN(root->children[i],n);
        if(ans==NULL){
            ans=temp;
        }
        if(temp!=NULL && temp->data<ans->data){
            ans=temp;
        }
    }
    return ans;
}


int main()
{
    TreeNode<int> *root=inputLevelWise();
    int n;
    cin>>n;
    cout<<justLargerThanN(root,n)->data;
    return 0;
}
