class Solution {
   public:
    vector<pair<int, int>> twoSum(vector<int>& nums, int target, int startIndex = 0) {
        vector<pair<int, int>> solutions;
        int i = startIndex, j = nums.size() - 1;
        while (i < j) {
            int twoSum = nums[i] + nums[j];
            if (twoSum == target) {
                solutions.push_back({nums[i], nums[j]});

                int left = nums[i];
                int right = nums[j];

                while (i < j && nums[i] == left) i++;
                while (i < j && nums[j] == right) j--;

            } else if (twoSum > target) {
                j--;
            } else if (twoSum < target) {
                i++;
            }
        }
        return solutions;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> solutions;
        int n = nums.size();

        for (int i = 0; i <= n - 2; i++) {
            // skip duplications in the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // -i = j+k
            vector<pair<int, int>> inner = twoSum(nums, -nums[i], i + 1);

            for (auto x : inner) {
                solutions.push_back({nums[i], x.first, x.second});
            }
        }

        return solutions;
    }
};
