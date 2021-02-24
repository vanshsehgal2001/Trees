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

int NodesGreaterThanX(TreeNode<int>* root,int x){
    int ans=0;
    if(root->data>x){
        ans=1;
    } 
    for(int i=0;i<root->children.size();i++){
        ans+=NodesGreaterThanX(root->children[i],x);
    }
    return ans;
}


int main()
{
    TreeNode<int> *root=inputLevelWise();
    int x;
    cin>>x;
    cout<<NodesGreaterThanX(root,x);
    return 0;
}
