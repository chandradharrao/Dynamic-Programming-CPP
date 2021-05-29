#include <iostream>
#include <string>
#include <unordered_map>

//function when the object is already craeted
int gridTraveler(int m,int n,std::unordered_map<std::string,int>& memo){
    //the key of the hashmap is m,n
    std::string key = m + "," + n;
    if(memo.find(key)!=memo.end()) return memo[key];
    if(m == 1 && n == 1) return 1;
    if(m == 0 || n == 0) return 0;
    //the value is the number of ways to reach E in a m,n grid
    memo[key] = gridTraveler(m-1,n,memo) + gridTraveler(m,n-1,memo);
    return memo[key];
}

//overloaded function to create a new object and pass it to the gridTraveler
int gridTraveler(int m,int n){
    std::unordered_map<std::string,int> memo = {};
    return gridTraveler(m,n,memo);
}


int main(){
    int m,n;
    std::cin >> n >> m;
    std::cout << "Goal : Bottom Right" << std::endl;
    std::cout << "Number of ways : " << gridTraveler(m,n)<<std::endl;
}   