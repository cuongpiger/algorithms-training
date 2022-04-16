// O(n*log(n)) with n = 8

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int X[1000010] = {0}, Y[1000010] = {0};
    vector<int> x, y;
    set<pair<int, int>> ip;

    for (int a, b, k = 0; k < 8; ++k) {
        cin >> a >> b;

        if (X[a] == 0) {
            x.push_back(a);
        }

        if (Y[b] == 0) {
            y.push_back(b);
        }

        ip.insert({a, b});

        X[a] += 1;
        Y[b] += 1;
    }

    if (x.size() != 3 || y.size() != 3 || ip.size() != 8) {
        cout << "ugly";
        return 0;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int d[] = {3, 2, 3};
    for (int i = 0; i < 3; ++i) {
        if (X[x[i]] != d[i] || Y[y[i]] != d[i]) {
            cout << "ugly";
            return 0;
        } 
    }

    cout << "respectable";

    return 0;
}