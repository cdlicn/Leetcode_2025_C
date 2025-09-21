#include "bits/stdc++.h"

using namespace std;

// 未借出: {movie: {price: shop}}
// 借出{price, shop, movie}

class MovieRentingSystem {
public:
    struct hash_pair {
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ (hash2 << 1);
        }
    };

    // 商店电影，shop，movie，price
    unordered_map<pair<int, int>, int, hash_pair> mp;
    // 未借出电影，movie，{price，shop}
    unordered_map<int, set<pair<int, int>>> non_borrow;
    // 已借出电影，{price, shop, movie}
    set<tuple<int, int, int>> borrow;

    MovieRentingSystem(int n, vector<vector<int>> &entries) {
        for (const auto &entry: entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            non_borrow[movie].emplace(price, shop);
            mp[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        int i = 0;
        for (const auto &[price, shop]: non_borrow[movie]) {
            if (i >= 5) {
                break;
            }
            res.emplace_back(shop);
            i++;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = mp[{shop, movie}];
        non_borrow[movie].erase({price, shop});
        borrow.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        int price = mp[{shop, movie}];
        non_borrow[movie].emplace(price, shop);
        borrow.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int i = 0;
        for (const auto &[price, shop, movie]: borrow) {
            if (i >= 5) {
                break;
            }
            res.emplace_back(vector<int>{shop, movie});
            i++;
        }
        return res;
    }
};
