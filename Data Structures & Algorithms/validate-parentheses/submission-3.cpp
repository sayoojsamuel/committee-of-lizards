class Solution {
   public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        vector<char> stack;
        stack.reserve(s.size());
        
        unordered_map<char, char> bracket_pairs = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for (char c : s) {
            cout << " c: " << c << endl;
            if (string("({[").find(c) != string::npos) {
                stack.push_back(c);
            } else {
                if (stack.empty()) return false;
                char top = stack.back();
                cout << " top: " << top << endl;
                if (c == bracket_pairs[top])
                    stack.pop_back();
                else
                    return false;
            }
        }
        if (!stack.empty())
            return false;
        else
            return true;
    }
};
