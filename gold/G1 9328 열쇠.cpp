/*
#include <iostream>
#include <queue>
using namespace std;

int cordX[4] = {0, 0, -1, 1};
int cordY[4] = {1, -1, 0, 0};

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

    char map[102][102];
    bool visited[102][102] = {false};
    vector<char> key;

    for(int i = 0; i < w + 2; i++) {
        map[0][i] = '.';
        map[h + 1][i] = '.';
    }

    for(int i = 1; i < h + 1; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < w + 2; j++) {
            if(j == 0 || j == w + 1)
                map[i][j] = '.';

            else
                map[i][j] = temp[j - 1];
        }
    }

    string obtainedKey;
    cin >> obtainedKey;
    for(int i = 0; i < obtainedKey.size(); i++)
        key.push_back(obtainedKey[i]);

    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26];
    visited[0][0] = true;
    q.push({0, 0});
    int count = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int r = cur.first;
        int c = cur.second;

        for(int i = 0; i < 4; i++) {
            if(r + cordY[i] >= 0 && r + cordY[i] < h + 2 && c + cordX[i] >= 0 && c + cordX[i] < w + 2) {
                if (!visited[r + cordY[i]][c + cordX[i]] && map[r + cordY[i]][c + cordX[i]] != '*') {

                    if (map[r + cordY[i]][c + cordX[i]] == '.') {
                        visited[r + cordY[i]][c + cordX[i]] = true;
                        q.push({r + cordY[i], c + cordX[i]});
                    }

                    else if (map[r + cordY[i]][c + cordX[i]] == '$') {
                        visited[r + cordY[i]][c + cordX[i]] = true;
                        q.push({r + cordY[i], c + cordX[i]});
                        count++;
                    }

                    else if (map[r + cordY[i]][c + cordX[i]] >= 'A' && map[r + cordY[i]][c + cordX[i]] <= 'Z') {
                        //문이라면

                        for (int l = 0; l < key.size(); l++) {
                            if (map[r + cordY[i]][c + cordX[i]] + 32 == key[l]) {
                                visited[r + cordY[i]][c + cordX[i]] = true;
                                q.push({r + cordY[i], c + cordX[i]});
                                continue;
                            }
                        }

                        door[map[r + cordY[i]][c + cordX[i]] - 65].push({r + cordY[i], c + cordX[i]});
                    }

                    else {
                        //열쇠라면

                        key.push_back(map[r + cordY[i]][c + cordX[i]]);
                        while(!door[map[r + cordY[i]][c + cordX[i]] - 97].empty()) {
                            pair<int, int> doorPosition = door[map[r + cordY[i]][c + cordX[i]] - 97].front();
                            door[map[r + cordY[i]][c + cordX[i]] - 97].pop();
                            visited[doorPosition.first][doorPosition.second] = true;
                            q.push(doorPosition);
                        }

                        visited[r + cordY[i]][c + cordX[i]] = true;
                        q.push({r + cordY[i], c + cordX[i]});
                    }
                }
            }
        }
    }

    cout << count << "\n";
}

*/
/*
 * A - 65 ~ Z - 90
 * a - 97 ~ z - 122
 */*/
