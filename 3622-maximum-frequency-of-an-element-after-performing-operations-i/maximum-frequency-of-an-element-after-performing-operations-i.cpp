class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());  // nums.sort()

    // O(n) | O(n)
    unordered_map<int, int> counts;
    for (int num : nums) {
        counts[num]++;
    }

    int maxFreq = 0;

    int endIndex = 0;
    int startIndex = 0;

    // O(m + n) | O(1)
    for (int element = nums.front(); element <= nums.back(); element++) {
        while (endIndex != nums.size() && nums[endIndex] <= element + k) {
            endIndex++;
        }

        while (startIndex < nums.size() && nums[startIndex] < element - k) {
            startIndex++;
        }

        int windowSize = endIndex - startIndex;
        int maxBound = counts[element] + numOperations;
        int freq = min(windowSize, maxBound);

        maxFreq = max(freq, maxFreq);
    }

    return maxFreq;
    }
};