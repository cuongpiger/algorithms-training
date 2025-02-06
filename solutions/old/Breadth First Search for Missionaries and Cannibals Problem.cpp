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

typedef struct State {
	// current
	int nMis, nCan;
	int curBank;
	
	// parent
	int pMis, pCan;
	int pBank;

	State() {
		nMis = nCan = 0;
		curBank = -1;
		pMis = pCan = pBank = -1;
	}

	State(int m, int c, int cB, int pmis, int pcan, int pbank) {
		nMis = m;
		nCan = c;
		curBank = cB;
		pMis = pmis;
		pCan = pcan;
		pBank = pbank;
	}
} State;

pii option[] = { {1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 1} };
State states[2][5][5];
#define mis first
#define can second

inline bool isSafe(int noMis, int noCan) {
	if (noMis < 0 || noMis > 3 || noCan < 0 || noCan > 3 || (noCan > noMis && noMis != 0)) {
		return false;
	}

	return true;
}

inline void bfs() {
	queue<State> q;
	q.push(State(3, 3, 0, -1, -1, -1));
	states[0][3][3] = State(3, 3, 0, -1, -1, -1);

	while (!q.empty()) {
		State u = q.front();
		q.pop();

		if (u.nMis == 3 && u.nCan == 3 && u.curBank == 1) {
			return;
		}

		for (int i = 0; i < 5; ++i) {
			int newMis = 3 - u.nMis + option[i].mis;
			int newCan = 3 - u.nCan + option[i].can;
			int newBank = 1 - u.curBank;
			int new_uMis = u.nMis - option[i].mis;
			int new_uCan = u.nCan - option[i].can;
			
			if (states[newBank][newMis][newCan].curBank == -1 && isSafe(new_uMis, new_uCan) && isSafe(newMis, newCan)) {
				State v = State(newMis, newCan, newBank, u.nMis, u.nCan, u.curBank);
				states[newBank][newMis][newCan] = v;
				q.push(v);
			}
		}
	}
}

void printPath(int _mis, int _can, int _bank) {
	if (_bank == -1) {
		return;
	}

	State atState = states[_bank][_mis][_can];
	printPath(atState.pMis, atState.pCan, atState.pBank);
	printf("At %d: %d - %d\n", atState.curBank, atState.nMis, atState.nCan);
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);
	bfs();
	printPath(3, 3, 1);
	
	return 0;
}
