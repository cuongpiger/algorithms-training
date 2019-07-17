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

void fromDtoB(int row, int col, int height, int width, int &ch, string s, int p){
	if (ch >= s.length() || !width || !height) {
		if (!width || !height) --ch;
		return;
	}
	printf("row = %d, col = %d, height = %d, width = %d, ch = %d, s[ch] = %c, p = %d\n", row, col, height, width, ch, s[ch], p);

	if (s[ch] == '1'){
		//int bit_1 = pow(2, c*1.0) - 1;
		//int bit_1 = pow(2, p*1.0) - 1;
		//int all_1 = pow(2, c*1.0) - 1;
		//int bit_1 = (int)(pow(2, p*1.0) - 1) << (c - p);

		int all_1 = pow(2, c*1.0) - 1;
		int bit_1 = (int)(pow(2, width*1.0) - 1) << (p - 1);
		bit_1 &= all_1;

		for (int i = row; i < row + height; ++i){
			//int tmp = (bit_1 >> (p - 1)) << (p - 1);
			int tmp = bit_1;
			printf("tmp = %d, screen[%d] = %d\n", tmp, i, screen[i]);
			screen[i] += tmp;
			printf("screen[%d] = %d\n\n", i, screen[i]);
		}

		return;
	}
	else if (s[ch] == 'D'){
		fromDtoB(row, col, height / 2 + height % 2, width / 2 + width % 2, ++ch, s, p + width / 2);
		fromDtoB(row, col + width / 2 + width % 2, height / 2 + height % 2, width / 2, ++ch, s, p);
		fromDtoB(row + height / 2 + height % 2, col, height / 2, width / 2 + width % 2, ++ch, s, p + width / 2);
		fromDtoB(row + height / 2 + height % 2, col + width / 2 + width % 2, height / 2, width / 2, ++ch, s, p);
	}
	else {
		cout << endl << endl;
	}
}

int decimalToBinary(int N)
{

	// To store the binary number 
	ll B_Number = 0;
	int cnt = 0;
	while (N != 0) {
		int rem = N % 2;
		ll c = pow(10, cnt);
		B_Number += rem * c;
		N /= 2;

		// Count used to store exponent value 
		cnt++;
	}

	return B_Number;
}

int main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);*/
	char func;
	string s, cp;

	while (cin >> func, func != '#'){
		cin >> r >> c >> s;

		if (func == 'B'){
			screen.resize(r);
			for (int i = 0; i < r; ++i){
				s.copy((char *)cp.c_str(), c, i*c);
				screen[i] = stoi(cp, nullptr, 2);
			}

			fromBtoD(0, 0, r, c, 1);
		}
		else{
			int ch = 0;
			screen.resize(r,0 /*pow(2, c*1.0) - 1*/);
			fromDtoB(0, 0, r, c, ch, s, 1);

			for (int i = 0; i < r; ++i){
				cout << decimalToBinary(screen[i]);
			}
		}
	}



	return 0;
}