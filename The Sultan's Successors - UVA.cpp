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
#define _x first
#define _y second
#define vit vector<int>::iterator
#define _cin(X) int (X); cin >> X
const double pi = 3.14159265359;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
int _gcd(int a, int b) { return !b ? a : _gcd(b, a %b); }
inline double _distance(const pii &a, const pii &b) { return sqrt(pw((double)(a._x - b._x)) + pw((double)(a._y - b._y))); }
//=============================================================================================

//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=103
/**
** Comment **
**/

int board[8][8], score, sum;
bool graveAccent[15], acuteAccent[15], col[8];

void bt(int row) {
	if (row == 8) {
		score = max(score, sum);
		return;
	}

	for (int i = 0; i < 8; ++i) {
		if (!col[i] && !graveAccent[row - i + 7] && !acuteAccent[row + i]) {
			col[i] = graveAccent[row - i + 7] = acuteAccent[row + i] = true;
			sum += board[row][i];
			bt(row + 1);

			col[i] = graveAccent[row - i + 7] = acuteAccent[row + i] = false;
			sum -= board[row][i];
		}
	}
}
																					
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	_cin(tc);
	while (tc--) {
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j) cin >> board[i][j];

		score = -69, sum = 0;
		bt(0);
		cout << setw(5) << setiosflags(ios::right) << score << endl;
	}

	return 0;
}
