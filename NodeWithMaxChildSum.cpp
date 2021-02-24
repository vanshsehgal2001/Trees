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


TreeNode<int>* nodeWithMaxChildSum(TreeNode<int>* root){
    TreeNode<int>* ans=root;
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp=nodeWithMaxChildSum(root->children[i]);
        int ssum=temp->data;
        for(int j=0;j<temp->children.size();j++){
            ssum+=temp->children[j]->data;
        }
        if(ssum>sum){
            sum=ssum;
            ans=temp;
        }
    }
    return ans;
}


int main()
{
    TreeNode<int> *root=inputLevelWise();
    cout<<nodeWithMaxChildSum(root)->data;
    return 0;
}
