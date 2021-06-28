#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//top down approach->we define states fstarting from the problem we want to solve as the sub problem ie dp(0,c)->can we get the sum c using all the elemnts of the set array starting from index 0?
//dp(i,targetSum)-> can we get the targetSum using the elements indexed {i,i+1,i+2,....,n} from the set array

bool util(int targetSum,int set[],int n,int i){
    if( i>=n || i<0 || targetSum < 0 ) return false;
    if( targetSum == 0 ) return true;

    //at each element we have a choice,include the set[i] in the subset ot not
    return util(targetSum-set[i],set,n,i+1)||util(targetSum,set,n,i+1);
}

bool canSum(int targetSum,int set[],int n){
    return util(targetSum,set,n,0);
}

int main(){
    int arr[] = { 3,34,4,12,5,2 };
    int sum = 9;

    if(canSum(9,arr,6)) cout << "Yes,We Can Sum \n" << endl;
    else cout << "No,We cannot Sum " << endl;
}