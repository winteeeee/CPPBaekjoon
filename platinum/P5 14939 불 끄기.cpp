#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool bulb[10][10];
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

    return 0;
}