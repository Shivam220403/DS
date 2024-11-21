#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;

    int hash[26] = {0};
    for (int i = 0; i < int(s.size()); i++){
        hash[s[i]-'a']++; 
    }
    
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
    return 0;
} 