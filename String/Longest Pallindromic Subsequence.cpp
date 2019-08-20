#include <bits/stdc++.h>
using namespace std;

int lps[100][100];

void print(int size){
    for(int i = 0 ; i < size; i++){
        for(int j = 0 ; j < size; j++){
            cout << lps[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main(){
    string str;
    cin >> str;
    lps[0][0] = 1;
    for(int i = 1 ; i < str.length(); i++){
        lps[i][i] = 1;
        lps[i][i-1] = 0;
    }
    // print(str.length());
    for(int j = 1; j < str.length(); j++){
        int col = j;
        for(int i = 0; i < str.length()-j;++i, ++col){
            if(str[i] == str[col]) lps[i][col] = 2 + lps[i+1][col-1];
            else lps[i][col] = max(lps[i+1][col], lps[i][col-1]);
        }
        // print(str.length());
    }
    cout << lps[0][str.length()-1] << endl;
return 0;
}