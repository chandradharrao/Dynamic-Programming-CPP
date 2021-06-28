#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool util(int set[],int n,int targetSum,int i){
    if( targetSum < 0 ) return false;
    if( targetSum == 0 ) return true;

    for(int j = i+1;j<n;j++){
        if( util(set,n,targetSum-set[j],j) ) return true;
    }
    return false;
}

bool canSum(int targetSum,int set[],int n){
    for(int i = 0;i<n;i++){
        if(util(set,n,targetSum-set[i],i)) return true;
    }
    return false;
}

int main(){
    int arr[] = { 3,34,4,12,5,2 };
    int sum = 9;

    if(canSum(9,arr,6)) cout << "Yes,We Can Sum \n" << endl;
    else cout << "No,We cannot Sum " << endl;
}