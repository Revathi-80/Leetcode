class Solution {
public:
    vector<int> findAnagrams(string txt, string p) {
        int n=txt.size(),k=p.size();
        unordered_map<char,int>mpp;
        for(int a=0;a<k;a++){
            mpp[p[a]]++;
        }
        int i=0,j=0;
        vector<int>ans;
        int cnt=mpp.size();
        while(j<n){
            //calculations
            if(mpp.find(txt[j])!=mpp.end()){
                mpp[txt[j]]--;
                if(mpp[txt[j]]==0)
                    cnt--;
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1==k){
                //ans---calculations
                if(cnt==0)
                    ans.push_back(i);
                //slide
                if(mpp.find(txt[i])!=mpp.end()){
                    mpp[txt[i]]++;
                    if(mpp[txt[i]]==1)
                        cnt++;
                }
                i++,j++;
            }
        }
        return ans;
    }
};