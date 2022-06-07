```
class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
int i=m-1,j=n-1,k=m+n-1;
while(i>=0 && j>=0){
if(nums1[i]>nums2[j])
nums1[k--]=nums1[i--]; // the greatest among the two is inserted at the end of nums1
else
nums1[k--]=nums2[j--];
}
// the remainig elements are added to nums1
while(i>=0)
nums1[k--]=nums1[i--];
while(j>=0)
nums1[k--]=nums2[j--];
}
};
```