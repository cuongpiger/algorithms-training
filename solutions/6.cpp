#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FILE_IO {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)

/*
We have 2 strings s and t with the same length. A solution is correct if all the result
(is called as res variable) greater than s and less than t (do not care about the order
of the string based on alphabet)
 */


int main() {
    FAST_IO;
    // FILE_IO;

    string s, t;
    cin >> s >> t;

    for (int i = s.size() - 1; i > -1; --i) {
        if (s[i] < 'z') {
            s[i] += 1;

            for (int j = i + 1; j < s.size(); ++j) {
                s[j] = 'a';
            }

            break;
        }
    }

    cout << (s < t ? s : "No such string");

    return 0;
}