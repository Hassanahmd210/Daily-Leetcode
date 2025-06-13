class Solution {
public:
    int shipWithinDays(vector<int>& weights, int ships) {
        int lower_bound = *max_element(weights.begin(), weights.end());
        int upper_bound = 0;

        for (int x : weights)
            upper_bound += x;

        int result = upper_bound;

        while (lower_bound <= upper_bound) {
            int capacity = (lower_bound + upper_bound) / 2;

            if (canShip(weights, capacity, ships)) {
                result = min(result, capacity);
                upper_bound = capacity - 1;
            } 
            else {
                lower_bound = capacity + 1;
            }
        }
        return result;
    }
    
private:
    bool canShip(const vector<int>& weights, int cap, int ships) {
        int cnt = 1, cur = 0;
        for (int x : weights) {
            if (cur + x > cap) {
                cnt++;
                cur = 0;
            }
            cur += x;
        }
        return cnt <= ships;
    }
};