//#include "bits/stdc++.h"
//
//using namespace std;
//
//long long maximumCoins(vector<vector<int>> &coins, int k) {
//    int n = coins.size();
//    sort(coins.begin(), coins.end(), [&](const vector<int> &v1, const vector<int> &v2) {
//        return v1[0] < v2[0];
//    });
//    long long res = -1;
//    // 从l往后找
//    for (int i = 0; i < n; ++i) {
//        vector<int> coin = coins[i];
//        int l = coin[0];
//        int r = coin[1];
//        int c = coin[2];
//        if (l + k < r) {
//            res = max(res, 1LL * k * c);
//            continue;
//        }
//        long long tmp = (r - l + 1) * c;
//        int j = i + 1;
//        while (j < n && coins[j][1] < l + k) {
//            tmp += 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
//            j++;
//        }
//        if (j < n && coins[j][0] < l + k) {
//            tmp += 1LL * (l + k - coins[j][0]) * coins[j][2];
//        }
//        res = max(res, tmp);
//    }
//
//    // 从r往后找
//    for (int i = n - 1; i >= 0; i--) {
//        vector<int> coin = coins[i];
//        int l = coin[0];
//        int r = coin[1];
//        int c = coin[2];
//        if (l + k < r) {
//            res = max(res, 1LL * k * c);
//            continue;
//        }
//        long long tmp = (r - l + 1) * c;
//        int j = i - 1;
//        while (j >= 0 && coins[j][0] > r - k) {
//            tmp += 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
//            j--;
//        }
//        if (j >= 0 && coins[j][1] > l - k) {
//            tmp += 1LL * (coins[j][1] - (r - k)) * coins[j][2];
//        }
//        res = max(res, tmp);
//    }
//    return res;
//}