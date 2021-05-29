#include <iostream>
#include <unordered_map>

//print hashmap
void printMemo(std::unordered_map <int,long long int> memo){
    for(auto it = memo.begin();it!=memo.end();it++){
        std::cout<<it->first<<":"<<it->second<<std::endl;
    }
}


//default argument is an empty memo object used at the first level call
long long fib(int n,std::unordered_map<int,long long int>& memo){
    //if n in memo - iter to end is not returned
    if(memo.find(n)!=memo.end()) return memo[n];
    //base cond
    if(n<=2) return 1;
    //store in memo,hence pass by REFERENCE
    memo[n] = fib(n-1,memo) + fib(n-2,memo);
    //printMemo(memo);
    return memo[n];
}

long long fib(int n){
    //create map
    std::unordered_map<int,long long int> memo = {};
    return fib(n,memo);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << "Fib("<<n<<") = ";

    std::cout << fib(n) << std::endl;
    return 0;
}