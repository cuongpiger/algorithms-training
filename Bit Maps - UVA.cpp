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
using namespace std;

//=============================================================================================
#define pw(a) ((a) * (a))
#define x first
#define y second
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

/**
 ** Comment **
 **/

void fromBtoD(vector<vector<int>> &bm, int row_s, int col_s, int row_e, int col_e, int &cnt){
	if (row_s >= row_e || col_s >= col_e) return;

	int cntBit_0 = 0;

	for (int i = row_s; i < row_e; ++i){
		cntBit_0 += (count(bm[i].begin() + col_s, bm[i].begin() + col_e, 0));
	}

	if (cnt > 0 && !(cnt % 50)){
		cout << endl;
	}
	++cnt;

	if (cntBit_0 == (col_e - col_s)*(row_e - row_s)){
		cout << "0";
	}
	else if (!cntBit_0){
		cout << "1";
	}
	else{
		cout << "D";

		int rowHalf = (row_s + row_e + 1) / 2;
		int colHalf = (col_s + col_e + 1) / 2;
		fromBtoD(bm, row_s, col_s, rowHalf, colHalf, cnt);
		fromBtoD(bm, row_s, colHalf, rowHalf, col_e, cnt);
		fromBtoD(bm, rowHalf, col_s, row_e, colHalf, cnt);
		fromBtoD(bm, rowHalf, colHalf, row_e, col_e, cnt);
	}
}

void fromDtoB(vector<vector<int>> &bm, int row_s, int col_s, int row_e, int col_e){
	if (row_s >= row_e || col_s >= col_e) return;
	int ch = cin.get();

	if (ch == '0' || ch == '1'){
		for (int i = row_s; i < row_e; ++i){
			for (int j = col_s; j < col_e; ++j){
				bm[i][j] = ch - '0';
			}
		}

		return;
	}
	else {
		int rowHalf = (row_s + row_e + 1) / 2;
		int colHalf = (col_s + col_e + 1) / 2;
		fromDtoB(bm, row_s, col_s, rowHalf, colHalf);
		fromDtoB(bm, row_s, colHalf, rowHalf, col_e);
		fromDtoB(bm, rowHalf, col_s, row_e, colHalf);
		fromDtoB(bm, rowHalf, colHalf, row_e, col_e);
	}
}

int main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);*/
	char func;
	int row, col;

	while (cin >> func, func != '#'){
		cin >> row >> col; cin.ignore();
		cout << (func == 'B' ? "D" : "B") << right << setw(4) << row << right << setw(4) << col << endl;
		
		vector<vector<int>> bm(row, vector<int>(col));
		if (func == 'B'){
			string input;
			while (input.length() < row *col){
				string tmp;
				getline(cin, tmp);
				input += tmp;
			}

			for (int i = 0; i < row; ++i){
				for (int j = 0; j < col; ++j){
					bm[i][j] = input[col *i + j] - '0';
				}
			}

			int cnt = 0; // count the number of characters was printed on a line
			fromBtoD(bm, 0, 0, row, col, cnt);
			cout << endl;
		}
		else{
			fromDtoB(bm, 0, 0, row, col);
			for (int i = 0; i < row; ++i){
				for (int j = 0; j < col; ++j){
					if (i + j > 0 && !((col*i + j) % 50)){
						cout << endl;
					}
					cout << bm[i][j];
				}
			}

			cout << endl;
		}
	}

	return 0;
}