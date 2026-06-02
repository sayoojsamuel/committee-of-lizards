class Solution {
public:
    vector<int> calculateHash(string& anagram) {
        vector<int> freq(26, 0);
        for (auto chr: anagram) {
            auto chr_index = chr - 'a';
            freq[chr_index] += 1;
        }
        return freq;
    }

    long long convertHashToInt(vector<int>& freq) {
        long long hash = 0;

        for (const int f: freq) {
            hash = hash * 100 + f;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hash anagrams map keeps
        // key -> vector if size 26, each index reserved for count of alphabets
        // value -> strings matching the pattern
        // map<vector<int>, vector<string>> umap_anagrams; 
        unordered_map<long long, vector<string>> umap_anagrams; 


        for (string s: strs) {
            vector<int> hash = calculateHash(s);
            long long int_hash = convertHashToInt(hash);
            
            umap_anagrams[int_hash].push_back(s);

        }

        vector<vector<string>> ans;
        for (auto &[key, value]: umap_anagrams) {
            ans.push_back(value);
        }

        return ans;
    }
};
