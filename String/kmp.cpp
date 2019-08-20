#include <bits/stdc++.h>
using namespace std;

string str, pat;
int *lps;
void computeLPS(){
    memset(lps, 0, sizeof(lps));
    for(int i = 1; i < pat.length(); i++){
        int last = lps[i-1];
        if(pat[i] == pat[last]){
            lps[i] = lps[i-1] + 1;
        }
        else{
            int index = last;
            bool found = false;
            while(index && !found){
                index = lps[index-1];
                if(pat[index] == pat[i]){
                    lps[i] = index + 1;
                    found = true;
                    break;
                }
            }
            if(!found) lps[i] = 0;
        }
    }

    for(int i = 0; i < pat.length(); i++){
        cout << lps[i] << "  ";
    }
    cout << endl;
}

void kmp(){
    int j=0;
    for(int i = 0 ; i < str.length(); i++){
        if(pat[j] == str[i]){
            ++j;
            if(j == pat.length()){
                cout << "Found at index i: " << i-j+1 << endl;
                j = lps[j-1];
            }
        }
        else{
            while(j > 0){
                j = lps[j-1];
                if(pat[j] == str[i]){
                    ++j;
                    break;
                }
            }
        }
    }
}

int main(){
    cin >> str >> pat;
    lps = new int[pat.length()];
    computeLPS();
    kmp();
return 0;
}