class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        // Kadane's algoto find maxsubsum
        for(int i = 1; i < n; i++){
            currSubSum = max(nums[i], currSubSum + nums[i]);
            maxSubSum = max(maxSubSum , currSubSum);
        }

        // Kadane's algoto find maxsubsum
        int minSubSum = nums[0];
        currSubSum = nums[0]; // reset

        for(int i = 1; i < n; i++){
            currSubSum = min(nums[i], currSubSum + nums[i]);
            minSubSum = min(minSubSum , currSubSum);
        }
        return max(abs(maxSubSum), abs(minSubSum));
    }
};