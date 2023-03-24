//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        /* If we look at it carefully, we see that we have to divide the array such that we get equal sum on both paritions. So we take the sum of the array and divide it by 2. And we find a subset where it's sum is the sum divided by 2 */
        
        long long sum = 0;
        for(int i=0; i< N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2)
        {
            
            return 0;
        }
        sum/=2;
        int t[N+1][sum+1];
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    t[i][j]=0;
                }
                if(j==0)
                {
                    t[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1] > j )
                {
                    t[i][j]=t[i-1][j];
                }
                else
                {
                    t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
                }
            }
        }
        return t[N][sum];
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends