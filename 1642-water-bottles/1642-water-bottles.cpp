class Solution {
public:
    int numWaterBottles(int b, int e) {
        int total = b; 
        int empty = b;  
        
        while (empty >= e) {
            int newBottles = empty / e;  
            total += newBottles;        
            empty = empty % e + newBottles; 
        }
        
        return total;
    }
};
