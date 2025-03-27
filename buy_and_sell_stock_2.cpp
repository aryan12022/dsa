#include<bits/stdc++.h>
using namespace std;



class Solution {
    int f(int ind , int buy , vector<int>&prices,int n,vector<vector<int>>&dp){
if(ind==n){
return 0;
}
if(n==1)return 0;
if(dp[ind][buy]!=-1)return dp[ind][buy];
int profit=0;

if(buy){
        profit=max((-prices[ind]+f(ind+1,0,prices,n,dp)),f(ind+1,1,prices,n,dp));
}else{
       profit=max(prices[ind]+f(ind+1,1,prices,n,dp),f(ind+1,0,prices,n,dp));
}
return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {

//           int n=prices.size();
//           vector<vector<int>>dp(n+1,vector<int>(2,0));


// for(int i=0;i<2;i++){
//     dp[n][i]=0;
// }
// for(int i=n-1;i>=0;i--){
//     for(int j=0;j<2;j++){
//       int profit=0;
// if(j){
//         profit=max((-prices[i]+dp[i+1][0]),dp[i+1][1]);
// }else{
//        profit=max((prices[i]+dp[i+1][1]),(dp[i+1][0]));
// }

// dp[i][j]=profit;
//     }
     
// }


       
// return dp[0][1];

          int n=prices.size();
          vector<int>prev(2,0),cur(2,0);


for(int i=0;i<2;i++){
   cur[i]=0;
}
for(int i=n-1;i>=0;i--){
    for(int j=0;j<2;j++){
      int profit=0;
if(j){
        profit=max((-prices[i]+prev[0]),prev[1]);
}else{
       profit=max((prices[i]+prev[1]),(prev[0]));
}

cur[j]=profit;
    }
    prev=cur;
     
}


       
return prev[1];
    }
};