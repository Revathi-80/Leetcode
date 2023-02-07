class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int l,r;
        int n=fruits.size();
        for( l=0,r=0;r<n;r++) {
            mp[fruits[r]]++;
            if(mp.size()>2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)
                    mp.erase(fruits[l]);
                l++;
            }
        }
        
        return r-l;
    }
}; 