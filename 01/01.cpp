/*
Write a C program that read the following string:
“Md. Tareq Zaman, Part-3, 2011”
a) Count number of words, letters, digits and other characters.
b) Separates letters, digits and others characters.
*/

#include <bits/stdc++.h>
using namespace std;

void generateFunction(string input) {
    int words = 1, letters = 0, digits = 0, otherCharacters = 0;
    string separateLetters, separateDigits, separateOtherChar;

    for(char c : input) {
        if(c == ' ') words++;
        else if(tolower(c) >= 'a' && tolower(c) <= 'z') {
            letters++;
            separateLetters += c; 
        }
        else if(c >= '0' && c <= '9') {
            digits++;
            separateDigits += c;
        }
        else {
            otherCharacters++;
            separateOtherChar += c;
        }

    }
    cout << "Number of words: " << words <<'\n';
    cout << "Number of letters: " << letters << '\n';
    cout << "Number of digits: " << digits << '\n';
    cout << "Number other of characters: " << otherCharacters << '\n';

    cout << "\nThe letters are: " << separateLetters <<'\n';
    cout << "The digits are: " << separateDigits << '\n';
    cout << "The characters are: " << separateOtherChar << '\n';
}

int main() {
    freopen("01.input.txt", "r", stdin);
    string input;
    getline(cin, input);

    generateFunction(input);
    return 0;
}
