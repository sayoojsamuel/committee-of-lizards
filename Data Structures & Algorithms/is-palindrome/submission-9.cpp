class Solution {
   public:
    bool isPalindrome(string s) {
        auto start = s.begin();
        auto end = s.end() - 1;

        while (start < end) {
            // jump to valid start pointer
            while (!isalnum(*start) && (start < end)) {
                start++;
            }
            while (!isalnum(*end) && (start < end)) {
                end--;
            }
            if (tolower(*start) != tolower(*end)) {
                return false;
            } else {
                start++;
                end--;
            }
        }

        return true;
    }
};
