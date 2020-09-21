#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int fine=0;
    int y_expected,m_expected,d_expected;
    int act_year,act_month,act_day;
    cin>>act_day>>act_month>>act_year;
    cin>>d_expected>>m_expected>>y_expected;
    if((act_year-y_expected)==0 )
    {
        if((act_month-m_expected)==0)
        {
            
            if((act_day-d_expected)==0 )
            {
                cout<<fine<<endl;
            }
            else if(act_day-d_expected>0)
            {
                int temp1=act_day-d_expected;
                fine=15*temp1;
                cout<<fine<<endl;
            }
            else {
            cout<<fine<<endl;
            }
        }
        else if (act_month-m_expected>0) {
            int temp=act_month-m_expected;
            fine=500*temp;
            cout<<fine<<endl;
        }
        else {
            cout<<fine<<endl;
        }
    }
    else if(act_year-y_expected>0)
    {
        fine=10000;
        cout<<fine<<endl;
    }
    else
    {
        cout<<fine<<endl;
    }
    
    return 0;
}
