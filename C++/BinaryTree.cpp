,.
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class node {
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left =NULL;
        this->right=NULL;
    }  
};

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first<=b.first;
}

node* buildTree(node* root){
    int data; 
    cin>>data;
    root=new node(data);
    if(data==-1)
    return NULL;
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
}

node* buildTree2(node* root){
    int data; cin>>data;
    root=new node(data);
    if(data==-1)
    return NULL;
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);
    return root;
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
// left data right
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

bool find(node* root, int d){
    if(root==NULL)
        return false;

    if(root->data==d){
        return true;
    } else if(root->data<d){ 
        find(root->right,d);
    } else {
        find(root->left,d);
    }
}

void buildLevelOrder(node* root){
    queue<node*> q;
    cout<<"Enter data for root: \n";
    int data; cin>>data;
    root=new node(data);
    q.push(root);
    while (!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter left data for "<<temp->data<<" :";
        int leftData; cin>>leftData;
        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right data for "<<temp->data<<" :";
        int rightData; cin>>rightData;
        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

int maxHeight(node* root){
    if(root==NULL)
    return 0;
    if(root->left==NULL&&root->right==NULL)
    return 1;
    int maxi =max(maxHeight(root->left),maxHeight(root->right));
    return maxi+1;
}

int diameter(node* root){
    if(root==NULL)
    return 0;
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=maxHeight(root->left)+maxHeight(root->right)+1;
    int ans=max(op1,max(op2,op3));
    return ans;
}

pair<int,int> fastDiameter(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p; 
    }
    pair<int,int> left=fastDiameter(root->left);
    pair<int,int> right=fastDiameter(root->right);
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}

bool balanceTree(node* root){
    if(root==NULL)
    return true;
    bool left=balanceTree(root->left);
    bool right=balanceTree(root->right);
    bool diff=abs(maxHeight(root->right)-maxHeight(root->left))<=1;
    if(left&&right&&diff)
    return true;
    return false;
}

pair<bool,int> fastBalanceTree(node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<bool,int> left=fastBalanceTree(root->left);
    pair<bool,int> right=fastBalanceTree(root->right);
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int> ans;
    if(left.first&&right.first&&diff)
    ans.first=true;
    else
    ans.first=false;
    ans.second=max(left.second,right.second)+1;
    return ans;
}

bool isIdentical(node* root1, node* root2){
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1==NULL&&root2!=NULL)
    return false;
    if(root1!=NULL&&root2==NULL)
    return false;
    bool left=isIdentical(root1->left,root2->left);
    bool right=isIdentical(root1->right,root2->right);
    bool curr=root1->data==root2->data;
    if(left&&right&&curr)
    return true;
    return false;
}

pair<bool,int> sumTree(node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<bool,int> left=sumTree(root->left);
    pair<bool,int> right=sumTree(root->right);
    bool curr=root->data==left.second+right.second;
    pair<bool,int> ans;
    if(left.first&&right.first&&curr)
    ans.first=true;
    else
    ans.first=false;
    ans.second=left.second+right.second+root->data;
    return ans;
}

vector<int> zigZagTraversal(node* root){
    vector<int> result;
    if(root==NULL)
    return result;
    queue<node*> q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            node* frontNode=q.front();
            q.pop();
            int index=leftToRight?i:size-i-1;
            ans[index]=frontNode->data;
            if(frontNode->left)
            q.push(frontNode->left);
            if(frontNode->right)
            q.push(frontNode->right);
        }
        leftToRight=!leftToRight;
        for(auto i:ans)
        result.push_back(i);
    }
    return result;
}

void traverseLeft(node* root, vector<int>& ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL))
    return;
    ans.push_back(root->data);
    if(root->left)
    traverseLeft(root->left,ans);
    else
    traverseLeft(root->right,ans);
}

void traverseLeaf(node* root, vector<int>& ans){
    if(root==NULL)
    return;
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root, vector<int>& ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL))
    return;
    if(root->right)
    traverseLeft(root->right,ans);
    else
    traverseLeft(root->left,ans);
    ans.push_back(root->data);
}

vector<int> boundryTraversal(node* root){
    vector<int> ans;
    if(root==NULL)
    return ans;
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    traverseLeaf(root,ans);
    traverseRight(root->right,ans);
    return ans;
}

vector<int> verticalTraversal(node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<node*,pair<int,int>>> q;
    vector<int> ans;
    if(root==NULL)
    return ans;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int,int>> temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int horiz=temp.second.first;
        int level=temp.second.second;
        nodes[horiz][level].push_back(frontNode->data);
        if(frontNode->left)
        q.push(make_pair((frontNode->left),make_pair(horiz-1,level+1)));
        if(frontNode->right)
        q.push(make_pair((frontNode->right),make_pair(horiz+1,level+1)));
    }
    for(auto i:nodes)
        for(auto j:i.second)
            for(auto k:j.second)
            ans.push_back(k);
    return ans;
}

