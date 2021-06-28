#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
const int* a or int const* a = new int; 
=> the value of a cannot be changed but the pointer ie a can be changed
int* const a = new int; 
=> the pointer a cannot be reassigned but the value of a can be changed
const int* const a = new int;
=>niether the pointer nor the value of the pointer can be changed

class Entity{
    private:
        int m;
    public:
        int getM() const{ => this means that this function will not modify
                             the class member m ie readonly function.
            return m;
        }
}

const Entity& e
=> Since its a reference and not a pointer,e is not a variable but an alias
to a variable of type Entity.Hence in this case we can neither change the 
reference of e ie e = new Entity() nor can we change the values of the 
reference ie e.m = 50;
*/

string empty = "";

int countConstruct(const string& target,const vector<string>& wordbank){
    if(target == empty) return 1;

    int total = 0;
    for(const string& word : wordbank){
        //check if word is a PREFIX of target
        if(target.find(word) == 0){
            const string suffix = target.substr(
                word.length(),target.length());
            total += countConstruct(suffix,wordbank);
            
        }
    }
    return total;
}

int main(){
    cout << "Running CanConstr.exe" << endl;
    int res = countConstruct("abcdef",{"ab","abc","cd","def","abcd","ef"});
    //cout << "res" << " " << res << endl;
    if(res > 0) {
        cout << "Can Construct the String in : " << res << endl;
        }
    else{
        cout << "Cannot construct :<" << endl;
    }
    return 0;
}