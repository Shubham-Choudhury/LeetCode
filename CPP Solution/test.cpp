// Link: https://coderbyte.com/editor/Codeland%20Username%20Validation:Cpp

#include <iostream>
#include <string>
using namespace std;

string CodelandUsernameValidation(string str){
    int n = str.size();
    if (n < 4 || n > 25)
        return "false";
    if (str[0] >= '0' && str[0] <= '9')
        return "false";
    for (int i = 0; i < n; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        if (str[i] >= 'a' && str[i] <= 'z')
            continue;
        if (str[i] >= 'A' && str[i] <= 'Z')
            continue;
        if (str[i] == '_')
            continue;
        return "false";
    }
    return "true";
}

int main() {
    cout << CodelandUsernameValidation("aa_") << endl;
    return 0;
}