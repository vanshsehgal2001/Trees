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

bool structurallyIdentical(TreeNode<int>* root1,TreeNode<int>* root2){
    if(root1->data!=root2->data || root1->children.size()!=root2->children.size()){
        return false;
    }
    bool ans=true;
    for(int i=0;i<root1->children.size();i++){
        bool temp=structurallyIdentical(root1->children[i],root2->children[i]);
        ans= ans && temp;
    }
    return ans;
}


int main()
{
    TreeNode<int> *root1=inputLevelWise();
    TreeNode<int> *root2=inputLevelWise();
    if(structurallyIdentical(root1,root2)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
