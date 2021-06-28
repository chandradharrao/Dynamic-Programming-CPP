#include <iostream>
#include <algorithm>
using namespace std;

int util(int W,int wt[],int val[],int n,int i){
    //base case
    //if bag has no storage capacity
    //if there are no items
    //if evaluating items out of the array
    //then no profit
    if(W <= 0 || n <= 0 || i >=n ){
        return 0;
    }

    //calc both the profit,considering ith item and skipping  it
    int profit1 = val[i] + util(W-wt[i],wt,val,n,i+1);
    int profit2 = util(W,wt,val,n,i+1);

    return max(profit1,profit2);
}

/*
W->bag weight
wt[]->sorted item weights
val[]->sorted item vals
n->number of items
*/
int knapsack(int W, int wt[],int val[],int n){
    return util(W,wt,val,n,0); 
}

int main(){
    int W = 50;
    int wt[] = {10,20,30};
    int val[] = {60,100,120};

    cout << "The Max Profit is Rs." << knapsack(W,wt,val,3) << endl;
}