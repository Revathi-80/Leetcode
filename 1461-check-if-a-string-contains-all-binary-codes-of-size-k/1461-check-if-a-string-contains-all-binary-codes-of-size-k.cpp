class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int n=s.length();
        for(int i=0;i<n-k+1;i++){
         //   cout<<s.substr(i,k)<<endl;
            st.insert(s.substr(i,k));
        }
       //for(auto x:st) cout<<x<<" ";
        if(st.size()==pow(2,k))
            return true;
        else
            return false;
    }
};