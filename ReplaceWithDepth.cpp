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

void replaceWithDepth(TreeNode<int>* root,int depth){
    root->data=depth;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepth(root->children[i],depth+1);
    }
}

void print(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    q.push(root);
    cout<<root->data<<endl;
    while(!q.empty()){
        TreeNode<int>* front=q.front();
        q.pop();
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<" ";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}


int main()
{
    TreeNode<int> *root=inputLevelWise();
    replaceWithDepth(root,0);
    print(root);
    return 0;
}
