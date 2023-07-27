//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int k=pat.size(),n=txt.size();
	    int i=0,j=0;
	    int ans=0;
	    unordered_map<char,int>mpp1;
	    for(int x=0;x<k;x++) mpp1[pat[x]]++;
	    int cnt=mpp1.size();
	    while(j<n){
	        if(mpp1.find(txt[j])!=mpp1.end()){
	             mpp1[txt[j]]--;
	        if(mpp1[txt[j]]==0)
	            cnt--;
	        }
	        if(j-i+1<k)
	            j++;
	        else if(j-i+1 == k){
	           if(cnt==0)
	           ans++;
	           if(mpp1.find(txt[i])!=mpp1.end()){
	                mpp1[txt[i]]++;
	           if(mpp1[txt[i]]==1)
	               cnt++;
	           }
	           i++,j++;
	        }
	        
	       // mpp1[txt[i]]++;
	        
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends