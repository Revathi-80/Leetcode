class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
     //   vector<int>candies(n,1);
        vector<int>right(n,1);
        vector<int>left(n,1);
        bool hasChanged=true;
      //  while(hasChanged){
            hasChanged=false;
            
            for(int i=1;i<n;i++){
                if(ratings[i]>ratings[i-1] ){
                    left[i]=left[i-1]+1;
                    //hasChanged=true;
                }
            }
        for(int i=n-2;i>=0;i--){
                if(ratings[i]>ratings[i+1] ){
                    right[i]=right[i+1]+1;
               //     hasChanged=true;
                }
            }
     //   }
        int sum=0;
        for(int i=0;i<n;i++) {
            //cout<<candies[i]<<" ";
            sum+=max(right[i],left[i]);
        }
        return sum;
    }
};