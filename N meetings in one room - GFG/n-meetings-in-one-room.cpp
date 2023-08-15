//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool static comp(const pair<int,int>&a , const pair<int,int>&b) {
        return a.second<b.second;
    }
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        pair<int,int>p[n];
        for(int i=0;i<n;i++) {
            p[i].first=start[i];
            p[i].second=end[i];
        }
        sort(p,p+n,comp);
        
        int limit=p[0].second;
        int ans=1;
        for(int i=1;i<n;i++){
            if(p[i].first >limit){
                ans++;
                limit=p[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends