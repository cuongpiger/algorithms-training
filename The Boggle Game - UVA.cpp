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
#include <sstream>
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

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=545
/**
 ** Comment **
 https://www.geeksforgeeks.org/boggle-set-2-using-trie/
 **/

vector<int> dic = { 'A', 'E', 'I', 'O', 'U', 'Y' };
const pii direc[] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int m1[4][4], m2[4][4];

inline bool isSafe(int &x, int &y, vector<vector<bool>> &vs) {
	if ((x > -1 && x < 4) && (y > -1 && y < 4) && !vs[x][y])
		return 1;
	return 0;
}

inline bool compare(int &x) {
	vector<int>::iterator it = find(dic.begin(), dic.end(), x);
	return it != dic.end();
}

void solve(int x, int y, int c_vo, int c_con, int m[][4], vector<vector<bool>> &vs, string box, map<string, int> &truck) {
	if (!isSafe(x, y, vs)) return;

	vs[x][y] = 1;
	box.push_back((char)m[x][y]);

	if (c_con == 4) {
		vs[x][y] = 0;
		if (c_vo == 2)
			++truck[box];

		return;
	}

	for (int i = 0; i < 8; ++i) {
		pii posNext = make_pair(x + direc[i].first, y + direc[i].second);
		solve(posNext.first, posNext.second, c_vo + compare(m[posNext.first][posNext.second]), c_con + 1, m, vs, box, truck);
	}

	vs[x][y] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	string br = "no", line;

	while (1) {
		vector<vector<bool>> vs1(4, vector<bool>(4, 0));
		vector<vector<bool>> vs2(4, vector<bool>(4, 0));
		map<string, int> truck1;
		map<string, int> truck2;

		for (int i = 0; i < 4; ++i) {
			getline(cin, line);
			if (line == "#") return 0;
			sscanf(line.c_str(), "%c %c %c %c %c %c %c %c", &m1[i][0], &m1[i][1], &m1[i][2], &m1[i][3], &m2[i][0], &m2[i][1], &m2[i][2], &m2[i][3]);
		}

		if (br == "") cout << endl;

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				string box;
				solve(i, j, compare(m1[i][j]), 1, m1, vs1, box, truck1);
			}
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				string box;
				solve(i, j, compare(m2[i][j]), 1, m2, vs2, box, truck2);
			}
		}

		for (map<string, int>::iterator it = truck2.begin(); it != truck2.end(); ++it) {
			if (truck1.count(it->first) > 0) {
				cout << it->first << endl;
				br = "1";
			}
		}

		if (br != "1") cout << "There are no common words for this pair of boggle boards." << endl;
		getline(cin, br);
	}

	return 0;
}
