/*
Build a lexical analyzer implementing the following regular expressions:
Integer variable = (i-nI-N)(a-zA-Z0-9)*
ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
LongInt Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise
*/


#include <bits/stdc++.h>
using namespace std;

bool integer(string word) {
    for(int i = 1; i < word.size(); i++) {
        if(!isalnum(word[i])) {
            return false;
        }
    }
    return true;
}

bool numbers(string word) {
    for(int i = 1; i < word.size(); i++) {
        if(!isdigit(word[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("04.input.txt", "r", stdin);
    string word;

    while (getline(cin, word)) {
        bool isValid = true;
        if (tolower(word[0]) >= 'i' && tolower(word[0]) <= 'n') {
            isValid = integer(word);
            if(isValid) cout << word << " : "<< "Integer variable\n";
        }
        else if(word[0] >= '1' && word[0] <= '9') {
            isValid = numbers(word);
            if(isValid) {
                if(word.size() < 5) cout << word << " : " << "ShortInt Number\n";
                else cout << word << " : " << "LongInt Number\n";
            }
        }
        else {
            cout << word << " : "<< "Invalid Input or Undefined\n";
        }
    }
    return 0;
}