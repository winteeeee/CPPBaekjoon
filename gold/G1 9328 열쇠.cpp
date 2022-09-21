#include <iostream>
#include <queue>
using namespace std;

void solve();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
        solve();
    return 0;
}

void solve() {
    int h, w;
    cin >> h >> w;

    char map[h + 2][w + 2];
    vector<char> key;
    for(int i = 0; i < h; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < w; j++) {
            map[i][j] = temp[j];
        }
    }

    string obtainedKey;
    cin >> obtainedKey;
    for(int i = 0; i < obtainedKey.size(); i++)
        key.push_back(obtainedKey[i]);


}

/*
 * A - 65 ~ Z - 90
 * a - 97 ~ z - 122
 */