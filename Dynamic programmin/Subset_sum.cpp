//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    Solution()
    {
    }
    /*
    
    Recursive memoized code 
    
    bool newrecfunc(vector<int> arr, int sum,int n,vector<vector<int> >& t)
    {
        if(sum==0)
            return true;
        if(n==0)
            return false;
        if(t[n-1][sum] != -1)
        {
            return t[n-1][sum];
        }
        
        if(arr[n-1]<= sum)
        {
            return t[n-1][sum]=newrecfunc(arr,sum-arr[n-1],n-1,t) || newrecfunc(arr,sum,n-1,t);
        }
        else
        {
            return t[n-1][sum]=newrecfunc(arr,sum,n-1,t);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<vector<int> > t(n+1,vector<int>(sum+1,-1));
        return newrecfunc(arr,sum,n,t);
        // code here 
    }
    */
    
    // This is the proper top down approach where we use the static table and replace the n and sum with i and j at appropriate places.
    
     bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<vector<bool> > t(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<n+1;i++)
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    t[i][j]=false;
                }
                if(j==0)
                {
                    t[i][j]=true;
                }
            }
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1] > j)
                    t[i][j]= t[i-1][j];
                else
                    t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }    
        // code here 
        return t[n][sum];
    }

    
    //This is the recursive memoized version of the code. Here we create a matrix and then pass the pointer to that matrix every call. So that the stack space is saved. Rest all is fairly straight forward. Now we look at the top down code.
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends