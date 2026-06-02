class Solution {
   public:
    bool isPalindrome(string s) {
        auto start = s.begin();
        auto end = s.end() - 1;

        while (start < end) {
            // jump to valid leftPtr
            while (!isalnum(*start) && (start < end)) {
                start++;
            }
            // if only all punctuations, the start will be end
            cout << " start: " << *start;
            // if (start == end-1) return true;
            while (!isalnum(*end) && (start < end)) {
                end--;
            }
            cout << " end: " << *end;
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
