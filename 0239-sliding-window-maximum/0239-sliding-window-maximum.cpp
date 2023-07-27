class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n=nums.size();
        int i=0,j=0;
        vector<int>ans;
        deque<int>q;
        while(j<n){
            //calculations
           while(!q.empty() && q.back()<nums[j]){
               q.pop_back();
           }
            q.push_back(nums[j]);
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                //ans from calculations
                ans.push_back(q.front());
                //slide
                if(!q.empty() && q.front()==nums[i]){
                    q.pop_front();
                }
                i++,j++;
            }
        }
        return ans;
    }
};