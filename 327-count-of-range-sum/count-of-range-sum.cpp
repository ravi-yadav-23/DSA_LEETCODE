class Solution {
public:
    int mergeSort(vector<long long>& sum, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(sum, left, mid, lower, upper) + mergeSort(sum, mid, right, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<long long> cache(right - left, 0);
        for (int i = left, r = 0; i < mid; ++i, ++r) {
            while (k < right && sum[k] - sum[i] < lower) k++;
            while (j < right && sum[j] - sum[i] <= upper) j++;
            while (t < right && sum[t] < sum[i]) cache[r++] = sum[t++];
            cache[r] = sum[i];
            count += j - k;
        }
        copy(cache.begin(), cache.begin() + (t - left), sum.begin() + left);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        return mergeSort(sum, 0, n + 1, lower, upper);
    }
};