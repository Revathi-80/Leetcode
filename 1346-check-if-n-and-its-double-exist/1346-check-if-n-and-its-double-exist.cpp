class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      int n=arr.size();
        int cnt=count(arr.begin(),arr.end(),0);
        if(cnt>1)
            return true;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
            auto it=find(arr.begin(),arr.end(),2*arr[i]);
            if(it!=arr.end())
                return true;
            }
        }
        return false;
    }
}; 