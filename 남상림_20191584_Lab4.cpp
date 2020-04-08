#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int V = 0, UP = 0, MP = 0;

bool match(char a, char b) {
    switch (a) {
    case '(':
        if (b == ')')
            return true;
        else
            return false;
    case '{':
        if (b == '}')
            return true;
        else
            return false;
    case '[':
        if (b == ']')
            return true;
        else
            return false;
    }
}

bool check(char* buffer) {
    stack<char> stackS;
    char temp;

    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[')
            stackS.push(buffer[i]);
        if ((buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']')) {
            if (stackS.empty()) {
                cout << "UnBalanced parentheses" << endl;
                UP += 1;
                return false;
            }
            else {
                temp = stackS.top();
                stackS.pop();
                if (match(temp, buffer[i]) == false) {
                    cout << "Mismatched parntheses are " << temp << " and " << buffer[i] << endl;
                    MP += 1;
                    return false;
                }
            }
        }
    }
    if (stackS.empty())
        return true;
    else
    {
        cout << "UnBalanced parentheses" << endl;
        UP += 1;
        return false;
    }

}

void main() {

    ifstream infile("lab4.txt");

    char buffer[80];
    bool validity;


    while (infile.getline(buffer, 80)) {
        cout << buffer << endl;
        validity = check(buffer);

        if (validity)
        {
            cout << "This Expression is Valid" << endl;
            V += 1;
        }

    }
    cout << "Total : " << "Balanced : " << V << ", Unbalanced : " << UP << ", Mimatched : " << MP << endl;
    infile.close();
}