 //LIS using bottom up approach
 #include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//dp[i] -> stores the Longest incresing subsequence length of those sub strings that END at set[i]
//this is done so that the next element can compare with its prev ele withput having to worry about what is the last eleemnt of the sub seq
//we finally return max(dp) which indicates the longest inc sub array length
//NOTE: dp[i] DOESNT represent the longest increasing sub seq length of the sequence upto set[i]

int LIS(int set[],int n){
    //create the dp array
    //by default,every eleemnt is a longest increasing sub seq of itself
    vector<int> dp(n,1);

    //iterate through every element
    for(int i = 0;i<n;i++){
        //check for which eles in the range set[0...i-1], set[i] is greater
        int lis_at = 0;
        for(int j = 0;j<i;j++){
            if(set[i] > set[j]){
                //for those eles,check if the lis len ending at     s[j] is greater than what we have previously seen
                if(set[j] > lis_at){
                    lis_at = set[j];
                }
            }
        }
        //inc the lis length at set[i]
        dp[i] += lis_at;
    }

    return *max_element(dp.begin(),dp.end());
}

int main(){
    int arr[] = { 10,22,9,33,21,50,41,60,80,1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The length of the longest increasing subsequence is " << n << endl;
    return 0;
}