class Solution {
    public int missingNumber(int[] nums){

        int n = nums.length;
        int sum = 0;
        for(int num : nums) sum+= num;
        int exp_sum = n*(n+1) /2 ;

        int result = exp_sum - sum;
        return result;
    }

}