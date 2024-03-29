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

//
/**
** Comment **
**/

const int X[] = { 0, -1, 0, 1 };
const int Y[] = { -1, 0, 1, 0 };
#define x first
#define y second

string des = "012345678"; // 0 is empty cell
map<string, string> states;
vstr grp;

inline pii getIndex(int index) {
	return pii(index / 3, index % 3);
}

inline int getIndexString(pii pos) {
	return pos.x * 3 + pos.y;
}

inline pii findEmptyCell(string state) {
	pii res = pii(0, 0);

	for (int i = 0; i < 9; ++i) {
		if (state[i] == '0') {
			res = getIndex(i);
			break;
		}
	}

	return res;
}

inline bool canGo(pii pos) {
	if (pos.x < 0 || pos.x > 2 || pos.y < 0 || pos.y> 2) {
		return false;
	}

	return true;
}

inline void bfs(string src) {
	queue<string> q;
	q.push(src);
	states[src] = "end";

	while (!q.empty()) {
		string u = q.front();
		pii posU = findEmptyCell(u);
		q.pop();

		if (u == des) {
			return;
		}

		for (int i = 0; i < 4; ++i) {
			pii posV = pii(posU.x + X[i], posU.y + Y[i]);

			if (canGo(posV)) {
				string v = u;
				swap(v[getIndexString(posU)], v[getIndexString(posV)]);

				if (!states.count(v)) {
					states[v] = u;
					q.push(v);
				}
			}
		}
	}
}

void printPath(string state) {
	if (state == "end") {
		return;
	}

	printPath(states[state]);
	cout << state.substr(0, 3) << endl;
	cout << state.substr(3, 3) << endl;
	cout << state.substr(6, 3) << endl;
	cout << endl;
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	
	grp.push_back("142");
	grp.push_back("375");
	grp.push_back("608");
	bfs(grp[0] + grp[1] + grp[2]);
	printPath(des);
	
	return 0;
}