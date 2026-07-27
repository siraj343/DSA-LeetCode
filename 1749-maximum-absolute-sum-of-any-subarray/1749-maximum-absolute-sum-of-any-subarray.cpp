class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSubSum = nums[0];
        int minSubSum = nums[0];
        int currSubSumMax = nums[0];
        int currSubSumMin = nums[0];

        for (int i = 1; i < n; i++) {
            currSubSumMax = max(nums[i], currSubSumMax+nums[i]);
            maxSubSum = max(maxSubSum, currSubSumMax);

            currSubSumMin = min(nums[i], currSubSumMin+nums[i]);
            minSubSum = min (minSubSum, currSubSumMin);
        }
        return max(abs(maxSubSum), abs(minSubSum));
    }
};