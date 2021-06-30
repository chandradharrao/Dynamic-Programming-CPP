#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//find catlans bottm up,smaller sub problems first and finally the answer

//Number of binary trees with n nodes is Catlan Number ie Cn

int catlan(int n){
    //create dp table to store 
    vector<int> dp(n+1);
    //catlan of 0 is 1 and catlan of 1 is 1
    dp[0] = 1;
    dp[1] = 1;

    //C3 = C0C2 + C1C1 + C2C0
    for(int i = 2;i<=n;i++){
        //for finding Ci,we require all of 0 to i-1 values
        for(int j = 0;j<i;j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    int n = 4;
    cout << "The catlan of " << n << " is " << catlan(n);
}