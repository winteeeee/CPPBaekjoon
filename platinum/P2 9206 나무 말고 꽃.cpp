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

double long risingFactorial(double long a, int num) {
    if (num == 0) {
        return 1;
    }

    double long result = 1;
    for (int i = 0; i < num; i++) {
        result *= (a + i);
    }

    return result;
}

double long exponentialIntegralE(double long x) {
    /*
     * Exponential Integral을 구하기 위하여
     * Incomplete gamma function을 구해야함.
     * 이를 구하기 위해 Confluent Hypergeometric function 사용
     */

    double long sigma = -1;
    double long nextVal = 0;
    for (int i = 0; nextVal != sigma; i++) {
        sigma = nextVal;
        nextVal += (risingFactorial(0.75, i) * pow(-x, i)) / (risingFactorial(1.75, i) * tgamma(i + 1));
        //tgamma(n + 1) == n!
    }

    return pow(x, -0.75) * (tgamma(0.75) - (1.33333 * pow(x, 0.75) * sigma));
}

double long a(const Vase& vase) {
    return pow(2 * M_PI, 0.5) * pow(vase.a, 2) * erf(vase.h * pow(2, 0.5));
}

double long b(const Vase& vase) {
    double long check1 = 2 * vase.b;
    double long check2 = -2 * vase.a * pow(vase.h, 1.5);
    double long check3 = exponentialIntegralE(pow(vase.h, 2));
    double long check4 = vase.b * pow(vase.h, 2);
    double long check5 = 2 * vase.a * tgamma(0.75);

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
    cout << findVolume(vases[0]) << '\n';
    int result = 0;
    for (int i = 1; i < n; i++) {
        double long volume = findVolume(vases[i]);
        cout << volume << '\n';

        if (abs(v - volume) < minDiff) {
            minDiff = abs(v - volume);
            result = i;
        }
    }

    cout << result;
    return 0;
}
