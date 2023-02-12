#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


class Stack {
    public:
        int* arr;
        int size;
        int top;
    Stack(int size){
        this->size=size;
        arr = new int[size];
        top=-1;
    }
    void push(int data){
        if(top<size-1){
            top++;
            arr[top]=data;
        } else {
            cout<<"Stack Overflow\n";
        }
    }
    void pop(){
        if(top>=0){
            top--;
        } else {
            cout<<"Stack Underflow\n";
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        } else {
            cout<<"Stack is Empty";
            return -1;
        }
    }
    int position(int d){
        if(top>=0&&top<d)
        return arr[d-1];
        else 
        return -1;
    }
    int toop(){
        if(top==-1)
        return -1;
        else
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1)
        return true;
        return false;
    }
};


string reverseString(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        s.push(ch);
    }
    string ans="";
    while(!s.empty()){
        ans=ans+s.top();
        s.pop();
    }
    return ans;
}

void deleteMid(stack<int> &s, int cnt, int size){
    if(cnt==size/2){
        s.pop();
        return;
    }
    int n=s.top();
    s.pop();
    deleteMid(s,cnt+1,size);
    s.push(n);
}

bool isValidParenthesis(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            s.push(str[i]);
        } else {
            if(!s.empty()){
                if((s.top()=='('&&str[i]==')')||(s.top()=='{'&&str[i]=='}')||(s.top()=='['&&str[i]==']')){
                    s.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    if(s.empty())
    return true;
    return false;
}

void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int n=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(n);
}

void reverseStack(stack<int> &s){
    if(s.empty())
    return;
    int n=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,n);
}

void sortedInsert(stack<int> &s, int x){
    if(s.empty()||s.top()<x){
        s.push(x);
        return;
    }
    int n=s.top();
    s.pop();
    sortedInsert(s,x);
    s.push(n);
}

void sortStack(stack<int> &s){
    if(s.empty())
    return;
    int n=s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s,n);
}

bool findReduntantBrackets(string &str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('||str[i]=='-'||str[i]=='+'||str[i]=='*'||str[i]=='/'){
            s.push(str[i]);
        } else if(str[i]==')'){
            bool isReduntant=true;
            while(str[i]!='('){
                isReduntant=false;
                s.pop();
            }
            s.pop();
            if(isReduntant)
            return true;
        }
    }
    return false;
}

int minCostToMakeStringValid(string &str){
    if(str.size()&1)
    return -1;
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='{'){
            s.push(str[i]);
        } else {
            if(!s.empty()&&s.top()=='{')
            s.pop();
            else
            s.push(str[i]);
        }
    }
    int a=0,b=0;
    while(!s.empty()){
        if(s.top()=='{')
        a++;
        else
        b++;
        s.pop();
    }
    return (a+1)/2+(b+1)/2;
}

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        while(s.top()!=-1&&arr[i]<=arr[s.top()]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(s.top()!=-1&&arr[i]<=arr[s.top()]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleAreaInHistogram(vector<int> &heights, int n){
    vector<int> next=nextSmallerElement(heights,n);
    vector<int> prev=prevSmallerElement(heights,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int l=heights[i];
        if(next[i]==-1)
        next[i]=n;
        int b=next[i]-prev[i]-1;
        area=max(area,l*b);
    }
    return area;
}

int largestRectangleIn2DMatrix(vector<vector<int>> &a, int n, int m){
    int ans=largestRectangleAreaInHistogram(a[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]){
                a[i][j]+=a[i-1][j];
            }
        }
        ans=max(ans,largestRectangleAreaInHistogram(a[i],m));
    }
    return ans;
}

bool verify(vector<vector<int>> &a, int n, int k){
    int row=1, col=1;
    for(int i=0;i<n;i++){
        if(a[k][i])
        row=0;
    }
    for(int i=0;i<n;i++){
        if(a[i][k]==0&&i!=k)
        col=0;
    }
    if(row&&col)
    return true;
    return false;
}

int celibrity(vector<vector<int>> &a, int n){
    stack<int> s;
    for(int i=0;i<n;i++)
    s.push(i);
    while(s.size()>1){
        int c=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(a[c][b])
        s.push(b);
        else
        s.push(c);
    }
    if(verify(a,n,s.top()))
    return s.top();
    else
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.peek()<<"\n";
    st.pop();
    cout<<st.peek()<<"\n";
    st.pop();
    cout<<st.peek()<<"\n";
    st.pop();
    cout<<st.peek()<<"\n";
    st.pop();
    cout<<st.peek()<<"\n";

    if(st.isEmpty())
    cout<<"Stack is Empty\n";
    else
    cout<<"Stack is not Empty\n";



    // stack<string> s;
    // s.push("Mrinal ");
    // s.push("Singh ");
    // s.push("is ");
    // s.push("King ");
    // cout<<"Top element is "<<s.top()<<"\n";
    // s.pop();
    // cout<<"Top element is "<<s.top()<<"\n";

    
}