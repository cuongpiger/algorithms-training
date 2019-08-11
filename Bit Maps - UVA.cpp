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

//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=119
/**
 ** Comment **
 **/

vector<vector<int>> bm;

inline int checkBitMap(int &row, int &col, int &height, int &width){
	int sum = 0;

	for (int i = row; i < row + height; ++i){
		for (int j = col; j < col + width; ++j){
			sum += bm[i][j];
		}
	}

	return sum;
}

string fromBtoD(int row, int col, int height, int width){
	if (height <= 0 || width <= 0) return "";

	int sum = checkBitMap(row, col, height, width);
	if (!sum){
		return "0";
	}
	else if (sum == width * height){
		return "1";
	}

	int widthHalf = (width + 1) / 2;
	int heightHalf = (height + 1) / 2;
	return "D" + fromBtoD(row, col, heightHalf, widthHalf)
		+ fromBtoD(row, col + widthHalf, heightHalf, width / 2)
		+ fromBtoD(row + heightHalf, col, height / 2, widthHalf)
		+ fromBtoD(row + heightHalf, col + widthHalf, height / 2, width / 2);
}

void fromDtoB(vector<string> &dest, int row, int col, int height, int width){
	if (height <= 0 || width <= 0) return;

	char ch; cin >> ch;

	if (ch == '1'){
		string strReplace(width, '1');
		for (int i = row; i < row + height; ++i){
			dest[i].replace(col, width, strReplace);
		}
		return;
	}
	else if (ch == 'D') {
		int widthHalf = (width + 1) / 2;
		int heightHalf = (height + 1) / 2;
		fromDtoB(dest, row, col, heightHalf, widthHalf);
		fromDtoB(dest, row, col + widthHalf, heightHalf, width / 2);
		fromDtoB(dest, row + heightHalf, col, height / 2, widthHalf);
		fromDtoB(dest, row + heightHalf, col + widthHalf, height / 2, width / 2);
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
		bm.clear();
		string res = "";

		if (func == 'B'){
			for (int i = 0; i < row; ++i){
				vector<int> tmp;
				for (int j = 0; j < col; ++j){
					char ch; cin >> ch;
					tmp.push_back((int)(ch - '0'));
				}
				bm.push_back(tmp);
			}

			res = fromBtoD(0, 0, row, col);
		}
		else{
			vector<string> dest(row, string(col, '0'));
			fromDtoB(dest, 0, 0, row, col);

			for (int i = 0; i < row; ++i){
				res += dest[i];
			}
		}

		for (int i = 0; i < (int)res.size(); ++i) {
			cout << res[i];
			if ((i + 1) % 50 == 0 || i == (int)res.size() - 1) {
				cout << endl;
			}
		}
	}

	return 0;
}
