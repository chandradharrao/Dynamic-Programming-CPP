#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int util(int set[],int n,int currIndx,int prevIndx){
    if(currIndx >= n) return 0; //no set elements to explore

    int prevNum = INT16_MIN;
    if(prevIndx != -1) prevNum = set[prevIndx];

    //for each element,we have a choice,weather to include it or not in the longest subsequence
    int includeCount = 0;
    //include it only if set[currIndx] is greater than the prev Num since its Increasing seq we want
    if(set[currIndx] > prevNum)
        includeCount = 1 + util(set,n,currIndx+1,currIndx);

    //to compare we pass the index of the prevEle included in the subsequence
    int excludeCount = 0 + util(set,n,currIndx+1,prevIndx);

    //we need to take max of both options since we need longest subsequence
    return max(includeCount,excludeCount);
}

int LIS(int set[],int n){
    return util(set,n,0,-1);
}

int main(){
    int arr[] = {5,8,7,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The length of the longest increasing subsequence is " << LIS(arr,n) << endl;
}
