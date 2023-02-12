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

string postfix(string s){
    stack<string> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            string temp;
            temp+=c;
            st.push(temp);
        } else {
            string sec=st.top();
            st.pop();
            string fst=st.top();
            st.pop();
            st.push(fst+c+sec);
        }
    }
    return st.top();
}

void code(){
    string s;
    cin>>s;
    cout<<postfix(s);
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