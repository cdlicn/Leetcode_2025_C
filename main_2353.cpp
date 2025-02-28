#include "bits/stdc++.h"

using namespace std;

class FoodRatings {
    unordered_map<string, pair<int, string>> food_map;
    unordered_map<string, set<pair<int, string>>> cuisine_map;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            food_map[food] = {rating, cuisine};
            cuisine_map[cuisine].emplace(-rating, food);
        }
    }

    void changeRating(string food, int newRating) {
        auto &[rating, cuisine] = food_map[food];
        auto &st = cuisine_map[cuisine];
        st.erase({-rating, food}); // 移除旧数据
        st.emplace(-newRating, food); // 添加新数据
        rating = newRating;
    }

    string highestRated(string cuisine) {
        return cuisine_map[cuisine].begin()->second;
    }
};