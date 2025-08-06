/*
Write a program that will check an English sentence given in present indefinite form 
to justify whether it is syntactically valid or invalid according to the following Chomsky 
Normal Form: 
S -> SUB PRED 
SUB -> PN | P 
PRED -> V | V N 
PN -> Sagor | Selim | Salma | Nipu 
P -> he | she | i | we | you | they 
N -> book | cow | dog | home | grass | rice | mango 
V -> read | eat | take | run | write
*/


#include <bits/stdc++.h>
using namespace std;

vector<string> subject = {"Sagor", "Selim", "Salma", "Nipu", "he", "she", "I", "we", "you", "they"};
vector<string> verb = {"read", "eat", "take", "run", "write"};
vector<string> noun = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

bool checkSubject(string str) {
    for(auto u: subject) {
        if((u == str)) {
            return true;
        }
    }
    return false;
}

bool checkVerb(string str) {
    for(auto u: verb) {
        if((u == str)) {
            return true;
        }
    }
    return false;
}

bool checkNoun(string str) {
    for(auto u: noun) {
        if((u == str)) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("09.input.txt", "r", stdin);
    string input;

    while(getline(cin, input)) {
        vector<string>words;
        string word = "";
        for(auto c: input) {
            if(c != ' ') {
                word += c;
            } else {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);
        
        int len = words.size();
        int cnt = 0;

        if(len >= 2 and len <= 3) {
            if(checkSubject(words[0])) {
               cnt++;
            }
            if(checkVerb(words[1])) {
                cnt++;
            }
            if(len == 3) {
                if(checkNoun(words[2])) {
                    cnt++;
                }
            }
        }
        if(len == 3 and cnt == 3) {
            cout << input << " : " << "Valid\n";
        } else if(len == 2 and cnt == 2) {
            cout << input << " : " << "Valid\n";
        } else {
            cout << input << " : " << "Invalid\n";
        }
    }
    return 0;
}