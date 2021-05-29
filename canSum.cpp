#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool canSum(int targetSum,std::vector<int>& numbers){
    if(targetSum == 0) return true;
    //all numbers are non negetive acc to question
    if(targetSum < 0) return 0;
    for(int num:numbers){
        bool res = canSum(targetSum-num,numbers);
        //early return
        if(res) return true;
    }
    //if no successful paths
    return false;
}

//overload operator
template <typename T>
std::ostream& std::operator<<(std::ostream& out,const std::vector<T>& arr){
    for(auto num : arr) cout << num << ",";
    out << "} ";
    return out;
}   

/*std::ostream& std::operator<<(std::ostream& out,const bool& truth){
    if(truth) out<< "True"<<std::endl;
    else out<<"False"<<std::endl;
    return out;
}*/

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
    //std::cout<<res?"Truth":"False"<<std::endl;
    if(res) std::cout << "Yes";
    else std::cout << "No";
    std::cout<<std::endl;
    return 0;
}