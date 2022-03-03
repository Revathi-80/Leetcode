class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>>mergeIntervals;
        if(intervals.size()==0){
            return mergeIntervals;
        }
    sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        for(auto i:intervals){
            if(i[0]<=temp[1]){
                temp[1]=max(i[1],temp[1]);
            }
            else{
                mergeIntervals.push_back(temp);
                temp=i;
            }
        }
        mergeIntervals.push_back(temp);
        return mergeIntervals;
    }
};