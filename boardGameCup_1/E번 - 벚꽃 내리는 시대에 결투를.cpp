/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, a, l, sumOfLifeDamages;
long long beTakenADamages;
vector<pair<int, int>> v;

void input() {
    cin >> n >> a >> l;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y});
        sumOfLifeDamages += y;

        if(y == -1) {
            beTakenADamages += x;
        }
    }
}

void dfs(int start, int curA, int curL, string path, int sumOfLifeDamage, long long beTakenADamage) {
    for(int i = start; i < n; i++) {
        pair<int, int> attack = v[i];

        if(sumOfLifeDamage < curL) {
            cout << "YES" << '\n';

            for(int j = i; j < n; j++) {
                pair<int, int> attack2 = v[j];
                if (attack2.second == -1) {
                    path += "A";
                } else {
                    path += "L";
                }
            }

            cout << path;
            exit(0);
        }

        if(attack.second == -1) {
            curA = curA - attack.first < 0 ? 0 : curA - attack.first;
            beTakenADamage -= attack.first;
            path += "A";

            if((curA - beTakenADamage <= 0 && curL < sumOfLifeDamage) || (curL <= 0)) {
                return;
            }

            dfs(start + 1, curA, curL, path, sumOfLifeDamage, beTakenADamage);
        } else if(attack.first == -1) {
            curL -= attack.second;
            sumOfLifeDamage -= attack.second;
            path += "L";

            if((curA - beTakenADamage <= 0 && curL < sumOfLifeDamage) || (curL <= 0)) {
                return;
            }

            dfs(start + 1, curA, curL, path, sumOfLifeDamage, beTakenADamage);
        } else {
            if(curA < attack.first) {
                curL -= attack.second;
                sumOfLifeDamage -= attack.second;
                path += "L";

                if((curA - beTakenADamage <= 0 && curL < sumOfLifeDamage) || (curL <= 0)) {
                    return;
                }

                dfs(start + 1, curA, curL, path, sumOfLifeDamage, beTakenADamage);
            } else {
                string aPath = path + "A";
                string lPath = path + "L";
                sumOfLifeDamage -= attack.second;

                if((curA - beTakenADamage <= 0 && curL < sumOfLifeDamage) || (curL <= 0)) {
                    return;
                }

                dfs(start + 1, curA - attack.first, curL, aPath, sumOfLifeDamage, beTakenADamage);
                dfs(start + 1, curA, curL - attack.second, lPath, sumOfLifeDamage, beTakenADamage);
            }
        }
    }

    cout << "YES" << '\n' << path;
    exit(0);
}

void solve() {
    string result = "NO";
    dfs(0, a, l, "", sumOfLifeDamages, beTakenADamages);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
