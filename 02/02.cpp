/*
Write a program that read the following string:
“Munmun is the student of Computer Science & Engineering”.
a) Count how many vowels and Consonants are there?
b) Find out which vowels and consonants are existed in the above string?
c) Divide the given string into two separate strings, where one string only contains 
the words started with vowel, and another contains the words started with consonant.
*/

#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    return tolower(c)=='a'||tolower(c)=='e'||tolower(c)=='i'||tolower(c)=='o'||tolower(c)=='u';
}

int main() {
    freopen("02.input.txt", "r", stdin); 
    string input;
    getline(cin, input);

    int vowel = 0, consonant = 0;
    string vowels, consonants, word;
    string vowel_words, consonant_words;

    for(char c : input) {
        if(is_vowel(c)) {
            vowel++;
            vowels += c;
        }
        else if(tolower(c) >= 'a' && tolower(c) <= 'z') {
            consonant++;
            consonants += c;
        }
        if(tolower(c) >= 'a' && tolower(c) <= 'z') {
            word += c; 
        }
        else if(c == ' ') {
            if(is_vowel(word[0])) vowel_words += " " + word;
            else consonant_words += " " + word;
            word = "";
        }
    }
    if(is_vowel(word[0])) vowel_words += " " + word;
    else consonant_words += " " + word;
    word = "";

    cout << "\nNumber of vowels: " << vowel << '\n';
    cout << "The vowels are: " << vowels << '\n';
    cout << "Number of consonants: " << consonant << '\n';
    cout << "The consonants are: " << consonants << '\n';
    cout << "Words started with vowel: " << vowel_words << '\n';
    cout << "Words started with consonant: " << consonant_words;
    
    return 0;
}