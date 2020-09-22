#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    string name;
    long number;
    map<string,long>pbook;
    for(int i=0;i<n;i++)
    {
        cin>>name;
        cin>>number;
        pbook[name]=number;
    } 
    /*map<string,long> ::iterator i;
    for(i=pbook.begin();i!=pbook.end();i++)
    {
        cout<<i->first<<" "<<i->second<<endl;
    }*/
    while (cin>>name) {
        if(pbook.find(name)!=pbook.end())
        {
            cout<<pbook.find(name)->first<<"="<<pbook.find(name)->second<<endl;
        }
        else {
        cout<<"Not found"<<endl;
        }
    }
     
    return 0;
}
