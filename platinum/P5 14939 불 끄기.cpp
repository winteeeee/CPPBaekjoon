#include <iostream>
#include <queue>
using namespace std;

bool bulb[10][10];
int coordX[5] = {0, 0, 0, 1, -1};
int coordY[5] = {0, 1, -1, 0, 0};
class Switches {
public:
    int r;
    int c;
    int offTargetBulbs;
    void setOffTargetBulbsNCoord() {
        int count = 0;
        for(int i = 0; i < 5; i++) {
            if((0 <= r + coordY[i] && r + coordY[i] < 10) && (0 <= c + coordX[i] && c + coordX[i] < 10)) {
                if(bulb[r + coordY[i]][c + coordX[i]])
                    count++;
                else
                    count--;
            }
        }

        offTargetBulbs = count;
    }
};

class comp {
public:
    bool operator() (const Switches &a, const Switches &b) {
        return a.offTargetBulbs < b.offTargetBulbs;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 10; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < 10; j++) {
            if(temp[j] == '#')
                bulb[i][j] = 0;
            else
                bulb[i][j] = 1;
        }
    }

    int count = 0;
    while(1) {
        priority_queue<Switches, vector<Switches>, comp> h;

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                Switches cur = {i, j};
                cur.setOffTargetBulbsNCoord();
                h.push(cur);
            }
        }
        
        int curTargetNum = h.top().offTargetBulbs;
        if(curTargetNum <= -1)
            break;

        for(int i = 0; i < 5; i++)
            bulb[h.top().r + coordY[i]][h.top().c + coordX[i]] ^= 1;
        count++;
    }

    cout << count;
    return 0;
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
