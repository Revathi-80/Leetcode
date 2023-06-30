```
class Solution {
int maxi(vector<int>&piles,int n) {
int ans=piles[0];
for(int i=1;i<n;i++){
ans=max(ans,piles[i]);
}
return ans;
}
int check(vector<int>&piles,int n,int mid){
int time=0;
for(int i=0;i<n;i++){
time += (piles[i]+mid-1)/mid;
}
return time;
}
public:
int minEatingSpeed(vector<int>& piles, int h) {
int n=piles.size();
int low=1,high=maxi(piles,n);
while(low<=high){
int mid= low + high/2;
if(check(piles,n,mid)<=h){
high=mid-1;
}
else {
low=mid+1;
}
}
return low;
}
};
```