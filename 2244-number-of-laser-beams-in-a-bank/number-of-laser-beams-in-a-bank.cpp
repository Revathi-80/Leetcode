class Solution {
    int countOne(string n) {
         int cnt=0;
         for(int i=0;i<n.size();i++) {
             if(n[i]=='1') cnt++;
         }
         return cnt;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int n= bank.size();
        int prev= countOne(bank[0]);
        int sum=0;
        for(int i=1;i<n;i++) {
            int current = countOne(bank[i]);
            sum+= (current*prev);
            if(current)
            prev=current;
        }
        return sum;
    }
};