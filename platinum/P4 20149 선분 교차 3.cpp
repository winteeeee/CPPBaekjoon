#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Segment {
private:
    pair<double, double> point1;
    pair<double, double> point2;

public:
    Segment(int x1, int y1, int x2, int y2);
    pair<double, double> getPoint1();
    pair<double, double> getPoint2();
};

Segment::Segment(int x1, int y1, int x2, int y2) {
    point1 = {x1, y1};
    point2 = {x2, y2};
}

pair<double, double> Segment::getPoint1() {
    return point1;
}

pair<double, double> Segment::getPoint2() {
    return point2;
}

long long ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c);
bool isCross(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Segment> segments;
    for(int i = 0; i < 2; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments.push_back(Segment(x1, y1, x2, y2));
    }

    if(isCross(segments[0].getPoint1(), segments[0].getPoint2(), segments[1].getPoint1(), segments[1].getPoint2())) {
        cout << "1" << "\n";

        double temp1 = segments[0].getPoint2().second - segments[0].getPoint1().second;
        double temp2 = segments[0].getPoint2().first - segments[0].getPoint1().first;
        double temp3 = segments[1].getPoint2().second - segments[1].getPoint1().second;
        double temp4 = segments[1].getPoint2().first - segments[1].getPoint1().first;
        double seg1Angle = temp1 / temp2;
        double seg2Angle = temp3 / temp4;
        double x = abs((seg1Angle * segments[0].getPoint1().first * -1 + segments[0].getPoint1().second) - (seg2Angle * segments[1].getPoint1().first * - 1 + segments[1].getPoint1().second)) / abs(seg1Angle - seg2Angle);
        double y = seg1Angle * x - seg1Angle * segments[0].getPoint1().first + segments[0].getPoint1().second;

        if(!isnan(x) && !isnan(y) && seg1Angle != seg2Angle)
            cout << x << " " << y;

        else if(isnan(x) && isnan(y) && seg1Angle == seg2Angle) {
            if(segments[0].getPoint1().first == segments[1].getPoint1().first && segments[0].getPoint1().second == segments[1].getPoint1().second) {
                if(segments[0].getPoint2().first < segments[0].getPoint1().first && segments[0].getPoint1().first < segments[1].getPoint2().first ||
                   segments[1].getPoint2().first < segments[0].getPoint1().first && segments[0].getPoint1().first < segments[0].getPoint2().first)
                    if(segments[0].getPoint2().first != segments[1].getPoint2().first)
                        cout << segments[0].getPoint1().first << " " << segments[0].getPoint1().second;
            }

            if(segments[0].getPoint1().first == segments[1].getPoint2().first && segments[0].getPoint1().second == segments[1].getPoint2().second) {
                if(segments[0].getPoint2().first < segments[0].getPoint1().first && segments[0].getPoint1().first < segments[1].getPoint1().first ||
                   segments[1].getPoint1().first < segments[0].getPoint1().first && segments[0].getPoint1().first < segments[0].getPoint2().first) {
                    if(segments[0].getPoint2().first != segments[1].getPoint1().first)
                        cout << segments[0].getPoint1().first << " " << segments[0].getPoint1().second;
                }
            }

            if(segments[0].getPoint2().first == segments[1].getPoint1().first && segments[0].getPoint2().second == segments[1].getPoint1().second) {
                if(segments[0].getPoint1().first < segments[0].getPoint2().first && segments[0].getPoint2().first < segments[1].getPoint2().first ||
                   segments[1].getPoint2().first < segments[0].getPoint2().first && segments[0].getPoint2().first < segments[0].getPoint1().first) {
                    if(segments[0].getPoint1().first != segments[1].getPoint2().first)
                        cout << segments[0].getPoint2().first << " " << segments[0].getPoint2().second;
                }
            }

            if(segments[0].getPoint2().first == segments[1].getPoint2().first && segments[0].getPoint2().second == segments[1].getPoint2().second) {
                if(segments[0].getPoint1().first < segments[0].getPoint2().first && segments[0].getPoint2().first < segments[1].getPoint1().first ||
                   segments[1].getPoint1().first < segments[0].getPoint2().first && segments[0].getPoint2().first < segments[0].getPoint1().first) {
                    if(segments[0].getPoint1().first != segments[1].getPoint1().first)
                        cout << segments[0].getPoint2().first << " " << segments[0].getPoint2().second;
                }
            }
        }
    }

    else
        cout << "0";

    return 0;
}

long long ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    long long val = (a.first * b.second) + (b.first * c.second) + (c.first * a.second) - ((a.first * c.second) + (b.first * a.second) + (c.first * b.second));

    if(val < 0)
        return -1;

    else if(val > 0)
        return 1;

    else
        return 0;
}

bool isCross(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d) {
    int seg1 = ccw(a, b, c) * ccw(a, b, d);
    int seg2 = ccw(c, d, a) * ccw(c, d, b);

    if(seg1 <= 0 && seg2 <= 0) {
        if ((a.first > c.first && a.first > d.first && b.first > c.first && b.first > d.first) ||
            (c.first > a.first && c.first > b.first && d.first > a.first && d.first > b.first)) return false;
        else if ((a.second > c.second && a.second > d.second && b.second > c.second && b.second > d.second) ||
                 (c.second > a.second && c.second > b.second && d.second > a.second && d.second > b.second)) return false;
        return true;
    }

    return false;
}