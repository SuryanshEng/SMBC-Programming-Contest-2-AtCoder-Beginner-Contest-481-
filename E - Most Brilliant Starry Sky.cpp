#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<ll,ll>> p(n);
        for(auto&[x,y]:p)cin>>x>>y;
        auto up=[](pair<ll,ll>a){return a.second>0||(a.second==0&&a.first>0);};
        auto cr=[](pair<ll,ll>a,pair<ll,ll>b){return a.first*b.second-a.second*b.first;};
        sort(p.begin(),p.end(),[&](auto a,auto b){
            if(up(a)!=up(b))return up(a)>up(b);
            return cr(a,b)>0;
        });
        int j=0,r=0;
        for(int i=0;i<n;i++){
            j=max(j,i+1);
            while(j<i+n&&cr(p[i],p[j%n])>0)j++;
            r=max(r,j-i);
        }
        cout<<r<<'\n';
    }
}