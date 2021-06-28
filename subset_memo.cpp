#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//top down approach -> we try to solve the entire problem and to solve that we compute sub problems

bool util(int targetSum,int set[],int n,unordered_map<string,bool>& memo,int i){
    if(targetSum == 0) return true;
    if(i>=n || targetSum <0) return false;

    //the nique key is number of elements of the set arr,specific targetSum
    string key = to_string(i) + "," + to_string(targetSum);
    if(memo.find(key)!=memo.end()){
        //key in hashmap
        return memo[key];
    }else{
        //calculate with and without element set[i]
        memo[key] = util(targetSum-set[i],set,n,memo,i+1)||util(targetSum,set,n,memo,i+1);
        return memo[key];
    }
}

bool subSet(int targetSum,int set[],int n){
    //data structure to cache the values
    unordered_map<string,bool> lookup;

    return util(targetSum,set,n,lookup,0);
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