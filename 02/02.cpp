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
    freopen("02.input.txt", "r", stdin); // Open the File
    string input;
    getline(cin, input);

    int vowel = 0, consonant = 0;
    string vowels, consonants, word;
    string vowel_words, consonant_words;

    for(char c : input) {
        if(is_vowel(c)) {
            vowel++; // Count the vowels in a string
            vowels += c; // Sepatate the vowels in a string
        }
        else if(tolower(c) >= 'a' && tolower(c) <= 'z') {
            consonant++; // Count the Consonant in a string
            consonants += c; // Separate the Consonant in a string
        }
        if(tolower(c) >= 'a' && tolower(c) <= 'z') {
            word += c; // Separate the word in the string
        }
        else if(c == ' ') {
            // words are checked if they started with vowel
            if(is_vowel(word[0])) vowel_words += " " + word;
            else consonant_words += " " + word;
            word = "";
        }
    }
    // Also check the last word after which there is no space
    if(is_vowel(word[0])) vowel_words += " " + word;
    else consonant_words += " " + word;
    word = "";


    cout << "\nNumber of vowels: " << vowel << '\n';
    cout << "The vowels are: " << vowels << '\n';
    cout << "Number of consonants: " << consonant << '\n';
    cout << "The consonants are: " << consonants <<' \n';
    cout << "Words started with vowel: " << vowel_words << '\n';
    cout << "Words started with consonant: " << consonant_words;
    
    return 0;
}