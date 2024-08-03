#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSeniors(vector<string>& details) {
    int count = 0;

    for(string &detail : details) {
        int secondDigit = detail[11] - '0';
        int firstDigit  = detail[12] - '0';

        int age         = secondDigit*10 + firstDigit;

        if(age > 60)
            count++;
    }

    return count;
}

int main(){

    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};

    cout << "The number of eligible are : ";
    cout << countSeniors(details);

    return 0;
}