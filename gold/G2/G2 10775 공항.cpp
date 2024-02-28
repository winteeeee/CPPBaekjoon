/*
#include <iostream>
#include <algorithm>
using namespace std;

int gate[100001];
bool docked[100001];
int g, p;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> g >> p;
    for(int i = 0; i <= g; i++)
        gate[i] = i;

    int count = 0;
    for(int i = 0; i < p; i++) {
        int gi;
        cin >> gi;
        int lower = lower_bound(gate, gate + g, gi) - gate;

        if(!docked[lower])
            docked[lower] = true;
        else {
            while(docked[lower - 1])
                lower = lower_bound(gate, gate + g, gate[lower - 1]) - gate;
            if(lower - 1 == 0)
                break;

            gate[lower - 1] = gate[lower];
            docked[lower - 1] = true;
        }

        count++;
    }

    cout << count;
    return 0;
}*/
