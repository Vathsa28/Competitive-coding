//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    /*
    for recurisve approach we do the memset inside a constructor   
    public:
       int  t[1002][1002] ;
    Solution()
    {
        memset(t,-1,sizeof(t));
    }
    ));
    */
 
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        
       // Your code here
       /*
       This is the recursive code for Knapsack,which passed 1142/1210 cases.
       
       if(n==0 || W==0)
       {
           return 0;
       }
       if(wt[n-1] <= W)
       {
           return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
       }
       else
           return knapSack(W,wt,val,n-1);
        
        Now we memoize it and try again
        */
        
        /*
        
        ** This is the memoized recursive approach for 0/1 knapsack
        
        if(n==0 || W==0)
        {
           return 0;
        }
        if(t[n][W] != -1)
        {
            return t[n][W];
        }
        if(wt[n-1] <= W)
        {
           return t[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
        }
        else
           return t[n][W]=knapSack(W,wt,val,n-1);
        */
        
        // top down code for knapsack
        
        int t[n+1][W+1];
        //initialization
        for(int i=0;i<n+1;i++)
            for(int j=0;j<W+1;j++)
                if(i==0 || j==0)
                    t[i][j]=0;
        
        for(int i=1 ; i < n+1;i++)
            for(int j=1;j<W+1;j++)
            {
                if(wt[i-1] <= j)
                {
                    t[i][j]=max(val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j]);
                }
                else
                    t[i][j]=t[i-1][j];
            }
        
        return t[n][W];
        
        //the optimal Solution for the knapsack problem
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends