#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> v[MAXN];
pair<int, int> bfs(int src, int n) {
    vector<int> dist(n+1, -1); 
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    int farthest_node = src;

    while(!q.empty()) {
        int parent = q.front();
        q.pop();

        for(int child : v[parent]) {
            if(dist[child] == -1) {
                dist[child] = dist[parent] + 1;
                q.push(child);
                if(dist[child] > dist[farthest_node]) {
                    farthest_node = child;
                }
            }
        }
    }
    return {farthest_node, dist[farthest_node]};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    auto p1 = bfs(1, n);
    auto p2 = bfs(p1.first, n);

    cout << p2.second << endl; 
    return 0;
}
