class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            rotate(nums);
            if (sorted(nums)) {
                return true;
            }
        }
        return false;
    }

    void rotate(vector<int>& arr) {
        int n = arr.size();
        int first = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first;
    }

    bool sorted(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1])
                return false;
        }
        return true;
    }
};
