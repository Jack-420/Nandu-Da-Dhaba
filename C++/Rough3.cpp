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
void transpose(vector<vector<int>>& v,vector<vector<int>>& ans,int N)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            ans[i][j] = v[j][i];
}

void code(){
    int n; cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    int even=1,odd=n*n;
    for(int i=0;i<n;i++){
        int x=0,y=i;
        while(x<n&&y>=0){
            if(i%2==0){
                v[x][y]=even;
                even++;
            }
            else{
                v[x][y]=odd;
                odd--;
            }
            x++;y--;
        }
    }
    for(int i=1;i<n;i++){
        int x=i,y=n-1;
        while(x<n&&y>=0){
            if(i%2==0){
                v[x][y]=even;
                even++;
            }
            else{
                v[x][y]=odd;
                odd--;
            }
            x++;y--;
        }
    }
    vector<vector<int>> ans(n,vector<int>(n,0));
    transpose(v,ans,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
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
        // cout<<endl;
    }
}