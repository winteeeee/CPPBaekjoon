/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
class human {
public:
    int bib;
    int a;
    int b;
    int c;
    int mul;
    int sum;
    human(int b, int aN, int bN, int cN) {
        bib = b;
        a = aN;
        b = bN;
        c = cN;
        mul = a * b * c;
        sum = a + b + c;
    }
};
vector<human> m;
bool comp(human &a, human &b) {
    if(a.mul == b.mul) {
        if(a.sum == b.sum) {
            return a.bib < b.bib;
        }

        else {
            return a.sum < b.sum;
        }
    }

    else {
        return a.mul < b.mul;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int bib, a, b, c;
        cin >> bib >> a >> b >> c;
        m.push_back(human(bib, a, b, c));
    }

    sort(m.begin(), m.end(), comp);
    for(int i = 0; i < 3; i++) {
        cout << m[i].bib << " ";
    }

    return 0;
}
*/
