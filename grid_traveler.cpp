#include <iostream>

//m and n are grid size and NOT player pos
int gridTraveler(int m,int n){
    if(m == 1 && n == 1) return 1;
    if(m ==0 || n == 0) return 0;
    //at each step we have the option to move DOWN or RIGHT
    //hence grid space reduces by 1 on either dim
    return gridTraveler(m-1,n) + gridTraveler(m,n-1);
}

int main(){
    int m,n;
    std::cin >> n >> m;
    std::cout << "Goal : Bottom Right";
    std::cout << "Number of ways : " << gridTraveler(m,n)<<std::endl;
}   