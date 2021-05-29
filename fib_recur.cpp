#include <iostream>

int fib(int n){
    if(n <=2) return 1;
    return fib(n-2) + fib(n-1);
}

int main(){
    int n;
    std::cin >> n;
    std::cout << "Fib("<<n<<") = ";
    std::cout << fib(n) << std::endl;
    return 0;
}