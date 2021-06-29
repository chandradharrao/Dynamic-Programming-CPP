#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//bottom up using table : dp[i][j]->min cons req to produce change for amout j using i coins

int minCoinsReq(vector<int> coins,int sum){
    int n = coins.size();

    //create table
    vector<vector<int>> dp(n+1,vector<int>(sum+1,INT16_MAX));

    //if change to produc is 0,then no coins are req to produce it
    for(int i = 0;i<n+1;i++){
        dp[i][0] = 0;
    }

    //if number of coins are zero then it cannot produce any amout of change except 0
    for(int j = 1;j<sum+1;j++){
        dp[0][j] = INT16_MAX;
    }

    //build sub problems to get the final problem result
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            //check if the i-1th coin produces valid change
            if(sum-coins[i-1] < 0){
                //if not then dont include the i-1th coin
                dp[i][j] = INT16_MAX;
            }else{
                //at each coin we have 2 choices: include the coin and not include the coin
                //since each coin has inf instances,the i-1th coin can be used how many ever times we need
                //the coins available are i coins
                dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);   
            }            
        }
    }
    return dp[n][sum];
}

int main(){
    vector<int> coins = {1,2,3};
    int sum = 5;
    cout << "The minimum coins required to produce sum of "<<sum <<" is " << minCoinsReq(coins,sum);
}