#include <iostream>
#include <string>
#include <vector>
using namespace std;

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

string keypad[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz"};

vector <string> substring;

void advance(char ch[], char op[], int i, int j){
    //base case
    if (ch[i] == '\0'){
        op[j] = '\0';
        
        for (int i=0; i<12; i++){
            size_t found = searchIn[i].find(op);
            if (found != string::npos){
                cout<<searchIn[i]<<endl;
            }
        }
        return;
    }

    int digit = ch[i] - '0';

    for (int w=0; keypad[digit][w] != '\0'; w++){
        op[j] = keypad[digit][w];
        advance(ch, op, i+1, j+1);
    }
}


int main() {
    char ch[10], op[10];
    cin>>ch;
    advance(ch, op, 0, 0);

    for (int i=0; i<substring.size(); i++){
        cout<<substring[i]<<" ";
    }

}