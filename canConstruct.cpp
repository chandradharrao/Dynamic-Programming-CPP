#include <string>
#include <iostream>
#include <vector>
using namespace std;

const string empty = "";

bool canConstruct(const string& target,const vector<string>& wordbank){
    //we can construct empty string without using any words from the bank
    if(target.compare(empty) == 0) return true;
    
    for(auto& word : wordbank){
        //check if word is the PREFIX in the target
        if(target.find(word) == 0){
            //target with removed PREFIX
            string suffix = target.substr(word.length(),target.length());
            //cout << "Suffix " << suffix << endl;
            bool res = canConstruct(suffix,wordbank);
            //early return
            if(res) return true;
        }
    }
    //if none of the words are a substring
    return false;
}

int main(){
    cout << "Running CanConstr.exe" << endl;
    bool res = canConstruct("abcdef",{"ab","abc","cd","def","abcd"});
    //cout << "res" << " " << res << endl;
    if(res) {
        cout << "Can Construct the String!" << endl;
        }
    else{
        cout << "Cannot construct :<" << endl;
    }
    return 0;
}