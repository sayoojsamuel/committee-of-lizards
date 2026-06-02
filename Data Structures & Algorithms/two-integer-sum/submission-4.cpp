class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> lookup;  // value -> index
        for (size_t i = 0; i < nums.size(); i++) {
            auto search_result = lookup.find(target - nums[i]);
            if (search_result != lookup.end()) {
                return {search_result->second, (int)i};
            }
            else {
                lookup.try_emplace(nums[i], i);
            }
        }
    }
};
