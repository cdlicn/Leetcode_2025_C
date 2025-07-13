#include "bits/stdc++.h"

using namespace std;

int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
    ranges::sort(players);
    ranges::sort(trainers);
    int i = players.size() - 1, j = trainers.size() - 1;
    int res = 0;
    while (i >= 0 && j >= 0) {
        if (players[i] <= trainers[j]) {
            res++;
            j--;
        }
        i--;
    }
    return res;
}