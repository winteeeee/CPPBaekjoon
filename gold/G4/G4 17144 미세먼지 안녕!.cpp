/*
#include <iostream>
using namespace std;

int cordX[4] = {0, 0, 1, -1};
int cordY[4] = {1, -1, 0, 0};

int main() {
    int r, c, t;
    scanf("%d %d %d", &r, &c, &t);
    int house[r + 1][c + 1];
    int spreadDust[51][51] = {0, };
    pair<int, int> airCleaner[2];

    int airCleanerIdx = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &house[i][j]);

            if(house[i][j] == -1) {
                airCleaner[airCleanerIdx] = {i, j};
                airCleanerIdx++;
            }
        }
    }

    for(int l = 0; l < t; l++) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (house[i][j] > 0) {
                    int decrease = 0;
                    for (int k = 0; k < 4; k++) {
                        if (i + cordY[k] > 0 && i + cordY[k] <= r && j + cordX[k] > 0 && j + cordX[k] <= c) {
                            if (house[i + cordY[k]][j + cordX[k]] != -1) {
                                spreadDust[i + cordY[k]][j + cordX[k]] += (house[i][j] / 5);
                                decrease += (house[i][j] / 5);
                            }
                        }
                    }
                    house[i][j] -= decrease;
                }
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                house[i][j] += spreadDust[i][j];
                spreadDust[i][j] = 0;
            }
        }

        for (int i = 0; i < 2; i++) {
            int curAirCleanerR = airCleaner[i].first;
            int curAirCleanerC = airCleaner[i].second;

            if (i == 0) {
                for (int j = curAirCleanerR; j > 1; j--) {
                    if(j == curAirCleanerR) {
                        house[curAirCleanerR - 1][curAirCleanerC] = 0;
                    }

                    else {
                        house[j][curAirCleanerC] = house[j - 1][curAirCleanerC];
                        house[j - 1][curAirCleanerC] = 0;
                    }
                }

                for (int j = curAirCleanerC; j < c; j++) {
                    house[1][j] = house[1][j + 1];
                    house[1][j + 1] = 0;
                }

                for(int j = 1; j < curAirCleanerR; j++) {
                    house[j][c] = house[j + 1][c];
                    house[j + 1][c] = 0;
                }

                for(int j = c; j > curAirCleanerC + 1; j--) {
                    house[curAirCleanerR][j] = house[curAirCleanerR][j - 1];
                    house[curAirCleanerR][j - 1] = 0;
                }
            }

            else {
                for (int j = curAirCleanerR; j < r; j++) {
                    if(j == curAirCleanerR) {
                        house[curAirCleanerR + 1][curAirCleanerC] = 0;
                    }

                    else {
                        house[j][curAirCleanerC] = house[j + 1][curAirCleanerC];
                        house[j + 1][curAirCleanerC] = 0;
                    }
                }

                for (int j = curAirCleanerC; j < c; j++) {
                    house[r][j] = house[r][j + 1];
                    house[r][j + 1] = 0;
                }

                for(int j = r; j > curAirCleanerR; j--) {
                    house[j][c] = house[j - 1][c];
                    house[j - 1][c] = 0;
                }

                for(int j = c; j > curAirCleanerC + 1; j--) {
                    house[curAirCleanerR][j] = house[curAirCleanerR][j - 1];
                    house[curAirCleanerR][j - 1] = 0;
                }
            }
        }
    }

    int sumOfDust = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(house[i][j] != -1)
                sumOfDust += house[i][j];
        }
    }

    printf("%d", sumOfDust);
    return 0;
}*/
