/*
Write a program that abbreviates the following code:
CSE-3141 as Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory.
*/

#include<bits/stdc++.h>
using namespace std;

map<string, string> dept_names;
map<char, string> year;
map<char, string> subject;
map<char, string> course;
string input;

void initialize() {
    dept_names["CSE"] = "Computer Science & Engineering";
    dept_names["ICE"] = "Information & Communication Engineering";

    year['1'] = "1st";
    year['2'] = "2nd";
    year['3'] = "3rd";
    year['4'] = "4th";

    subject['1'] = "Software Engineering";
    subject['2'] = "Database Management Systems";
    subject['3'] = "Web Engineering";
    subject['4'] = "Compiler Design";

    course['1'] = "Theory";
    course['2'] = "Lab";
}

void depertment_name(string dept_name) {
    cout << input << " : " << dept_names[dept_name] << " ";
}

void course_name(string code) {
    cout << year[code[0]] << " year, " << year[code[1]] << " semester, " << subject[code[2]] << ", " << course[code[3]] << '\n';
}

int main() {
    freopen("03.input.txt", "r", stdin);
    string dept_name;
    getline(cin, input);

    int i = 0;
    while(input[i] != '-') {
        dept_name += input[i];
        i++;
    }

    string code = input.substr(i+1);

    initialize();

    depertment_name(dept_name);
    course_name(code);

    return 0;
}