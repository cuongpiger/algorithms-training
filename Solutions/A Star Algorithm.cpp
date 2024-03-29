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

const int X[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int Y[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
#define x first
#define y second
#define cost first
#define posi second

int cnt = 0;

typedef struct cell {
	pii parent;
	double f, g, h;

	cell() {
		parent.x = parent.y = -1;
		f = g = h = 69696969;
	}
} cell;

typedef struct option {
	bool operator() (const pair<double, pii>& a, const pair<double, pii>& b) {
		return a.first > b.first;
	}
};
int n = 10, m = 9;

inline bool canGo(pii pos, int maze[][10]) {
	if (pos.x < 0 || pos.x >= m || pos.y < 0 || pos.y >= n || maze[pos.x][pos.y] == 0) {
		return false;
	}

	return true;
}

void printPath(pii des, vector<vector<cell>> &grp, int maze[][10]) {
	if (des.x != -1 && des.y != -1) {
		maze[des.x][des.y] = 2;
		des = grp[des.x][des.y].parent;
		printPath(des, grp, maze);
	}
}

void aStarSearch(pii src, pii des, int maze[][10]) {
	if (!canGo(src, maze) || !canGo(des, maze)) {
		cout << "The maze is invalid!!!";
		return;
	}

	vector<vector<cell>> grp(m, vector<cell>(n));
	priority_queue<pair<double, pii>, vector<pair<double, pii>>, option> pq;

	grp[src.x][src.y].f = grp[src.x][src.y].g = grp[src.x][src.y].h = 0;
	grp[src.x][src.y].parent.x = grp[src.x][src.y].parent.y = -1;
	pq.push({ 0, src });

	while (!pq.empty()) {
		pair<double, pii> u = pq.top();
		pq.pop();

		++cnt;

		if (u.posi.x == des.x && u.posi.y == des.y) {
			printPath(des, grp, maze);
			return;
		}

		for (int i = 0; i < 8; ++i) {
			pii next = { u.posi.x + X[i], u.posi.y + Y[i] };
			++cnt;

			if (canGo(next, maze)) {
				double newG = grp[u.posi.x][u.posi.y].g + 1;
				double newH = DIST(next, des);
				double newF = newG + newH;

				if (grp[next.x][next.y].f == 69696969 || grp[next.x][next.y].f > newF) {
					pq.push({ newF, next });
					grp[next.x][next.y].g = newG;
					grp[next.x][next.y].h = newH;
					grp[next.x][next.y].f = newF;
					grp[next.x][next.y].parent = u.posi;
				}
			}
		}

	}
}

int main() {
	FAST_IO;
	freopen("output.txt", "w", stdout);

	int maze[9][10] = {
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
	};
	
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << maze[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl;

	pii src = { 0, 0 }, des = { 8, 9 };
	aStarSearch(src, des, maze);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << maze[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << "Number of loops: " << cnt << endl;

	return 0;
}