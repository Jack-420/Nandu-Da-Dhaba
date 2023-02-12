#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

class node{
    public:
    int data;
    int height;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left =NULL;
        this->right=NULL;
    }  
};

node* insertIntoBst(node* root, int data){
    if(root==NULL){
        root= new node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertIntoBst(root->right,data);
    } else {
        root->left=insertIntoBst(root->left,data);
    }
    return root;
}

void takeInput(node* &root){
    int data; cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<"\n";
            if(!q.empty())
            q.push(NULL);
        } else {
            cout<<temp->data<<" ";
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
    }
}

void inorderTraversal(node* root){
    if(root==NULL)
    return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root){
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root){
    if(root==NULL)
    return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

bool present(node* root, int data){
    if(root==NULL)
    return false;
    if(root->data==data)
    return true;
    if(root->data>data)
    return present(root->left,data);
    return present(root->right,data);    
}

bool present2(node* root, int data){
    node* temp=root;
    while(temp){
        if(temp->data==data)
        return true;
        else if(temp->data>data)
        temp=temp->left;
        else
        temp->right;
    }
    return false;
}

int smallest(node* root){
    if(root->left==NULL)
    return root->data;
    return smallest(root->left);
}

int smallest2(node* root){
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp->data;
}

int largest(node* root){
    if(root->right==NULL)
    return root->data;
    return smallest(root->right);
}

int largest2(node* root){
    node* temp=root;
    while(temp->right){
        temp=temp->right;
    }
    return temp->data;
}

node* deleteNode(node* root, int data){
    if(!root)
    return NULL;
    if(root->data==data){
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        } else if(root->left==NULL&&root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        } else if(root->left!=NULL&&root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        } else {
            int minval=smallest2(root->right);
            root->data=minval;
            root->right=deleteNode(root->right,minval);
            return root;
        }
    } else if(root->data>data){
        root->left=deleteNode(root->left,data);
        return root;
    } else {
        root->right=deleteNode(root->right,data);
        return root;
    }
}

bool isValidBST(node* root, int min, int max){
    if(root==NULL)
    return true;
    if(root->data<=max&&root->data>=min){
        bool left = isValidBST(root->left,min,root->data);
        bool right= isValidBST(root->right,root->data,max);
        return left&&right;
    } else {
        return false;
    }
}

int kthSmallElem(node* root, int k, int &cnt){
    if(root==NULL)
    return -1;
    int left=kthSmallElem(root->left,k,cnt);
    if(left!=-1)
    return left;
    cnt++;
    if(cnt==k)
    return root->data;
    return kthSmallElem(root->right,k,cnt);
}

pair<int,int> predOrSucc(node* root, int k){
    node* temp=root;
    int succ=-1,pred=-1;
    while(temp->data!=k){
        if(temp->data>k){
            succ=temp->data;
            temp=temp->left;
        } else {
            pred=temp->data;
            temp=temp->right;
        }
    }
    node* left=temp->left;
    while(left!=NULL){
        pred=left->data;
        left=left->right;
    }
    node* right=temp->right;
    while(right!=NULL){
        pred=right->data;
        right=right->left;
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    node* root=NULL;
    takeInput(root);
    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    cout<<endl;
    levelOrderTraversal(root);
}