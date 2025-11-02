/*
Write a program to generate a parse tree of predictive parser using the following parsing
table:
      id          +          *          (          )          $
E   E->TE'                            E->TE'
E'             E'->+TE'                          E'->@      E'->@
T   T->FT'                            T->FT'
T'              T'->@      T'->*FT'              T'->@      T'->@
F   F->id                             F->(E)
*/

#include <bits/stdc++.h>
using namespace std;

map<pair<char, char>, string> table;

bool solve(string str){
    stack<pair<int, char>> stk;
    stk.push({0, 'E'});
    int space = 0;
    for (int i = 0; i < str.size(); i++) {
        while (stk.top().second != str[i] && stk.top().second != '@')  {
            pair<int, char> front = stk.top();
            if (table[{front.second, str[i]}] == "") {
                return false;
            }
            for (int i = 0; i < front.first; i++)
                cout << " ";
            cout << front.second << "--->" << table[{front.second, str[i]}] << endl;
            space = front.first + 5;
            stk.pop();
            string rightside = table[{front.second, str[i]}];
            reverse(rightside.begin(), rightside.end());
            for (char c : rightside) {
                stk.push({space, c});
            }
        }
        if (stk.top().second == str[i])  {
            stk.pop();
        }
        if (stk.top().second == '@') {
            stk.pop();
            i--;
        }
    }
    while (!stk.empty()) {
        for (int i = 0; i < stk.top().first; i++)
            cout << " ";
        cout << stk.top().second << "--->" << '@' << endl;
        stk.pop();
    }
    return true;
}

int main() {
    freopen("15.input.txt", "r", stdin);
    string str;
    getline(cin, str);

    table[{'E', 'i'}] = "TP";
    table[{'E', '('}] = "TP";
    table[{'P', '+'}] = "+TP";
    table[{'P', ')'}] = "@";
    table[{'P', '$'}] = "@";
    table[{'T', 'i'}] = "FQ";
    table[{'T', '('}] = "FQ";
    table[{'Q', '+'}] = "@";
    table[{'Q', ')'}] = "@";
    table[{'Q', '$'}] = "@";
    table[{'Q', '*'}] = "*FQ";
    table[{'F', 'i'}] = "i";
    table[{'F', '('}] = "(E)";

    cout << "Input string : " << str << endl;
    if (solve(str))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}