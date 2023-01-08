class Solution
{
    public:
        int maxPoints(vector<vector < int>> &points)
        {
           
            int n = points.size();
           int ans=0;
            
            for (int i = 0; i < n; i++)
            {    int concurrent=1;
                unordered_map<double,int>mp;
                for (int j = i + 1; j < n; j++)
                {
                    double slope;
                    double x=(points[j][0] - points[i][0]);
                    double y=(points[j][1] - points[i][1]);
                //    cout<<"Y "<<y<<" "<<x<<endl;
                    if(x==0 && y==0)
                       concurrent++;
                    else if(x==0)
                        mp[INT_MAX]++;
                    else{
                        slope = y / x;
                    mp[slope]++;
                    }
                  //  cout<<slope<<endl; 
                }
              int maxi=0;
              for(auto i:mp) {
                maxi=max(maxi,i.second);
            }
            maxi+=concurrent;
             ans=max(ans,maxi);
               
            }
          
        return ans;
        }
};