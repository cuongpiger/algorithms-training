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
vector<int> screen;
int r, c;

inline int bitExtracted(int number, int k, int p)
{
	return (((1 << k) - 1) & (number >> (p - 1)));
}

void fromBtoD(int row, int col, int height, int width, int p){
	if (!width || !height) return;
	int sum = 0;

	for (int i = row; i < row + height; ++i){
		sum += bitExtracted(screen[i], width, p);
	}

	if (sum == 0){
		cout << "0";
	}
	else if (sum == (pow(2, width*1.0) - 1)*height){
		cout << "1";
	}
	else {
		cout << "D";
		fromBtoD(row, col, height / 2 + height % 2, width / 2 + width % 2, p + width / 2);
		fromBtoD(row, col + width / 2 + width % 2, height / 2 + height % 2, width / 2, p);
		fromBtoD(row + height / 2 + height % 2, col, height / 2, width / 2 + width % 2, p + width / 2);
		fromBtoD(row + height / 2 + height % 2, col + width / 2 + width % 2, height / 2, width / 2, p);
	}
}

void fromDtoB(int row, int col, int height, int width, int &ch, string &s, int p){
	if (ch >= s.length() || !width || !height) {
		if (!width || !height) --ch;
		return;
	}
	//printf("row = %d, col = %d, height = %d, width = %d, ch = %d, s[ch] = %c, p = %d\n", row, col, height, width, ch, s[ch], p);

	if (s[ch] == '1'){
		int all_1 = pow(2, c*1.0) - 1;
		int bit_1 = (int)(pow(2, width*1.0) - 1) << (p - 1);
		bit_1 &= all_1;

		for (int i = row; i < row + height; ++i){
			//printf("bit_1 = %d, screen[%d] = %d\n", bit_1, i, screen[i]);
			screen[i] += bit_1;
			//printf("screen[%d] = %d\n\n", i, screen[i]);
		}

		return;
	}
	else if (s[ch] == 'D'){
		fromDtoB(row, col, height / 2 + height % 2, width / 2 + width % 2, ++ch, s, p + width / 2);
		fromDtoB(row, col + width / 2 + width % 2, height / 2 + height % 2, width / 2, ++ch, s, p);
		fromDtoB(row + height / 2 + height % 2, col, height / 2, width / 2 + width % 2, ++ch, s, p + width / 2);
		fromDtoB(row + height / 2 + height % 2, col + width / 2 + width % 2, height / 2, width / 2, ++ch, s, p);
	}
}

inline string show_binary(unsigned int u, int num_of_bits)
{
	string a = "";

	int t = pow(2, num_of_bits);   // t is the max number that can be represented

	for (t; t > 0; t = t / 2)           // t iterates through powers of 2
		if (u >= t){                // check if u can be represented by current value of t
			u -= t;
			a += "1";               // if so, add a 1
		}
		else {
			a += "0";               // if not, add a 0
		}

		return a;                     // returns string
}

int main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);*/
	char func;

	while (cin >> func, func != '#'){
		string s;
		cin >> r >> c;
		cin.ignore();

		while (s.length() < r * c) {
			string tmp;
			getline(cin, tmp);
			s += tmp;
		}
		cout << endl;
		cout << s << endl;

		screen.clear();
		screen.resize(r, 0);
		cout << (func == 'B' ? "D" : "B") << right << setw(4) << r << right << setw(4) << c << endl;

		if (func == 'B'){
			for (int i = 0; i < r; ++i){
				cout << s.substr(i*c, c) << endl;
				screen[i] = stoi(s.substr(i*c, c), nullptr, 2);
			}

			fromBtoD(0, 0, r, c, 1);
			cout << endl;
		}
		else{
			int ch = 0;
			fromDtoB(0, 0, r, c, ch, s, 1);

			for (int i = 0; i < r; ++i){
				cout << show_binary(screen[i], c - 1);
			}
			cout << endl;
		}
	}

	return 0;
}