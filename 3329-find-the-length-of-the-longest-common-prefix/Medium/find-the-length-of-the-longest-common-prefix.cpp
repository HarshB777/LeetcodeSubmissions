class Solution {
public:
    unordered_set<string> gen(vector<int> vec)
    {
        unordered_set<string> hs;
        
        for (auto x: vec)
        {
            string curr = to_string(x);
            
            string temp = "";
            for (int i = 0; i < curr.size(); i++)
            {
                temp+=curr[i];
                hs.insert(temp);
            }
        }
        
        return hs;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> set1 = gen(arr1);
        unordered_set<string> set2 = gen(arr2);
        
        int maxLen = 0;
        string ans = "";
        for (auto x: set1)
        {
            string curr = x;
            int sz = curr.size();
            if (set2.find(curr)!=set2.end())
            {
                maxLen = max(maxLen,sz);
            }
        }
        
        return maxLen;
    }
};
