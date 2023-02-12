#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int Power(int a, int b){
    if(b==0)
    return 1;
    if(b==1)
    return a;
    int ans=Power(a,b/2);
    if(b%2==0)
    return ans*ans;
    return ans*ans*a;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    int a,b; cin>>a>>b;
    cout<<Power(a,b);

}