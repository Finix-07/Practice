#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int minOperations(vector<string>& logs) {
    int NoOperations = 0;
    /*
    The operations are described below:

    "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
    "./" : Remain in the same folder.
    "x/" : Move to the child folder named x (This folder is guaranteed to always exist).
    */
    for (int i = 0 ; i < logs.size(); i++){
        if (!logs[i].compare("./")){
            continue;
        }
        else if (!logs[i].compare("../")){
            if (NoOperations > 0){
                NoOperations -= 1;
            }
            else{
                continue;
            }
        }
        else{
            NoOperations += 1;
        }
    }

    return NoOperations;
}

int main(){
    vector<string> moves = {"d1/","d2/","../","d21/","./"};


    cout << "No of Operations needed is ";
    cout << minOperations(moves) << endl;

    return 0;
}
