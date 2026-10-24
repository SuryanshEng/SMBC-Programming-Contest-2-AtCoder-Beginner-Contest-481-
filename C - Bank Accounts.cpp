#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q;
    string s;
    unordered_map<string,int> m;
    cin>>q;
    while(q--){
        cin>>s;
        cout<<m.emplace(s,m.size()+1).first->second<<'\n';
    }
}