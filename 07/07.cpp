/*
Write a program to recognize C++
 i) Keyword ii) Identifier iii) Operator iv) Constant
*/

#include<bits/stdc++.h>
using namespace std;

string keywords[] = {"alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
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

string operators[] = {
    "+", "-", "*", "/", "%",
    "==", "!=", "<", ">", "<=", ">=",
    "&&", "||", "!",
    "&", "|", "^", "~", "<<", ">>",
    "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", 
    "++", "--",
    "?", ":",
    ",",
    ".", "->",
    "::"
};

bool checkKeyword(string str) {
    for(auto i: keywords) {
        if(str == i) {
            return true;
        }
    }
    return false;
}

bool checkOperator(string str) {
    for(auto i: operators) {
        if(i == str) {
            return true;
        }
    }
    return false;
}

bool checkConstnt(string str) {
    int cnt = 0;
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
    freopen("07.input.txt", "r", stdin);
    string str;
    while(getline(cin, str)) {
        if(checkKeyword(str)) {
            cout << str << " : " << "Keyword\n";
        }
        else if(checkOperator(str)) {
            cout << str << " : " << "Operator\n";
        }
        else if(checkConstnt(str) || (str[0] == '"' and str[str.size()-1] == '"') ) {
            cout << str << " : " << "Constant\n";
        }
        else if (str[0] == '_' || isalpha(str[0])) {
            bool isValid = numaric(str);
            if (isValid) cout << str << " : " << "Identifier\n";
        } else {
            cout << str << " : " << "Invalid Lexeme\n";
        }
    }

    return 0;
}