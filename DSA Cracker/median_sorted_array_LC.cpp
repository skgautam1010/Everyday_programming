#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ar(n+m);
        double result;
        int i=0,j=0,k=0;
        if (m==0 && n==0)
        {
            return double(0);
        }
        while(i<m && j<n)
        {
               if(nums1[i]<nums2[j])
               {
                   ar[k]=nums1[i];
                   i++;
                   k++;
               }
                else if(nums1[i]>nums2[j])
                {
                    ar[k]=nums2[j];
                    k++;
                    j++;
                }
            else
            {
                ar[k]=nums1[i];
                k++;
                ar[k]=nums2[j];
                k++;
                i++;
                j++;
            }
        }
        while(i<m)
        {
            ar[k]=nums1[i];
            i++;
            k++;
        }
        while(j<n)
        {
            ar[k]=nums2[j];
            j++;
            k++;
        }
        for(int p:ar)
        {
            cout<<p<<"\t";
        }
        cout<<"\n";
        int x=ar.size();
        if(x%2==0)
        {
            int temp1=(x/2);
            int temp2=(x/2)+1;
            result=(double(ar[temp1-1])+double(ar[temp2-1]))/2;
            
        }
        else
        {
            int temp=(x+1)/2;
          result= ar[temp-1];
        }
        return result;
    }

int main()
{
    std::vector<int> nums1={1,2};
    std::vector<int> nums2={3,4};
    cout<<findMedianSortedArrays(nums1,nums2)<<"\n";
    return 0;
}