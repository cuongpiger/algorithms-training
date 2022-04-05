#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define x(a) (a.first)
#define y(a) (a.second)
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================
//https://codeforces.com/problemset/problem/161/D
/**
 ** Comment **
 https://www.geeksforgeeks.org/find-the-number-of-distinct-pairs-of-vertices-which-have-a-distance-of-exactly-k-in-a-tree/
 If don't remember how to solve this problem, open command lines from 54 to 56, 62 and 63, then debugging to understand
 **/

const int N = (int)(5e4 + 5);
const int K = 505;
int numVerticesAtDistanceK[N][K]; /*Count the number of vertices that connect to the current vertex
								  and was about distance of K away from the current vertex*/
vector<int> grp[N];
int n, k, ans = 0;

// the current vertex and the parent of the current vertext
void dfs(int vertex, int parent){
	numVerticesAtDistanceK[vertex][0] = 1; // at distance 0, vertex itself is counted

	for (auto v : grp[vertex]){
		if (v != parent){
			dfs(v, vertex);

			/*Count the pair of vertices at distance k*/
			for (int i = 1; i <= k; ++i){
				ans += (numVerticesAtDistanceK[v][i - 1] * numVerticesAtDistanceK[vertex][k - i]);
				//printf("Parent: %d, at distance: %d, d_parent = %d\n", vertex, k - i, numVerticesAtDistanceK[vertex][k - i]);
				//printf("Child : %d, at distance: %d, d_child  = %d\n", v, i - 1, numVerticesAtDistanceK[v][i - 1]);
				//printf("Ans   : %d\n\n", ans);
			}

			/*Count vertices connect to the 'vertex' at all distance from 1 to k*/
			for (int i = 1; i <= k; ++i){
				numVerticesAtDistanceK[vertex][i] += numVerticesAtDistanceK[v][i - 1];
				//printf("Parent: %d, at distance: %d, d_parent = %d\n", vertex, i, numVerticesAtDistanceK[vertex][i]);
				//printf("Child : %d, at distance: %d, d_child  = %d\n\n", v, i - 1, numVerticesAtDistanceK[v][i - 1]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int u, v, root = 1;
	cin >> n >> k >> u >> v;
	root = u;
	grp[u].push_back(v);
	grp[v].push_back(u);

	for (int i = 0; i < n - 2; ++i){
		cin >> u >> v;
		grp[u].push_back(v);
		grp[v].push_back(u);
	}

	dfs(root, 0); // the root have the parent vertex is 0
	cout << ans << endl;

	return 0;
}
