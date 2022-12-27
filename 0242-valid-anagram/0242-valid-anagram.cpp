class Solution {
public:
    bool isAnagram(string s, string t) {
        // int n=s.size();
        // int m=t.size();
        // unordered_map<int,int>mp;
        // for(int )
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};