#include<bits/stdc++.h>
using namespace std;
string get_colour(string s){
    if (s.length() == 1) return s;
    string sn;
    for (int i = 0; i < s.length()-1; i++){
        vector<char> c {'R', 'G', 'B'};
        if (s[i] == s[i+1]) sn += s[i];
        else{
            if (s[i] == 'R'){
                if (s[i+1] == 'G') sn += 'B';
                else sn += 'G';
            } else if (s[i] == 'G'){
                if (s[i+1] == 'R') sn += 'B';
                else sn += 'R';
            } else {
                if (s[i+1] == 'R') sn += 'G';
                else sn += 'R';
            }
        }
    }

    return get_colour(sn);

}

int main(){
    string s;
    cin >> s;
    
    cout << get_colour(s);
    return 0;
}