#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//bottom up -> solve the smaller sub problems iteratively and use ot to find the entire problem solution
//dp(i,c) -> using the eleemnts indexed {0,1,2...,i},find the sum c

bool subSet(int targetSum,int set[],int n){
    //T[i][j] -> can we produce sum j using first i items ie {0,1,2,..,i-1} indexed items?
    vector<vector<bool>> T(n+1,vector<bool>(targetSum+1,false));

    //if sum is zero,any amount of elemnts can produce it
    for(int i = 0;i<=n;i++){
        T[i][0] = true;
    }
    //if 0 items in the list then it cannot produce any sum except 0 sum
    for(int j = 1;j<=targetSum;j++){
        T[0][j] = false;
    }

    //starting with 1 element from set array
    for(int i = 1;i<=n;i++){
        //starting with a targetSum of 1
        for(int j = 1;j<=targetSum;j++){
            //check if the ith element(index i-1) of set when included is valid
            if(j-set[i-1] >=0 ){
                //if valid,at each element we have the choice of choosing wheather to include it or not
                //find the subset sum after including the elem
                bool inc = T[i-1][j-set[i-1]];
                //find the subset sum without the elem
                bool exec = T[i-1][j];
                T[i][j] = inc||exec;
            }else{
                //exclude the ith eke
                T[i][j] = T[i-1][j];
            }
        }
    }

    return T[n][targetSum];
}

int main(){
    //int arr[] = { 3,34,4,12,5,2 };
    //int sum = 9;
    int arr[] = {3,6};
    int targetSum = 9;

    if(subSet(targetSum,arr,sizeof(arr)/sizeof(arr[0])))
        cout << "Yes,We Can Sum \n" << endl;
    else 
        cout << "No,We cannot Sum " << endl;
}