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

int main(){
    int n;
    std::cin >> n;
    std::cout << "Fib("<<n<<") = ";
    //create map
    std::unordered_map<int,long long int> memo = {};

    std::cout << fib(n,memo) << std::endl;
   // printf("Fib(%d)=%lld",n,fib(n,memo));
    return 0;
}