#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
bool visited[MAXN];

int dfs(int node) {
    visited[node] = true;
    int size = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            size += dfs(neighbor);
        }
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    fill(visited, visited + N + 1, false);
    int max_component_size = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            int current_size = dfs(i);
            if (current_size > max_component_size) {
                max_component_size = current_size;
            }
        }
    }
    
    cout << max_component_size << endl;
    
    return 0;
}