vector<int> vertical_Traversal(node* root){
    vector<int> ans;
    if(root==NULL)
    return ans;
    vector<pair<int,int>> temp;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> jhaat=q.front();
        q.pop();
        node* frontNode=jhaat.first;
        int horizon=jhaat.second;
        temp.push_back(make_pair(horizon,frontNode->data));
        if(frontNode->left)
        q.push(make_pair(frontNode->left,horizon-1));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,horizon+1));
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<temp.size();i++)
    ans.push_back(temp[i].second);
    return ans;
}

vector<int> topView(node* root){
    vector<int> ans;
    if(root==NULL)
    return ans;
    map<int,int> topNode;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int horiz=temp.second;
        if(topNode.find(horiz)==topNode.end())
        topNode[horiz]=frontNode->data;
        if(frontNode->left)
        q.push(make_pair(frontNode->left,horiz-1));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,horiz+1));
    }
    for(auto i:topNode)
    ans.push_back(i.second);
    return ans;
}

vector<int> bottomView(node* root){
    vector<int> ans;
    if(root==NULL)
    return ans;
    map<int,int> topNode;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int horiz=temp.second;
        topNode[horiz]=frontNode->data;
        if(frontNode->left)
        q.push(make_pair(frontNode->left,horiz-1));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,horiz+1));
    }
    for(auto i:topNode)
    ans.push_back(i.second);
    return ans;
}

vector<int> leftView(node* root){
    vector<int> ans;
    if(root==NULL)
    return ans;
    map<int,int> leftNode;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int level=temp.second;
        if(leftNode.find(level)==leftNode.end())
        leftNode[level]=frontNode->data;
        if(frontNode->left)
        q.push(make_pair(frontNode->left,level+1));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,level+1));
    }
    for(auto i:leftNode)
    ans.push_back(i.second);
    return ans;
}

vector<int> left_View(node* root, int level, vector<int> &ans){
    if(root==NULL)
    return ans;
    if(level==ans.size())
    ans.push_back(root->data);
    left_View(root->left,level+1,ans);
    left_View(root->right,level+1,ans);
    return ans;
}

vector<int> right_View(node* root, int level, vector<int> &ans){
    if(root==NULL)
    return ans;
    if(level==ans.size())
    ans.push_back(root->data);
    right_View(root->right,level+1,ans);
    right_View(root->left,level+1,ans);
    return ans;
}

void Bloodline(node* root, int &ht, int i, int sum, int &sumf){
    if(!root) return ;
    sum+=root->data;
    i++;
    if(i>ht){
        sumf=sum;
        ht=i;
    } else if(i==ht)
    sumf=max(sumf,sum);
    Bloodline(root->left ,ht,i,sum,sumf);
    Bloodline(root->right,ht,i,sum,sumf);
    return ;
}

void bloodline(node* root, int &ht, int i, int sum, int &sumf){
    if(!root){
        if(i>ht){
            sumf=sum;
            ht=i;
        } else if(i==ht){
            sumf=max(sum,sumf);
        }
        return ;
    }
    sum+=root->data;
    bloodline(root->left,ht,i+1,sum,sumf);
    bloodline(root->right,ht,i+1,sum,sumf);
}

node* lca(node* root, int n1, int n2){
    if(root==NULL)
    return NULL;
    if(root->data==n1||root->data==n2)
    return root;
    node* leftAns=lca(root->left,n1,n2);
    node* rightAns=lca(root->right,n1,n2);
    if(leftAns==NULL&&rightAns==NULL)
        return NULL;
    else if(leftAns!=NULL&&rightAns==NULL)
        return leftAns;
    else if(leftAns==NULL&&rightAns!=NULL)
        return rightAns;
    else
        return root;
}

int distBet2Node(node* root, int n1, int n2){
    if(root==NULL)
    return 0;
    if(root->data==n1||root->data==n2)
    return 1;
    int leftAns=lca(root->left,n1,n2);
    int rightAns=lca(root->right,n1,n2);
    if(leftAns==0&&rightAns==0)
        return 0;
    else if(leftAns!=0&&rightAns==0)
        return leftAns+1;
    else if(leftAns==0&&rightAns!=0)
        return rightAns+1;
    else
        return leftAns+rightAns+1;
}

void KsumPath(node* root, int k, int count, vector<int> path){
    if(root==NULL)
    return ;
    path.push_back(root->data);
    int sum=0,size=path.size();
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k)
        count++;
    }
    KsumPath(root->left,k,count,path);
    KsumPath(root->right,k,count,path);
    path.pop_back();
}

node* KthAnsister(node* root, int &k, int d){
    if(!root)
    return NULL;
    if(root->data==d)
    return root;
    node* left=KthAnsister(root->left,k,d);
    node* right=KthAnsister(root->right,k,d);
    if(left!=NULL&&right==NULL){
        k--;
        if(k==0)
        return root;
        return left;
    } else if(left==NULL&&right!=NULL){
        k--;
        if(k==0)
        return root;
        return right;
    } else {
        return NULL;
    }
}

