/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Vase {
public:
    double long a;
    double long b;
    double long h;
};

double long v;
int n;
vector<Vase> vases;

double long exponentialIntegralE(double long x) {
    double long sigma = -1;
    double long nextVal = 0;
    for (int i = 0; sigma != nextVal; i++) {
        sigma = nextVal;
        nextVal += pow(x, i) / tgamma(1.75 + i);
    }

    return pow(x, -0.75) * (tgamma(0.75) - pow(x, 0.75) * sigma * tgamma(0.75) * pow(M_E, -x));
}

double long a(const Vase& vase) {
    return pow(2 * M_PI, 0.5) * pow(vase.a, 2) * erf(vase.h * pow(2, 0.5));
}

double long b(const Vase& vase) {
    return 2 * vase.b * (-2 * vase.a * pow(vase.h, 1.5) * exponentialIntegralE(pow(vase.h, 2)) + 2 * vase.a * tgamma(0.75) + vase.b * pow(vase.h, 2));
}

double long findVolume(const Vase& vase) {
    return 0.25 * M_PI * (a(vase) + b(vase));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> n;
    for (int i = 0; i < n; i++) {
        double long a, b, h;
        cin >> a >> b >> h;
        vases.push_back({a, b, h});
    }

    double long minDiff = abs(v - findVolume(vases[0]));
    int result = 0;
    for (int i = 1; i < n; i++) {
        double long volume = findVolume(vases[i]);

        if (abs(v - volume) < minDiff) {
            minDiff = abs(v - volume);
            result = i;
        }
    }

    cout << result;
    return 0;
}
*/
