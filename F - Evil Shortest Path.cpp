#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int n, m;
vector<vector<pair<int,int>>> road;
vector<ll> rohit, virat;
vector<int> jadeja;

void readGraph(){
    cin >> n >> m;
    road.assign(n + 1, {});
    for(int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        road[a].push_back({b, c});
    }
}

void spreadLayer(vector<int>& now, vector<int>& next, vector<int>& rank, vector<bool>& seen){
    for(int u : now)
        for(auto [v, w] : road[u]){
            if(seen[v]) continue;
            ll key = (ll)rank[u] * 10 + w;
            if(virat[v] == LLONG_MAX) next.push_back(v);
            if(key < virat[v]) virat[v] = key, jadeja[v] = u;
        }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    readGraph();
    rohit.assign(n + 1, 0);
    virat.assign(n + 1, LLONG_MAX);
    jadeja.assign(n + 1, 0);
    vector<int> rank(n + 1, 0), now{1}, next;
    vector<bool> seen(n + 1, false);
    seen[1] = true;
    while(!now.empty()){
        next.clear();
        spreadLayer(now, next, rank, seen);
        sort(next.begin(), next.end(), [&](int a, int b){ return virat[a] < virat[b]; });
        int r = -1;
        for(size_t i = 0; i < next.size(); i++){
            int v = next[i];
            if(i == 0 || virat[v] != virat[next[i - 1]]) r++;
            rank[v] = r;
            rohit[v] = (rohit[jadeja[v]] * 10 + virat[v] % 10) % MOD;
            seen[v] = true;
        }
        now = next;
    }
    for(int v = 2; v <= n; v++) cout << rohit[v] << '\n';
}