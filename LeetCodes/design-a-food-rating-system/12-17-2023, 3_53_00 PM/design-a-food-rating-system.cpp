// Link: https://leetcode.com/problems/design-a-food-rating-system

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-a-food-rating-system
 *  RUNTIME: 401 ms
 *  MEMORY: 166.3 MB
 *  DATE: 12-17-2023, 3:53:00 PM
 *
 */

// Solution:

#define ll long long

class FoodRatings {
public:
    unordered_map<string, set<pair<ll, string>>> cuisine_rating;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, ll> food_rating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++) {
            cuisine_rating[cuisines[i]].insert({-ratings[i], foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        cuisine_rating[food_cuisine[food]].erase({-food_rating[food], food});
        cuisine_rating[food_cuisine[food]].insert({-newRating, food});
        food_rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return (cuisine_rating[cuisine].begin())->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
