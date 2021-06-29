#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
//top down with memoization

int util(vector<int> coins,int sum,unordered_map<int,int>& dict){
    if(sum == 0) return 0;
    if(sum < 0) return INT16_MAX;

    //check if cached
    if(dict.find(sum) != dict.end()) return dict[sum];

    int min_coins = INT16_MAX;

    for(int i = 0;i<coins.size();i++){
        int sub_res = util(coins,sum-coins[i],dict);
        if(sub_res != INT16_MAX && 1+sub_res < min_coins){
            min_coins = 1+sub_res;
        }   
    }
    return dict[sum] = min_coins;
}

int coinsReq(vector<int> coins,int sum){
    //use a hashmap to store min num of coins req to produce an amount
    unordered_map<int,int> dict;
    return util(coins,sum,dict);
}

int main(){
    vector<int> coins = {1,2,3};
    int sum = 5;
    cout << "The minimum coins required to produce sum of "<<sum <<" is " << coinsReq(coins,sum);
}