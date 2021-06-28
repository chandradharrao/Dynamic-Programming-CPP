#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//naive recursive approach

//dimArr indices : {0,1,2,.....,N} => size = N+1
int util(vector<int> dimArr,int l,int r){
    //the cost of multiplying single matrix is 0
    if(l == r || l > r) return 0;

    //minimum cost and index of splitting
    int min_cost = INT16_MAX;
    int min_index = INT16_MAX;

    //test out all paranthesis positions
    for(int k = l;k<r;k++){
        int rightCost = util(dimArr,l,k);
        int leftCost = util(dimArr,k+1,r);
        int currCost = dimArr[l]*dimArr[k]*dimArr[r];
        int totalCost =  rightCost + leftCost + currCost;
        
        if(totalCost < min_cost) min_index = k;
    }

    cout << "The min cost is "<< min_cost << endl;
    return min_index;
}

//if N matrixes,then dim array will have N+1 entries
int mcm(vector<int> dimArr){
    //if we put paranthesis on the right side,then we can start from index 1 since a matrix must have atleast one element
    return util(dimArr,1,dimArr.size()-1);
}

int main(){

}