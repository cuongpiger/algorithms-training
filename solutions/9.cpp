#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

int cnt[110] = {0};

int main() {
    FAST_IO;
    // FILE_IO;

    int n, k, pwl, resl = 0, resr;
    string pw;

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> pw;
        cnt[pw.length()] += 1;
    }

    cin >> pw;

    for (int i = 0; i < pw.length(); ++i) {
        resl += cnt[i];
    }

    resr = resl + cnt[pw.length()] - 1;


    resl += ((int)(resl / k)) * 5 + 1;
    resr += ((int)(resr / k)) * 5 + 1;

    cout << resl <<  " " << resr;

    return 0;
}