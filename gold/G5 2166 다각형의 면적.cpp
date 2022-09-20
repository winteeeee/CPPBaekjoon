/*
#include <iostream>
#include <vector>
using namespace std;

vector<pair<double, double>> point;
int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        point.push_back({x, y});
    }

    double temp1 = 0;
    double temp2 = 0;
    for(int i = 0; i < n - 1; i++) {
        temp1 += (point[i].first * point[i + 1].second);
        temp2 += (point[i + 1].first * point[i].second);
    }
    temp1 += (point[n - 1].first * point[0].second);
    temp2 += (point[0].first * point[n - 1].second);

    double result = temp1 + (temp2 * -1);

    printf("%.1lf", 0.5 * abs(result));
    return 0;
}*/
