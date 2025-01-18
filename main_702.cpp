#include "bits/stdc++.h"

using namespace std;

class ArrayReader {
public:
    int get(int index);
};

int search(ArrayReader reader, int target) {
    int lef = 0;
    int rig = 10e4 + 1;
    while (lef <= rig) {
        int mid = (lef + rig) >> 1;
        int v = reader.get(mid);
        if (v == target) {
            return mid;
        }
        if (v > target) {
            rig = mid - 1;
        } else {
            lef = mid + 1;
        }
    }
    return -1;
}