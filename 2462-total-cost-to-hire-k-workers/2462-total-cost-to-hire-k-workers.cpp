class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        long long ans=0;
        //min priority queue
        priority_queue<int,vector<int>,greater<int>>left,right;
        int cnt=0,i=0,j=n-1;
        while(cnt<k){
            while(left.size()<candidates && i<=j) left.push(costs[i++]);
            while(right.size()<candidates && i<=j) right.push(costs[j--]);
            int a = left.size()>0 ? left.top():INT_MAX;
            int b= right.size()>0? right.top():INT_MAX;
            if(a<=b){
                ans+=a;
                left.pop();
            }
            else{
                ans+=b;
                right.pop();
            }
            cnt++;
        }
        return ans;
    }
};