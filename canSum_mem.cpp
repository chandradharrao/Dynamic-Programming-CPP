#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool canSum(int targetSum,
std::vector<int>& numbers,
std::unordered_map<int,int>& memo){
    if(memo.find(targetSum) != memo.end()) return memo[targetSum];
    if(targetSum == 0) return true;
    //all numbers are non negetive acc to question
    if(targetSum < 0) return 0;
    for(int num:numbers){
        bool res = canSum(targetSum-num,numbers,memo);
        //early return
        if(res == true){
            memo[targetSum] = true;
            return true;
        }
    }
    //if no successful paths
    memo[targetSum] = false;
    return false;
}

bool canSum(int targetSum,std::vector<int>& numbers){
    std::unordered_map<int,int> memo = {};
    return canSum(targetSum,numbers,memo);
}

//overload operator
template <typename T>
std::ostream& std::operator<<(std::ostream& out,const std::vector<T>& arr){
    for(auto num : arr) cout << num << ",";
    out << "} ";
    return out;
}   

int main(){
    int n;
    std::cin >> n;
    int s;
    std::cin >> s;
    std::vector<int> arr;
    int temp;
    for(int i = 0;i<s;i++){
        std::cin >> temp;
        arr.push_back(temp);
    }
    std::cout << "Can we get "<<n<<" using the array {"<<arr<<"? "<<std::endl;
    bool res = canSum(n,arr);
    if(res) std::cout << "Yes";
    else std::cout << "No";
    std::cout<<std::endl;
    return 0;
}