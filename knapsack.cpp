#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//Top Down approach - recursion with memoization
//REFER:https://www.youtube.com/watch?v=ZYYNcm6Kn3g&ab_channel=SunnyGupta
//subproblem dp(i,c) = find max profit for items { i,i+1,i+2,...,n} when there is a bag with capacity c

int util(int W,int wt[],int val[],int n,vector<vector<int*>>& cache,int i){

    //base case
    if(W <= 0 || n <= 0 || i>= n) return 0;

    //check if the profit for a given bag size and item exists in the cache
    if(cache[i][W] != nullptr){
        cout << i << "," << W << endl;
        return *cache[i][W];
    }

    //if not,calculate the profit for : with and without the item
    int profit1 = val[i] + util(W-wt[i],wt,val,n,cache,i+1);
    int profit2 = util(W,wt,val,n,cache,i+1);

    int profit = max(profit1,profit2);
    cache[i][W] = &profit;
    return *cache[i][W];
}

int knapsack(int W,int wt[],int val[],int n){
    //vector containing n elements and each having storing a vector of int*s.
    //each of these vector of ints have size W+1 and store null
    vector< vector<int*> > cache( n, vector<int*> (W+1,nullptr) );

    return util(W,wt,val,n,cache,0);
}


int main(){
    int W = 50;
    int wt[] = {10,20,30};
    int val[] = {60,100,120};

    cout << "The Max Profit is Rs." << knapsack(W,wt,val,3) << endl;
}


