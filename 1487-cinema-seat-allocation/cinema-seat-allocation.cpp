class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        int ans = 2 * n;

        unordered_map<int, vector<bool>> mp;

        for (auto &seat : r) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 5)
                mp[row].push_back(true);

            if (col >= 4 && col <= 7)
                mp[row].push_back(true);

            if (col >= 6 && col <= 9)
                mp[row].push_back(true);
        }

        for (auto &[row, v] : mp) {
            bool left = false, middle = false, right = false;

            for (auto &seat : r) {
                if (seat[0] != row) continue;

                int col = seat[1];

                if (col >= 2 && col <= 5) left = true;
                if (col >= 4 && col <= 7) middle = true;
                if (col >= 6 && col <= 9) right = true;
            }

            if (left && right) {
                if (!middle)
                    ans--;
                else
                    ans -= 2;
            } 
            else if (left || right) {
                ans--;
            }
        }

        return ans;
    }
};