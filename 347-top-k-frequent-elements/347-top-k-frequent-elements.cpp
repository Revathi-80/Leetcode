class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>ans;
        // int cnt=0,chec=0;
        // while(cnt<=k){
        //     cnt++;
        //     int put;
        // for(auto x:mp){
        //     if(x.second >chec){
        //         chec=x.second;
        //         put=x.first;
        //     }
        // }
        //      if(cnt<=k)
        //         ans.push_back(put);
        // }
        priority_queue<pair<int,int>>p;
        for(auto pr:mp){
            p.push(make_pair(pr.second,pr.first));
            if(p.size()>mp.size()-k){
                ans.push_back(p.top().second);
                p.pop();
            }
        }
        return ans;
    }
};