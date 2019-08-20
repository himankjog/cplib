#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int lps[s.length()];
    memset(lps, 0, sizeof(lps));
    for(int i = 1; i < s.length(); i++ ){
        int last = lps[i-1];
        if(s[i] == s[last]){
            lps[i] = 1+lps[i-1];
        }
        else{
            int index = last;
            bool found = false;
            while(index && !found){
                index = lps[index-1];
                if(s[index] == s[i]){
                    lps[i] = index+1;
                    found = true;
                    break;
                }
            }
            if(!found) lps[i] = 0;
        }
    }

    for(int i = 0 ; i < s.length(); i++){
        cout << lps[i] << " ";
    }
    cout << endl;
return 0;
}