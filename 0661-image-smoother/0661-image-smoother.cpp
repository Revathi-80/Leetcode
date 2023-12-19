class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row=img.size(),col=img[0].size();
        vector<vector<int>>ans(row,vector<int>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int avg= img[i][j];
                
                int cnt=1;
                if(i>0 ) {avg+=img[i-1][j]; cnt++;}
                if(j>0) {avg+=img[i][j-1]; cnt++;}
                if(i<row-1) {avg+= img[i+1][j]; cnt++;}
                if(j<col-1) {avg+=img[i][j+1]; cnt++;}
                if(j-1>=0 && i-1>=0) {avg+=img[i-1][j-1],cnt++;}
                if(j-1>=0 && i+1<row) {avg+=img[i+1][j-1],cnt++;}
                if(j+1<col && i-1>=0) {avg+=img[i-1][j+1],cnt++;}
                if(j+1<col && i+1<row) {avg+=img[i+1][j+1],cnt++;}
                    
               // cout<<avg<<" ";
               avg=floor(avg/cnt);
               // cout<<avg<<" "<<cnt;
                ans[i][j]=avg;
            }
            
        }
        return ans;
    }
};