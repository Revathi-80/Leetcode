class Solution {
    void NSL(vector<int>&h,vector<int>&left) {
       
        int n=h.size();
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++) {
            if(s.size()==0)
                left.push_back(-1);
            else if(s.size()>0 && s.top().first<h[i])
                left.push_back(s.top().second);
            else if(s.size()>0 && s.top().first >= h[i]) {
                while(s.size()>0 && s.top().first >=h[i]) {
                    s.pop();
                }
                if(s.size()==0)
                    left.push_back(-1);
                else 
                    left.push_back(s.top().second);
            }
            s.push({h[i],i});
        }
       
    }
     void NSR(vector<int>&h,vector<int>&right) {
        
        int n=h.size();
         int ind=n;
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--) {
            if(s.size()==0)
                right.push_back(ind);
            else if(s.size()>0 && s.top().first<h[i])
                right.push_back(s.top().second);
            else if(s.size()>0 && s.top().first >= h[i]) {
                while(s.size()>0 && s.top().first >=h[i]) {
                    s.pop();
                }
                if(s.size()==0)
                    right.push_back(ind);
                else 
                    right.push_back(s.top().second);
            }
            s.push({h[i],i});
        }
         reverse(right.begin(),right.end());
    
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
       vector<int>h(m,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(matrix[i][j]!='0')
                    h[j]=h[j]+ (matrix[i][j] - '0');
                else
                    h[j]=0;
               // cout<<h[j]<<endl;
            }
            for(int i=0;i<m;i++) cout<<h[i]<<" ";
            cout<<endl;
            vector<int>right;
            vector<int>left;
            NSL(h,left);
            NSR(h,right);
            vector<int>w(m);
            for(int i=0;i<m;i++) {
                w[i]=right[i]-left[i]-1;
            }
            vector<int>area(m);
            int maxi=INT_MIN;
            for(int i=0;i<m;i++) {
                area[i]=w[i]*h[i];
                maxi= max(maxi,area[i]);
            }
            ans=max(ans,maxi);
        }
    
       
        return ans;
    }
};