#include "bits/stdc++.h"

using namespace std;

int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dis1(n, n);
    int v1 = 0;
    while (node1 >= 0 && dis1[node1] == n) {
        dis1[node1] = v1;
        v1++;
        node1 = edges[node1];
    }
    vector<int> dis2(n, n);
    int v2 = 0;
    while (node2 >= 0 && dis2[node2] == n) {
        dis2[node2] = v2;
        v2++;
        node2 = edges[node2];
    }
    int min_dis = n, res = -1;
    for (int i = 0; i < n; i++) {
        int d = max(dis1[i], dis2[i]);
        if (d < min_dis) {
            min_dis = d;
            res = i;
        }
    }
    return res;
}