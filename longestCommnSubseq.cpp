#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

//recursive approach
//smallest sub sequence is when there is one letter matching -> return 1 

int util(string s1,string s2,int i,int j){
    //if either of iterators reach end,then there is no sub seq
    if ( i < 0 || j < 0 ) return 0;

    //if letters match,then sub seq len can be inc by one and inc iterators
    if ( s1[i] == s2[j] )
        return 1 + util(s1,s2,i-1,j-1);
    //if not same letters,search if jth letter of s2 is present in s1 or if ith letter of s1 is present in s2
    else
        return max(util(s1,s2,i-1,j),util(s1,s2,i,j-1));
}


//return the length of the longest subsequence
int lcs(string s1,string s2){
    //start from the last letter
    return util(s1,s2,s1.length()-1,s2.length()-1);
}

int main(){
    string s1 = "bd";
    string s2 = "abcd";

    cout << "The longest subsequence is " << lcs(s1,s2) << endl;
}
