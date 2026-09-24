class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        int digit;
        while (num > 0) {
             digit = num % 10;
             sum = sum + digit;
             num = num / 10; 
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i<n; i++) {
            if(digitSum(nums[i]) == i)
                return i;
        }
        return -1;
        
    }
};