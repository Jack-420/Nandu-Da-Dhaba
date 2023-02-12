#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;
#define adiwish ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

template <class T>
void display(vector<T> &v){
    cout<<"Displaying vector."<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        adiwish
    #define int long long

        // Ways to create a vector.

        vector<int> vec1; // Zero length integer vector.
        display(vec1);
        
        int element,size;
        cin>>size;
        for(int i=0;i<size;i++){
            cin>>element;
            vec1.push_back(element);
        }
        display(vec1);
        vector<int> :: iterator iter = vec1.begin();
        vec1.insert(iter+0,1,556);
        display(vec1);

        // vector<char> vec2(4); // charrectors vector of length = 4.
        // vec2.push_back('5'); // vec2.emplace_back('5'); ----> similar but emplace takes lesser time.
        // vec2.push_back('4');
        // display(vec2);
        // vector<char> vec3(vec2);
        // vec3.push_back('6');
        // display(vec3);
        // vector<int> vec4(10,6); // Displaying 6 ten times.
        // display(vec4);
        // vec.clear(); ---> vector ko khali kar deta hai.
        // vector<int> vec(4,0) ----> {0,0,0,0}.
        


        // 2D vector.
        // vector<vector<int>> vec;

        // vector<int> v1;
        // v1.push_back(1);
        // v1.push_back(2);
        // v1.push_back(3);

        // vector<int> v2;
        // v2.push_back(4);
        // v2.push_back(5);
        // v2.push_back(6);

        // vector<int> v3;
        // v3.push_back(7);
        // v3.push_back(8);
        // v3.push_back(9);

        // vec.push_back(v1);
        // vec.push_back(v2);
        // vec.push_back(v3);

        // for(auto vctr: vec){
        //     for(auto it: vctr){
        //         cout<<it<<" ";
        //     }
        //     cout<<"\n";
        // }
        // // for(int i=0;i<vec.size();i++){
        // //     for(int j=0;j<vec[i].size();j++){
        // //         cout<<vec[i][j]<<" ";
        // //     }
        // //     cout<<"\n";
        // // }

        // vector<vector<int>> vec2(10,vector<int> (20,0)); // ----> 10*20 with all value 0
        // // 3D vector.
        // vector<vector<vector<int>>> vec3(10, vector<vector<int>> (20,vector<int> (30,0))); // 10*20*30 with all values 0
    return 0;
}