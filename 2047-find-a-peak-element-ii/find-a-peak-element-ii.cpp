class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = 0;
            for (int i = 1; i < m; i++)
                if (arr[i][mid] > arr[row][mid])
                    row = i;

            int left = (mid - 1 >= 0) ? arr[row][mid - 1] : -1;
            int right = (mid + 1 < n) ? arr[row][mid + 1] : -1;

            if (arr[row][mid] > left && arr[row][mid] > right)
                return {row, mid};
            else if (arr[row][mid] < right)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {-1, -1};
    }
};