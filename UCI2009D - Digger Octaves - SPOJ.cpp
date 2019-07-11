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
using namespace std;

//=============================================================================================
const double pi = 3.14159265359;
#define p(a) ((a) * (a))
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
//=============================================================================================

/**
 ** Comment **
 https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
 **/

const vector<pii> direc = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // moving in the four directions
set<set<pii>> truck; // contain all octaves, so the answer of this problem is the truck's size
int n;

inline bool isSafe(int &x, int &y, vector<vector<char>> &land, vector<vector<bool>> &vs) {
	if ((x > -1 && x < n) && (y > -1 && y < n) && land[x][y] == 'X' && vs[x][y] == 0)
		return 1;
	return 0;
}

void solve(int x, int y, int c, vector<vector<char>> &land, vector<vector<bool>> &vs, set<pii> box) {
	if (!isSafe(x, y, land, vs)) return;

	vs[x][y] = 1;
	box.insert({ x, y });

	if (c == 8) {
		vs[x][y] = 0;
		truck.insert(box); // duplicate boxes will be excluded when insert to the set 'truck'	
		return;
	}

	for (int i = 0; i < 4; ++i) {
		pii posNext = make_pair(x + direc[i].first, y + direc[i].second);
		solve(posNext.first, posNext.second, c + 1, land, vs, box);
	}

	vs[x][y] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tc; cin >> tc;

	while (tc--) {
		cin >> n;
		vector<vector<char>> land(n, vector<char>(n));
		vector<vector<bool>> vs(n, vector<bool>(n, 0));
		truck.clear();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> land[i][j];
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				set<pii> box;
				solve(i, j, 1, land, vs, box);
			}
		}

		cout << truck.size() << endl;
	}

	return 0;
}