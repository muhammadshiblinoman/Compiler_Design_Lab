#include <bits/stdc++.h>
using namespace std;

map<string, string> rules;
string stk = "", input;

void reduce() {
    for(auto rule: rules) {
        if(stk.find(rule.first) != std::string::npos) {
            int position = stk.find(rule.first);
            stk.erase(position);
            stk += rule.second;
            cout << left << setw(13) << "$" + stk << right << setw(13) << input + "$" << right << "         Shift " << stk.back() << "\n";
            reduce();
            return;
        }
    }
}

int main() {
    freopen("practice.txt", "r", stdin);
    string production;
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        getline(cin, production);
        rules[production.substr(3)] = production[0];
    }

    cin >> input;
    cout << "stack              " << "Input            " << "Action\n";
    cout << left << setw(3) << "$" + stk << right << setw(13) << input + "$" << '\n';
    
    for(int i = 0; !input.empty(); i++) {
        stk += input[0];
        input.erase(0, 1);
        cout << left << setw(13) << "$" + stk << right << setw(13) << input + "$" << right << "         Shift " << stk.back() << "\n";
        reduce();
    }

    if(stk == "E") cout << "Acepted";
    else cout << "Rejected";
}