#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

vector<int> topoSort(vector< vector<int> > &adj, vector<int> &indegree){
    int n = indegree.size();
    priority_queue<int, vector<int>, greater<int> > zero_indegree;
    vector<int> topoSorted;
    // vector<bool> avail(n, true);

    for (int i = 0; i < indegree.size(); i++)
        if (indegree[i] == 0){
            zero_indegree.push(i);
            // avail[i] = false;
        }


    while (!zero_indegree.empty()){
        int u = zero_indegree.top();
        zero_indegree.pop();

        topoSorted.push_back(u);

        for (int i = 0;i < adj[u].size(); i++){
            int v = adj[u][i];
            indegree[v] --;
            if (indegree[v] == 0){
                zero_indegree.push(v);
            }
        }
    }

    
    return topoSorted;
}

int main(){
    // n: number of vertices
    // m: number of edges
    int n, m, u, v;
    vector< vector<int> > adj;
    vector<int> indegree;
    scanf("%d %d", &n, &m);
    adj.resize(n);
    indegree.assign(n, 0);
    for (int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1].push_back(v - 1);
        indegree[v - 1] ++;
    }
    
    vector<int> res = topoSort(adj, indegree);
    if (res.size() < n){
        printf("Sandro fails.\n");
        return 0;
    }

    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i] + 1);
    printf("\n");

    return 0;
}
