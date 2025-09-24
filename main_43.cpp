//#include "bits/stdc++.h"
//
//using namespace std;
//
//string multiply(string num1, string num2) {
//    string res = "";
//    int n = num1.size(), m = num2.size();
//
//    int more = 0;
//    for (int j = n - 1; j >= 0; j--) {
//        int v = (num1[j] - '0') * (num2[0] - '0') + more;
//        more = v / 10;
//        res = to_string(v % 10) + res;
//    }
//    if (more != 0) {
//        res = to_string(more) + res;
//    }
//
//    for (int i = m - 2; i >= 0; i--) {
//        more = 0;
//        int idx = res.size() - (m - i);
//        for (int j = n - 1; j >= 0; j--) {
//            int v = (num1[j] - '0') * (num2[i] - '0') + more;
//            if (idx >= 0) {
//                more = v / 10;
//                res[idx] = (v % 10) + '0';
//            } else {
//                more = v;
//            }
//            idx--;
//        }
//        if (more != 0) {
//            res = to_string(more) + res;
//        }
//        cout << res << endl;
//    }
//    return res;
//}