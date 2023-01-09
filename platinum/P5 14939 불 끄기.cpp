#include <iostream>
using namespace std;

bool table[10][10];
int xRange[5] {-1, 1, 0, 0, 0};
int yRange[5] {0, 0, -1, 1, 0};
void input();
void solve();
void convertSwitch(int i, int j);
void print();
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}

void input() {
    char temp;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> temp;

            if(temp == '#') {
                table[i][j] = 0;
            }

            else {
                table[i][j] = 1;
            }
        }
    }
}

void solve() {

}

void convertSwitch(int i, int j) {
    for(int k = 0; k < 5; k++) {
        if((0 <= i + yRange[k] && i + yRange[k] < 10) && (0 <= j + xRange[k] && j + xRange[k] < 10)) {
            table[i + yRange[k]][j + xRange[k]] = !table[i + yRange[k]][j + xRange[k]];
        }
    }
}

void print() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(table[i][j]) {
                cout << 'O';
            }

            else {
                cout << '#';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

/*
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########

#O########
OOO#######
#O########
####OO####
###O##O###
####OO####
##########
########O#
#######OOO
########O#
 4

O########O
#OOOOOOOO#
#OOOOOOOO#
#OOOOOOOO#
#OOOOOOOO#
#OOOOOOOO#
#OOOOOOOO#
#OOOOOOOO#
#OOOOOOOO#
O########O
 100
 */

