#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    bool lps[str.length()][str.length()];
    lps[0][0] = true;
    for(int i = 1 ; i < str.length(); i++){
        lps[i][i] = true;
        lps[i][i-1] = true;
    }
    int maxi = 1;
    for(int j = 1; j < str.length(); j++){
        int col = j;
        for(int i = 0; i < str.length()-j; ++i, ++col){
            if(str[i] == str[col] && lps[i+1][col-1]){
                if ((col-i+1) > maxi) maxi = (col - i + 1);
                lps[i][col] = true;
            }else{
                lps[i][col] = false;
            }
        }
    }

    cout << maxi << endl;
return 0;
}