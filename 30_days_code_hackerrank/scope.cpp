#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
    vector<int>newarr;
    Difference(vector<int>e)
    {
        this->elements=e;
    }
    void computeDifference()
    {
        for(int i=0;i<elements.size()-1;i++)
        {
            for(int j=i+1;j<elements.size();j++)
            {
                newarr.push_back(abs(elements[i]-elements[j]));
            }
        }
        sort(newarr.begin(),newarr.end());
        maximumDifference=newarr[newarr.size()-1];
    }
	// Add your code here

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}