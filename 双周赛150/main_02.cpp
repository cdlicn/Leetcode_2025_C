#include "bits/stdc++.h"

using namespace std;

static bool cmp(const std::vector<int> &v1, const std::vector<int> &v2) {
    return v1[1] < v2[1];
}

double separateSquares(std::vector<std::vector<int>> &squares) {
    // 根据y 从小到大排序
    std::sort(squares.begin(), squares.end(), cmp);

    // 事件点：(y, width)
    vector<pair<double, int>> events;
    for (const auto &square: squares) {
        int y = square[1];
        int l = square[2];
        events.emplace_back(y, l);
        events.emplace_back(y + l, -l);
    }

    // 按 y 坐标排序事件点
    sort(events.begin(), events.end());

    double sum = 0.0;
    double currentY = 0.0;
    long long currentL = 0;

    // 计算总面积
    for (const auto &[y, l]: events) {
        sum += currentL * (y - currentY);
        currentY = y;
        currentL += l;
    }
    cout << sum << endl;

    double half = sum / 2.0;
    double currentArea = 0.0;
    currentY = 0.0;
    currentL = 0;

    // 再次遍历事件点以找到分割线
    for (const auto &[y, l]: events) {
        if (currentL > 0) {
            double nextY = y;
            double add = currentL * (nextY - currentY);
            if (currentArea + add >= half) {
                double c = half - currentArea;
                return currentY + c / currentL;
            }
            currentArea += add;
        }
        currentY = y;
        currentL += l;
    }
    return -1.0;
}

//double separateSquares(vector<vector<int>> &squares) {
//    // 根据y 从小到大排序
//    sort(squares.begin(), squares.end(), [&](const vector<int> &v1, const vector<int> &v2) {
//        return v1[1] > v2[1];
//    });
//    // 记录 key行的面积为 value
//    unordered_map<int, long> mp;
//    int topY = 0, lowY = INT_MAX;
//    for (const auto &square: squares) {
//        int y = square[1], l = square[2];
//        for (int i = y; i < y + l; ++i) {
//            mp[i] += l;
//            lowY = min(lowY, i);
//            topY = max(topY, i);
//        }
//    }
//    double topSum = 0, lowSum = 0;
//    while (topY > lowY) {
//        if (topSum > lowSum) {
//            topSum -= lowSum;
//            lowSum = 0;
//            lowSum += mp[lowY];
//            lowY++;
//        } else if (topSum == lowSum) {
//            topSum = lowSum = 0;
//            topSum += mp[topY];
//            lowSum += mp[lowY];
//            topY--;
//            lowY++;
//        } else {
//            lowSum -= topSum;
//            topSum = 0;
//            topSum += mp[topY];
//            topY--;
//        }
//    }
//    if (topSum == lowSum) {
//        if (mp.count(lowY)) {
//            return lowY - 1 + 0.5;
//        } else {
//            while (!mp.count(lowY)) {
//                lowY--;
//            }
//            return lowY;
//        }
//    } else if (topSum > lowSum) {
//        double c = topSum - lowSum;
//        return 1 + lowY + c / mp[topY + 1];
//    } else {
//        double c = lowSum - topSum;
//        return 1 + topY + c / mp[lowY - 1];
//    }
//}

//[[522261215,954313664,461744743],[628661372,718610752,21844764],[619734768,941310679,91724451],[352367502,656774918,591943726],[860247066,905800565,853111524],[817098516,868361139,817623995],[580894327,654069233,691552059],[182377086,256660052,911357],[151104008,908768329,890809906],[983970552,992192635,462847045]]