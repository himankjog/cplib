#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int lps[str.length()];
    memset(lps, 0, sizeof(lps));
    for(int i = str.length()-1; i >= 0; --i){
        int prev_res = 0;
        for (int j = i ; j < str.length(); ++j){
            if(j == i){
                lps[j] = 1;
            }
            else if(str[i] == str[j]){
                int temp = lps[j];
                lps[j] = 2 + prev_res;
                prev_res = temp;
            }
            else{
                prev_res = lps[j];
                lps[j] = max(lps[j], lps[j-1]);
            }
        }
    }
    cout << lps[str.length()-1] << endl;
return 0;
}