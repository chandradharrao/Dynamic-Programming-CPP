#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//minimum number of edits to change string s1 to s2 using:
//INSERT,REPLACE and DELETE ops
int min(int a,int b,int c){
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    return c;
}
//top down recursive approach

int util(string s1,string s2,int i,int j){
    //base cases
    //if both indices are -1 then match in the strings.Hence no ops req
    if(i == -1 && j == -1 ) return 0;
    //if len(s1) == 0,then to convert to s2,len(s2) insert ops req
    if(i < 0) return 1+j;

    //if len(s2) == 0,then to convert s1 to s2,len(s1) dels req
    if(j < 0) return 1+i;

    //if not then the optimal operation would be minimum of the 3 operations.Move the iterators i and j when the characters match.
    if(s1[i] == s2[j]) return 0+util(s1,s2,i-1,j-1);

    //inserting characters always on the right of the iterator
    int insertOps = 1 + util(s1,s2,i,j-1);
    //move iterators depending on the cases
    int remOps = 1 + util(s1,s2,i-1,j);
    int repOps = 1 +util(s1,s2,i-1,j-1);
    return min(insertOps,remOps,repOps);
}

int numMinEdits(string s1,string s2){
    //start comparision of characters from the end of the strings
    return util(s1,s2,s1.length()-1,s2.length()-1);
}

int main(){
    string s1 = "abc";
    string s2 = "abc";
    int n = numMinEdits(s1,s2);
    cout << "The min num of ops req  to conv s1 to s2 is " <<n << endl; 
}