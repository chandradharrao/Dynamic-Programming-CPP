//Solvebiterativly, where we need to do all sub problem calculation to get the final result
//subproblem dp(i,c) = find max profit for the subset of 0,1,2,3,....,i-1 items for bag with capcity c

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int util(int W,int wt[],int val[],int n,vector<vector<int>>& memo){
    //iteratively compute 
    for(int i = 1;i<n;i++){
        for(int w = 0;w<=W+1;w++){
            if(wt[i] > w){
                //if weight of the item is greater than that of the bag capacity,ignore the item
                memo[i][w] = memo[i-1][w];
            }
            else{
                //profit with and without including the ite,
                memo[i][w] = max(val[i] + memo[i-1][w-wt[i]],memo[i-1][w]);
            }
        }
    }

    //print the items considered
    cout << "Items considered are : ";
    int c = W;
    int i = n-1; //we need i outside the loop
    for(;i>0;i--){
        if( memo[i][c] > memo[i-1][c] ){
            //then we have considered the item i.Hence the profit is more than that when we havent considered
            cout << "{" << wt[i] << "," << val[i] << "}" << ",";

            //reduce the weight by item's weight
            c = c- wt[i];
        }else{
            cout << "{" << wt[i] << "," << val[i] << "}" << ",";
        }
    }

    //check for 1st element ie 0th index elem
    if( c > 0 )
        cout << "{" << wt[i] << "," << val[i] << "}" << ",";
        
    cout << endl;

    return memo[n-1][W];
}

int knapsack(int W,int wt[],int val[],int n){
    //create memo
    vector< vector<int> >memo(n,vector<int>(W+1,-1));

    //init memo - if capacity of bag is 0,then no matter for what item,profit is 0
    for(int i = 0;i<n;i++){
        memo[i][0] = 0;
    }

    return util(W,wt,val,n,memo);
}

int main(){
    int W = 50;
    int wt[] = {10,20,30};
    int val[] = {60,100,120};

    cout << "The Max Profit is Rs." << knapsack(W,wt,val,3) << endl;
}