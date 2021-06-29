#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
//fewest coins to make the change

//let INF amount of coins -> represent unable to generate the given amount

//top down approach 
int coinsRequired(vector<int> coins,int sum){
    //base cases
    //if the amount is 0,no coins are required to make the change
    if(sum == 0) return 0;

    //if the amount is less than zero,its not possible to generate that change.
    if(sum < 0) return INT16_MAX;

    //min num of coins variable
    int min_coins = INT16_MAX;

    for(int i = 0;i<coins.size();i++){
        //find out the coins required to generate sub problem
        int sub_res = coinsRequired(coins,sum-coins[i]);

        //check if the amount=sum-coins[i] could be produced or not
        if(sub_res != INT16_MAX){
            //check if the new coin,coins[i] used to produce change requires lesser coins
            min_coins = min(min_coins,sub_res+1);
        }
    }

    return min_coins;
}

int main(){
    vector<int> coins = {1,2,3};
    int sum = 5;
    cout << "The minimum coins required to produce sum of "<<sum <<" is " << coinsRequired(coins,sum);
}