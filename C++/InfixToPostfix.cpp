#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define int long long

int mod(int n){
    return n % 1000000007;
}

bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int isSquare(int n){
    int l=1,h=n;
    while(l<=h){
        int mid=(l+h)/2;
        if(mid*mid==n) return mid;
        if(mid*mid<n) l=mid+1;
        else h=mid-1;
    }
    return -1;
}

bool cmp(int a, int b){
    return a>b;
}

int power(int a,int b){
    int temp=1;
    while(b--)
        temp*=a;
    return temp;
}

int prec(char c){
    if(c=='^')              return 3;
    else if(c=='/'||c=='*') return 2;
    else if(c=='+'||c=='-') return 1;
    else                    return 0;
}

string infixToPostfix(string s){
    string ans;
    stack<char> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            ans+=c;
        } else if(c=='('){
            st.push(c);
        } else if(c==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty()&&prec(c)<=prec(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

void code(){
    string s; cin>>s;
    cout<<infixToPostfix(s);
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420

    int t;
    cin>>t;
    while(t--)
    {
        code();
        cout<<endl;
    }
}