pair<int,int> MaxSumofNonAdjNode(node* root){
    if(root==NULL)
    return make_pair(0,0);
    pair<int,int> left=MaxSumofNonAdjNode(root->left);
    pair<int,int> right=MaxSumofNonAdjNode(root->right);
    int include = left.second+right.second+root->data;
    int exclude = max(left.first,left.second)+max(right.first,right.second);
    return make_pair(include,exclude);
}

node* buildTreeInPre(int in[], int pre[], int n, int inStInd, int intEnInd, int &preInd){
    if(preInd==n||inStInd>intEnInd)
    return NULL;
    int target=0;
    for(int i=0;i<n;i++){
        if(in[i]==pre[preInd]){
            target=i;
            break;
        }
    }
    node* root=new node(pre[preInd++]);
    root->left=buildTreeInPre(in,pre,n,inStInd,target-1,preInd);
    root->right=buildTreeInPre(in,pre,n,target+1,intEnInd,preInd);
    return root;
}

node* buildTreeInPost(int in[], int post[], int n, int inStInd, int intEnInd, int &postInd){
    if(postInd==-1||inStInd>intEnInd)
    return NULL;
    int target=0;
    for(int i=0;i<n;i++){
        if(in[i]==post[postInd]){
            target=i;
            break;
        }
    }
    node* root=new node(post[postInd--]);
    root->right=buildTreeInPost(in,post,n,target+1,intEnInd,postInd);
    root->left=buildTreeInPost(in,post,n,inStInd,target-1,postInd);
    return root;
}

node* target(node* root, int data, map<node*,node*> &nodeToParent){
    queue<node*> q;
    q.push(root);
    nodeToParent[root]=NULL;
    node* temp;
    while(!q.empty()){
        node* front=q.front();
        q.pop();
        if(front->data==data)
        temp=front;
        if(front->left){
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }
    return temp;
}

int burning(node* root, map<node*,node*> &nodeToParent){
    map<node*,bool> visited;
    queue<node*> q;
    q.push(root);
    int ans=0;
    while(!q.empty()){
        bool flag=false;
        int n=q.size();
        for(int i=0;i<n;i++){
            node* front=q.front();
            q.pop();
            visited[front]=true;
            if(front->left&&!visited[front->left]){
                visited[front->left]=true;
                q.push(front->left);
                flag=true;
            }
            if(front->right&&!visited[front->right]){
                visited[front->right]=true;
                q.push(front->right);
                flag=true;
            }
            if(nodeToParent[front]&&!visited[nodeToParent[front]]){
                visited[nodeToParent[front]]=true;
                q.push(nodeToParent[front]);
                flag=true;
            }
        }
        if(flag) ans++;
    }
    return ans;
}

int BurningTree(node* root, int data){
    map<node*,node*> nodeToParent;
    node* targetNode=target(root,data,nodeToParent);
    int ans=burning(targetNode,nodeToParent);
    return ans;
}

void morrisInorder(node* root){
    node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        } else {
            node* pre=curr->left;
            while(pre->right!=NULL&&pre->right!=curr){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            } else {
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}

void flattenTree(node* root){
    node* curr=root;
    while(curr){
        if(curr->left){
            node* pre=curr->left;
            while(pre->right){
                pre=pre->right;
            }
            pre->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    node* root=NULL;
    root=buildTree(root);

    cout<<"pre order traversal\n";
    preorderTraversal(root);
    cout<<"\n";
    cout<<"post order traversal\n";
    postorderTraversal(root);
    cout<<"\n";
    cout<<"inorder traversal\n";
    inorderTraversal(root);
    cout<<"\n";
    cout<<"Level order traversal\n";
    levelOrderTraversal(root);
    cout<<"Boundry traversal\n";
    vector<int> ans=boundryTraversal(root);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" "; 
    cout<<"\n";
    cout<<"Vertical Traversal\n";
    vector<int> vertical = verticalTraversal(root);
    for(int i=0;i<vertical.size();i++) cout<<vertical[i]<<" ";
    cout<<"\n";
    cout<<"Top View\n";
    vector<int> TopView = topView(root);
    for(int i=0;i<TopView.size();i++) cout<<TopView[i]<<" ";
    cout<<"\n";
    cout<<"Bottom View\n";
    vector<int> BottomView = bottomView(root);
    for(int i=0;i<BottomView.size();i++) cout<<BottomView[i]<<" ";
    cout<<"\n";
    cout<<"Left View\n";
    vector<int> LeftView = left_View(root,0,LeftView);
    for(int i=0;i<LeftView.size();i++) cout<<LeftView[i]<<" ";
    cout<<"\n";
    cout<<"right View\n";
    vector<int> RightView = right_View(root,0,RightView);
    for(int i=0;i<RightView.size();i++) cout<<RightView[i]<<" ";
    cout<<"\n";
}