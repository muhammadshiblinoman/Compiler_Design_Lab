/*
Write a program which converts a word of C++ program to its equivalent token.
RESULT:
Input: 646.45
Output: Float
Input: do
Output: Keyword
Input: 554
Output: Integer
Input: abc
Output: Identifier
Input: +
Output: Arithmetic Operator
*/

#include<bits/stdc++.h>
using namespace std;

int cnt;
vector<string> keywords = {"alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
                     "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
                     "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast",
                     "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
                     "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
                     "false", "float", "for", "friend", "goto", "if", "import", "inline", "include", "int",
                     "long", "module", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
                     "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register",
                     "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static",
                     "static_assert", "static_cast", "struct", "switch", "synchronized", "template",
                     "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename",
                     "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while",
                     "xor", "xor_eq"
};

vector<string> arithmetic_operators = {"+", "-", "*", "/", "%"};
vector<string> relational_operators = {"==", "!=", "<", ">", "<=", ">="};
vector<string> logical_operators = {"&&", "||", "!"};
vector<string> bitwise_operators = {"&", "|", "^", "~", "<<", ">>"};
vector<string> assignment_operators = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="};
vector<string> increment_decrement_operators = {"++", "--"};

bool stringChecking(const string& str, const vector<string>& check) {
    for (const auto& i : check) {
        if (str == i) {
            return true;
        }
    }
    return false;
}

bool checkConstnt(string str) {
    cnt = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '.') {
            cnt++;
        }
        else if(!isdigit(str[i])) {
            return false;
        }
    }
    if(cnt > 1) {
        return false;
    }
    return true;
}

bool numaric(string word) {
    for(int i = 1; i < word.size(); i++) {
        if(!isalnum(word[i]) && word[i] != '_') {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("08.input.txt", "r", stdin);
    string str;
    while(getline(cin, str)) {
        if(stringChecking(str, keywords)) {
            cout << str << " : " << "Keyword\n";
        }
        else if(stringChecking(str, arithmetic_operators)) {
            cout << str << " : " << "Arithmetic Operators\n";
        }
        else if(stringChecking(str, assignment_operators)) {
            cout << str << " : " << "Assignment Operators\n";
        }
        else if(stringChecking(str, bitwise_operators)) {
            cout << str << " : " << "Bitwise Operators\n";
        }
        else if(stringChecking(str, relational_operators)) {
            cout << str << " : " << "Relatioinal Operator\n";
        }
        else if(stringChecking(str, increment_decrement_operators)) {
            cout << str << " : " << "Increment or Decrement Operators\n";
        }
        else if(checkConstnt(str) ) {
            if(cnt == 0) {
                cout << str << " : " << "Integer\n";
            } else if(cnt == 1) {
                cout << str << " : " << "Float\n";
            }
        }
        else if (str[0] == '_' || isalpha(str[0])) {
            bool isValid = numaric(str);
            if (isValid) cout << str << " : " << "Identifier\n";
        }
        else if((str[0] == '"' and str[str.size()-1] == '"') ) {
            cout << str << " : " << "String Literal\n";
        } 
        else {
            cout << str << " : " << "Invalid Lexeme\n";
        }
    }

    return 0;
}