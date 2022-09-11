#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int chickenDistanceOfCity = 0;
int result = INT_MAX;
int city[51][51];
bool visited[51][51];
bool visited2[51][51];
int cordX[4] = {0, 0, 1, -1};
int cordY[4] = {1, -1, 0, 0};

int findChickenDistance(int r, int c, int n);
void shutDown(int shutDownCount, int m, int n, int r, int c) {
    if(shutDownCount == m + 1 && !visited[r][c]) {
        visited[r][c] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(city[i][j] == 1 && !visited2[i][j]) {
                    chickenDistanceOfCity += findChickenDistance(i, j, n);

                    for(int i = 1; i <= n; i++) {
                        for(int j = 1; j <= n; j++) {
                            visited2[i][j] = false;
                        }
                    }
                }
            }
        }

        if(result > chickenDistanceOfCity) {
            result = chickenDistanceOfCity;
        }
        chickenDistanceOfCity = 0;
        return;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(city[i][j] == 2) {
                if(shutDownCount != m) {
                    city[i][j] = 0;
                    shutDown(shutDownCount + 1, m, n, i, j);
                    city[i][j] = 2;
                }

                else {
                    shutDown(shutDownCount + 1, m, n, i, j);
                }
            }
        }
    }
}

int findChickenDistance(int r, int c, int n) {
    queue<int> q;
    int result = 0;
    q.push(r);
    q.push(c);
    q.push(0);
    visited2[r][c] = true;

    while(!q.empty()) {
        int curR = q.front(); q.pop();
        int curC = q.front(); q.pop();
        int count = q.front(); q.pop();

        if(city[curR][curC] == 2) {
            result = count;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int rIdx = curR + cordY[i];
            int cIdx = curC + cordX[i];
            if((rIdx > 0 && rIdx <= n) && (cIdx > 0 && cIdx <= n)) {
                if(!visited2[rIdx][cIdx]) {
                    q.push(rIdx);
                    q.push(cIdx);
                    q.push(count + 1);
                    visited2[rIdx][cIdx] = true;
                }
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int chickenHouse = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &city[i][j]);

            if(city[i][j] == 2)
                chickenHouse++;
        }
    }

    shutDown(0, chickenHouse - m, n, 1, 1);
    printf("%d", result);

    return 0;
}