#include <bits/stdc++.h>
using namespace std;

bool RatMaze(char ch[][1000], int i, int j, int m, int n){
    //base case
    if (i == m-1 && j == n-1){
        ch[i][j] = '1';
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (ch[i][j] == '1'){
                    cout<<"1 ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
        return true;
    }
    //recursive case
    if (ch[i][j+1] == 'O' && j+1 < n){
        ch[i][j]='1';
        bool x = RatMaze(ch, i, j+1, m, n);
        if(x){
            return true;
        }
        ch[i][j]='0'; //backtracking
    }
    if (ch[i+1][j] == 'O' && i+1 < m){
        ch[i][j]='1';
        bool y = RatMaze(ch, i+1, j, m, n);
        if(y){
            return true;
        }
        ch[i][j]='0'; //backtracking
    }
    if (ch[i-1][j] == 'O' && i-1 >= 0){
        ch[i][j]='1';
        bool y = RatMaze(ch, i-1, j, m, n);
        if(y){
            return true;
        }
        ch[i][j]='0'; //backtracking
    }
    if (ch[i][j-1] == 'O' && j-1 >= 0){
        ch[i][j]='1';
        bool y = RatMaze(ch, i, j-1, m, n);
        if(y){
            return true;
        }
        ch[i][j]='0'; //backtracking
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    char ch[1000][1000];
    int m,n;
    cin>>m>>n;
    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>ch[i][j];
        }
    }    
    int x = RatMaze(ch, 0, 0, m, n);
    if (x != 1){
        cout<<"NO PATH FOUND";
    } 
}