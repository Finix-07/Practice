#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string reverseParentheses(string s) {
    string result;

    stack<int> ReversingLength;

    for(auto &x : s){

        if (x == '('){
            ReversingLength.push(result.size());
        }
        else if ( x == ')'){
            int l = ReversingLength.top();
            ReversingLength.pop();
            reverse(result.begin() + l , result.end());
        }
        else{
            result.push_back(x);
        }


    }


    return result;
}

int main(){
    string s = "(u(love)i)";

    cout << reverseParentheses(s);

    return 0;
}