//program to check whether two strings are equivalent or not according to given condition

//Given two strings A and B of equal size. Two strings are equivalent either of the following conditions hold true:
//1) They both are equal. Or,
//2) If we divide the string A into two contiguous substrings of same size A1 and A2 and string B into two contiguous substrings of same size B1 and B2, then one of the following should be correct:

#include<bits/stdc++.h>

using namespace std;

string lexigraph(string a)
{
	if(a.size()==1)
	{
		return a;
	}
	string x=lexigraph(a.substr(0,a.size()/2));
	string y=lexigraph(a.substr(a.size()/2));
	return min(x+y,y+x);
}

bool areEquivalent(string a ,string b)
{
	return (lexigraph(a)==lexigraph(b));
}

int main() 
{ 
    string a = "aaba"; 
    string b = "abaa"; 
    if (areEquivalent(a, b)) 
        cout << "YES" << endl; 
    else
        cout << "NO" << endl; 
  
    a = "aabb"; 
    b = "abab"; 
    if (areEquivalent(a, b)) 
        cout << "YES" << endl; 
    else
        cout << "NO" << endl; 
    return 0; 
} 