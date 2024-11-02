#include<bits/stdc++.h>
using namespace std;

int minimum_coins(int n,int amount,int coins[]){
    
    int dp[n + 1][amount + 1];

    for(int i = 0; i < n; i++)
        dp[i][0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amount; j++){
            if(coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
        }
    }
    return dp[n + 1][amount];
}

int main(){
    int n;
    cin>>n;

    int coins[n];
    for(int i = 0; i < n; i++)
    cin>>coins[i];

    int amount;
    cin>>amount;

    int result = minimum_coins(n,amount,coins);

    cout<<result;
}