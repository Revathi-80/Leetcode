class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int n=digits.size();
        int carry=0;
        bool flag=false;
        if(digits[n-1]==9) {
            digits[n-1]=0;
            carry=1;
            flag=true;
        }
        else {
            digits[n-1]++;
        }
        for(int i=n-2;i>=0;i--) {
          if(flag){  
            if(digits[i]==9) {
                carry=1;
                digits[i]=0;
                flag=true;
            }
            else {
                digits[i]=digits[i]+carry;
                carry=0;
                flag=false;
            }
          }
        }
        if(carry==1) {
            reverse(digits.begin(),digits.end());
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};