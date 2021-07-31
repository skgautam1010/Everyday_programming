#include<bits/stdc++.h>

using namespace std;

/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>>ans;
      /*  for(string a:strs)
        {
            cout<<a<<" ";
        }*/
        for(string a:strs)
        {
            string temp=a;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(a);
        }
        
        for(auto a:mp)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};