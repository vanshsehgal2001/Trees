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

TreeNode<int> *inputRecur(){
    int rootdata,n;
    cin>>rootdata;
    TreeNode<int>* root=new TreeNode<int>(rootdata);
    cout<<"Enter num of children";
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* temp=inputRecur();
        root->children.push_back(temp);
    }
    return root;
}

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

void print(TreeNode<int>* root){
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}

int main()
{
    // TreeNode<int> *root=inputRecur();
    TreeNode<int> *root=inputLevelWise();
    print(root);
    return 0;
}
