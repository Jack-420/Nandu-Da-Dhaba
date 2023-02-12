#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define Jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        Jack420
    #define int long long

        int t; 
        cin>>t;
        while(t--){
            int k1, k2, a, b, c, d;
            cin>>k1>>k2>>a>>b>>c>>d;
            if(k1==1&&k2!=8&&k2!=1){
                if(a==2&&b!=k2&&b!=k2-1&&b!=k2+1){
                    if(c>=2&&d!=k2&&d!=k2-1&&d!=k2+1&&d!=b){
                        cout<<"YES";
                    } else {
                        cout<<"NO"; 
                    }
                } else if(c==2&&d!=k2&&d!=k2-1&&d!=k2+1){
                    if(a>=2&&b!=k2&&b!=k2-1&&b!=k2+1&&b!=d){
                        cout<<"YES";
                    } else {
                        cout<<"NO";
                    }
                } else {
                    cout<<"NO";
                }
            } else if(k2==1&&k1!=8&&k1!=1){
                if(b==2&&a!=k1&&a!=k1-1&&a!=k1+1){
                    if(d>=2&&c!=k1&&c!=k1-1&&c!=k1+1&&c!=a){
                        cout<<"YES";
                    } else {
                        cout<<"NO"; 
                    }
                } else if(d==2&&c!=k1&&c!=k1-1&&c!=k1+1){
                    if(b>=2&&a!=k1&&a!=k1-1&&a!=k1+1&&a!=c){
                        cout<<"YES";
                    } else {
                        cout<<"NO";
                    }
                } else {
                    cout<<"NO";
                }
            } else if(k1==8&&k2!=8&&k2!=1){
                if(a==7&&b!=k2&&b!=k2-1&&b!=k2+1){
                    if(c<=7&&d!=k2&&d!=k2-1&&d!=k2+1&&d!=b){
                        cout<<"YES";
                    } else {
                        cout<<"NO";
                    }
                } else if(c==7&&d!=k2&&d!=k2-1&&d!=k2+1){
                    if(a<=7&&b!=k2&&b!=k2-1&&b!=k2+1&&b!=d){
                        cout<<"YES";
                    } else {
                        cout<<"NO";
                    }
                } else {
                    cout<<"NO";
                }
            }else if(k2==8&&k1!=8&&k1!=1){
                if(b==7&&a!=k1&&a!=k1-1&&a!=k1+1){
                    if(d<=7&&c!=k1&&c!=k1-1&&c!=k1+1&&c!=a){
                        cout<<"YES";
                    } else {
                        cout<<"NO";                    
                    }
                } else if(d==7&&c!=k1&&c!=k1-1&&c!=k1+1){
                    if(b<=7&&a!=k1&&a!=k1-1&&a!=k1+1&&a!=c){
                        cout<<"YES";
                    } else {
                        cout<<"NO";
                    }
                } else {
                    cout<<"NO";
                }
            } else if(k1==1&&k2==1){
                if(a>=2 && b>=3 && c>=2 && d>=3 && b!=d && (c==2||a==2)){
                    cout<<"YES";
                } else if(c>=3 && d>=2 && a>=3 && b>=2 && a!=c && (b==2||d==2)){
                    cout<<"YES";
                } else {
                    cout<<"NO";
                }
            } else if(k1==1&&k2==8){
                if(a>=3&&b<=7&&c>=3&&d<=7&&a!=c&&(b==7||d==7)){
                    cout<<"YES";
                } else if(c>=2&&d<=6&&a>=2&&b<=6&&b!=d&&(a==2||c==2)){
                    cout<<"YES";
                } else {
                    cout<<"NO";
                }
            } else if(k1==8&&k2==8){
                if(a<=6&&b<=7&&c<=6&&d<=7&&a!=c&&(b==7||d==7)){
                    cout<<"YES";
                } else if(c<=7&&d<=6&&a<=7&&b<=6&&b!=d&&(a==7||c==7)){
                    cout<<"YES";
                } else {
                    cout<<"NO";
                }
            } else if(k1==8&&k2==1){
                if(a<=6&&b>=2&&c<=6&&d>=2&&a!=c&&(b==2||d==2)){
                    cout<<"YES";
                } else if(c<=7&&d>=3&&a>=7&&b>=3&&b!=d&&(c==7||a==7)){
                    cout<<"YES";
                } else {
                    cout<<"NO";
                }
            } else {
                cout<<"NO";
            }
            cout<<"\n";
        }
        return 0;
    }