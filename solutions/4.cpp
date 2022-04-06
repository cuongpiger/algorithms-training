#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int main() {
    FAST_IO;
    // FILE_IO;

    int n, itp, turnOffTv = 15;
    bool off = false;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> itp;

        if (itp <= turnOffTv && off == false) {
            turnOffTv = itp + 15;
        } else {
            off = true;
        }
    }

    cout << min(90, turnOffTv);


    return 0;
}