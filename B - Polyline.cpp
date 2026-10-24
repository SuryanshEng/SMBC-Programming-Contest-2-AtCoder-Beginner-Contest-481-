#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,p,a,r=0;
    cin>>n>>k>>p;
    r=p==k;
    while(--n){
        cin>>a;
        r+=a==k||(a-k)*(p-k)<0;
        p=a;
    }
    cout<<r;
}