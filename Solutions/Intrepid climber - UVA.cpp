#pragma warning(disable:4996)
#include <iostream>
#include <cstdint>
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
#include <unordered_set>
#include <unordered_map>
using namespace std;

//==========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define sortRev greater<int>()
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<double, int> pdi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvi;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//==========================================================================================================================

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4727
/**
** Comment **
- We need to visit all friends at the vertices, so we will calculate the cost which we will take to visit all friends from
at all branches of vertex 1 (our position are standing) of tree, we need to seek where is the maximum branch's cost and save
it to variable <maxBranch>. The second condition that we need to calculate total cost of finding friend from vertex 1 (our position
are standing) to position of friends in array <markFriend>, if at any node which markFriend is true, we will sum all costs from
vertext 1 to this friend's position, sum altogether to variable <totalTree>, by fact, to save the cost of moving, we should visit friend
which they are as close by us as possible, and the friends at the branch is furthest by us, we should visit at last. Finally the answer for
this problem we just get the total cost to visit all friends <totalTree> minus the maximum branch's cost <maxBranch>
**/

#define neighbor first
#define weight second

bool markFriend[100010];
int maxBranch, totalTree;

void dfs(int u, bool& hasFriend, int cost, vvpii& grp) {
	bool hasFriend_2 = false;
	hasFriend = markFriend[u];

	if (markFriend[u]) {
		maxBranch = max(maxBranch, cost);
	}

	for (int i = 0; i < grp[u].size(); ++i) {
		pii v = grp[u][i];
		dfs(v.neighbor, hasFriend_2, cost + v.weight, grp);

		if (hasFriend_2) {
			totalTree += v.weight;
			hasFriend = true;
		}
	}
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	int n, m;

	while (cin >> n >> m) {
		markFriend[n] = false;
		maxBranch = totalTree = 0;
		vvpii grp(n + 5);
		bool hasFriend = false;

		for (int u, v, w, i = 1; i < n; ++i) {
			markFriend[i] = false;
			cin >> u >> v >> w;
			grp[u].push_back({ v, w });
		}

		for (int p, i = 0; i < m; ++i) {
			cin >> p;
			markFriend[p] = true;
		}

		dfs(1, hasFriend, 0, grp);
		cout << totalTree - maxBranch << endl;
	}

	return 0;
}