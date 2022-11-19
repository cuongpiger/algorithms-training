#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <set>
#include <stack>
#include <numeric>
#include <regex>
#include <queue>
#include <iomanip>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

#define id first
#define vl second

void dfs(int u, vector<vector<int>> &G, vector<bool> &visited) {
    visited[u] = true;
    for (int v : G[u]) {
        if (!visited[v]) {
            dfs(v, G, visited);
        }
    }
}

int main() {
    FAST_IO;
    // FILE_IO;

    vector<vector<int>> G(100010);
    vector<bool> vst(100010);
    int T, N, E, u, v;
    cin >> T;

    while (T--) {
        cin >> N >> E;
        for (int i = 0; i < N; ++i){
            G[i].clear();
            vst[i] = false;
        }

        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (!vst[i]) {
                dfs(i, G, vst);
                ++cnt;
            }
        }

        cout << cnt << endl;
    }


    return 0;
}
