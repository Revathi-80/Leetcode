class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        int s=k;
        vector<int>v;
        int i=n;
        while(--i>=0 || s>0) {
            if(i>=0) 
                s+=num[i];
            v.push_back(s%10);
            s/=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};