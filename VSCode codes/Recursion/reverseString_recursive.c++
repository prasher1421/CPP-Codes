#include <bits/stdc++.h>
using namespace std;

void reverseString(string &str, int i, int j){
    if(i>=j)
        return;
    
    swap(str[i++],str[j--]);

    return reverseString(str,i,j);
}

int main(){
    string name = "Aryan Prasher";
    reverseString(name,0,4);
    cout<<name;
}