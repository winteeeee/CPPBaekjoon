/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string status;
vector<int> fixedNum(3);

void input() {
    cin >> status >> fixedNum[0] >> fixedNum[1] >> fixedNum[2];
}

void solve() {
    int result = 0;

    for(int i = 0; i < 12; i++) {
        int curScore = 0;

        if(status[i] == 'N') {
            continue;
        }

        if(i == 0) {    //Ones
            curScore += 2;

            for(int j = 0; j < 3; j++) {
                if(fixedNum[j] == 1) {
                    curScore++;
                }
            }

            result = max(result, curScore);
        } else if(i == 1) { //Twos
            curScore += 4;

            for(int j = 0; j < 3; j++) {
                if(fixedNum[j] == 2) {
                    curScore += 2;
                }
            }

            result = max(result, curScore);
        } else if(i == 2) { //Threes
            curScore += 6;

            for(int j = 0; j < 3; j++) {
                if(fixedNum[j] == 3) {
                    curScore += 3;
                }
            }

            result = max(result, curScore);
        } else if(i == 3) { //Fours
            curScore += 8;

            for(int j = 0; j < 3; j++) {
                if(fixedNum[j] == 4) {
                    curScore += 4;
                }
            }

            result = max(result, curScore);
        } else if(i == 4) { //Fives
            curScore += 10;

            for(int j = 0; j < 3; j++) {
                if(fixedNum[j] == 5) {
                    curScore += 5;
                }
            }

            result = max(result, curScore);
        } else if(i == 5) { //Sixes
            curScore += 12;

            for(int j = 0; j < 3; j++) {
                if(fixedNum[j] == 6) {
                    curScore += 6;
                }
            }

            result = max(result, curScore);
        } else if(i == 6) { //Four of a Kind
            vector<vector<int>> temp(7, vector<int>());

            for(int j = 0; j < 3; j++) {
                temp[fixedNum[j]].push_back(0);
            }

            for(int j = 1; j < 7; j++) {
                if(temp[j].size() >= 2) {
                    curScore = j * 4;
                }
            }

            result = max(result, curScore);
        } else if(i == 7) { //Full House
            vector<vector<int>> temp(7, vector<int>());

            for(int j = 0; j < 3; j++) {
                temp[fixedNum[j]].push_back(0);
            }

            for(int j = 1; j < 7; j++) {
                if(temp[j].size() == 1) {
                    curScore = j * 3;

                    for(int k = 1; k < 7; k++) {
                        if(temp[k].size() == 2) {
                            curScore += (k * 2);
                        }
                    }

                    if(curScore == j * 3) {
                        curScore = 0;
                    }
                } else if(temp[j].size() == 2) {
                    curScore = j * 3;

                    for(int k = 1; k < 7; k++) {
                        if(temp[k].size() == 1) {
                            curScore += (k * 2);
                        }
                    }
                } else if(temp[j].size() == 3){
                    if(j == 6) {
                        curScore = j * 3 + 5 + 5;
                    } else {
                        curScore = j * 3 + 6 + 6;
                    }
                }
            }

            result = max(result, curScore);
        } else if(i == 8) { //Little Straight
            vector<vector<int>> temp(7, vector<int>());

            for(int j = 0; j < 3; j++) {
                temp[fixedNum[j]].push_back(0);
            }

            int count = 0;
            for(int j = 1; j < 6; j++) {
                if(temp[j].size() == 1) {
                    count++;
                }
            }

            if(count == 3) {
                curScore = 30;
            }

            result = max(result, curScore);
        } else if(i == 9) { //Big Straight
            vector<vector<int>> temp(7, vector<int>());

            for(int j = 0; j < 3; j++) {
                temp[fixedNum[j]].push_back(0);
            }

            int count = 0;
            for(int j = 2; j < 7; j++) {
                if(temp[j].size() == 1) {
                    count++;
                }
            }

            if(count == 3) {
                curScore = 30;
            }

            result = max(result, curScore);
        } else if(i == 10) {    //Yacht
            if(fixedNum[0] == fixedNum[1] && fixedNum[1] == fixedNum[2] && fixedNum[2] == fixedNum[0]) {
                curScore = 50;
            }

            result = max(result, curScore);
        } else {    //Choice
            for(int j = 0; j < 3; j++) {
                curScore += fixedNum[j];
            }

            curScore += 12;
            result = max(result, curScore);
        }
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}

*/
