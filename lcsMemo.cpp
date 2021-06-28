//bottom to top solution
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string s1,string s2){
    int m = s1.length();
    int n = s2.length();

    //2d matrix to store the longest sub sequence count for each sub sequence
    vector< vector<int> > table(m+1,vector<int>(n+1,0));

    //bottom up -> start from the smallest sub problem and build to the final solution
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){

            //empty strings dont have sub sequences 
            if(i == 0 || j == 0){
                table[i][j] = 0;
            }
            //if both the letters are same,then move equally back
            else if( s1[i - 1] == s2[j - 1] ){
                table[i][j] = 1 + table[i-1][j-1];
            }
            else{
                //else if not same,then we have to take max of the two choices
                table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
    }

    return table[m][n];
}


int main(){
    string s1 = "acadb";
    string s2 = "cbda";

    cout << "The longest subsequence is " << lcs(s1,s2) << endl;
}