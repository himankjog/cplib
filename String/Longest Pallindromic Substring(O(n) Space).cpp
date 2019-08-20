#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int maxi = 1;
    for(int i = 0 ; i < str.length(); i++){
        int odd_len=1, even_len = 0;
        int a,b;

        // Even len
        a = i;
        b = i+1;
        while(a >= 0 && b < str.length() && str[a] == str[b]){
            even_len += 2;
            --a; ++b;
        }

        // Odd Len
        a = i-1;
        b = i+1;
        while(a >= 0 && b < str.length() && str[a] == str[b]){
            odd_len += 2;
            --a; ++b;
        }

        maxi = max(maxi, max(odd_len, even_len));
    }
    cout << maxi << endl;
return 0;
}