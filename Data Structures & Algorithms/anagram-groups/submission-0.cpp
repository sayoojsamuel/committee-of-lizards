class Solution {
public:
    vector<int> calculateHash(string& anagram) {
        vector<int> v_alphabet(26, 0);
        for (auto chr: anagram) {
            auto chr_index = chr - 'a';
            v_alphabet[chr_index] += 1;
        }
        return v_alphabet;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hash anagrams map keeps
        // key -> vector if size 26, each index reserved for count of alphabets
        // value -> strings matching the pattern
        map<vector<int>, vector<string>> umap_anagrams; 

        for (auto s: strs) {
            vector<int> hash = calculateHash(s);
            
            if (umap_anagrams.count(hash)) {
                umap_anagrams[hash].push_back(s);
            } else {
                umap_anagrams[hash] = {s};
            }
        }

        vector<vector<string>> ans;
        for (auto &[key, value]: umap_anagrams) {
            ans.push_back(value);
        }

        return ans;
    }
};
