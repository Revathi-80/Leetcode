class Solution {
  
public:
 static bool cmp(pair<int,int>&a,pair<int,int>&b){
     return (a.second==b.second)?a.first>b.first:a.second<b.second;
 }  
public:
 void sortMap(map<int,int>&mp,vector<int>&ans){
     vector<pair<int,int>>v;
     for(auto it:mp){
         v.push_back(it);
     }
     sort(v.begin(),v.end(),cmp);
     for(auto it:v){
         for(int i=0;i<it.second;i++){
             ans.push_back(it.first);
         }
     }
 }   
    
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        sortMap(mp,ans);
        return ans;
    }
};