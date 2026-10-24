#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,s,t,a,b;
    cin>>n>>m>>s>>t;
    vector<vector<int>> g(n+1);
    while(m--)cin>>a>>b,g[a].push_back(b);
    vector<int> d(n+1,INT_MAX);
    deque<int> q{s};
    d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop_front();
        if(g[u].empty())continue;
        int mn=*min_element(g[u].begin(),g[u].end());
        for(int v:g[u]){
            int c=v!=mn;
            if(d[u]+c<d[v]){
                d[v]=d[u]+c;
                c?q.push_back(v):q.push_front(v);
            }
        }
    }
    cout<<(d[t]==INT_MAX?-1:d[t]);
}