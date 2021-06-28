#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef unordered_map<string,bool> dict;
string empty = "";

bool canConstruct(
    const string& target,
    const vector<string>& wordbank,
    dict* memo
){
    if(memo->find(target)!=memo->end()) return (*memo)[target];
    if(target == empty) return true;
    for(const string& word : wordbank){
        //check if the word is a prefix of target
        if(target.find(word) == 0){
            //remove the prefix
            const string suffix = target.substr(word.length(),target.length());
            (*memo)[target] = canConstruct(suffix,wordbank,memo);
            if((*memo)[target]) return true;
        }
    }
    return false;
}

bool canConstruct(
    const string& target,
    const vector<string>& wordbank
){
    dict* memo = new dict;
    return canConstruct(target,wordbank,memo);
}

int main(){
    cout << "Running CanConstrMemo.exe" << endl;
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