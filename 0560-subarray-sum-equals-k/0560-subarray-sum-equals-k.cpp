class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int > map;
        int r = 0;
        int  csum =0;
        map.insert({0,1});

        for(int i = 0 ; i< nums.size(); i++){
            csum += nums[i];
            if(map.find(csum-k) != map.end()){
                r += map[csum-k];
            }
        
            map[csum]++;
        }
        return r;
    }
};