#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2001]; // adjacency list
bool visited[2001];

// performs DFS and returns true if cycle is found
bool dfs(int u, int parent) 
{ 
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) 
                return true; 
        } 
        else if (v != parent) // cycle found
            return true;
    }
    return false; 
}

// adds edge between u and v
void addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

// deletes edge between u and v    
void deleteEdge(int u, int v) 
{
    adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end()); 
    adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
}

int main() 
{
    int n, m;
    cin >> n >> m;
    
    // read input edges
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    
    // perform DFS to find cycles
    memset(visited, false, sizeof(visited));
    bool cycle = false;
    for (int i=1; i<=n; i++) {
        if (!visited[i] && dfs(i, -1)) {
            cycle = true;
            break;
        }
    }
    
    // if no cycle, then no need to add/delete edge
    if (!cycle) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    
    // stores edges to be deleted and added
    vector<pair<int,int>> del, add; 
    
    // traverse edges and check if deleting an edge 
    // makes graph acyclic, if yes then delete it
    for (int u=1; u<=n; u++) {
        for (int v : adj[u]) {
            if (u > v) continue; // avoid parallel edges
            
            deleteEdge(u, v); // delete the edge
            
            // perform DFS again to check for cycles
            memset(visited, false, sizeof(visited));
            cycle = false;
            for (int i=1; i<=n; i++) {
                if (!visited[i] && dfs(i, -1)) {
                    cycle = true;
                    break;
                }
            }
            
            if (!cycle) { // if graph is acyclic now
                del.push_back({u, v}); // add to del vector
            }
            else {        // else add the edge back
                addEdge(u, v);  
            }
        }
    }
    
    cout << del.size() << " " << add.size() << endl;
    for (auto d : del) cout << d.first << " " << d.second << endl;
    for (auto a : add) cout << a.first << " " << a.second << endl;
}