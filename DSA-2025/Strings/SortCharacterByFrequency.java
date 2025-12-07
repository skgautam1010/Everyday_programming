class Solution {
    public char[] merge(char[] firstArray, char[] secondArray, Map<Character,Integer> mp) {
        int n = firstArray.length;
        int m = secondArray.length;
        int i = 0;
        int j = 0;
        int k = 0;
        char[] ans = new char[n+m];
        while(i < n && j < m) {
            char firstChar = firstArray[i];
            char secondChar = secondArray[j];
            if(mp.get(firstChar) <= mp.get(secondChar)) {
                ans[k] = secondChar;
                j++;
            }
            else {
                ans[k] = firstChar;
                i++;
            }
            k++;
        }
        while(i < n) {
            char firstChar = firstArray[i];
            ans[k] = firstChar;
            i++;
            k++;
        }
        while(j<m) {
            char secondChar = secondArray[j];
            ans[k] = secondChar;
            j++;
            k++;
        }
        return ans;
    }
    public char[] mergeSort(char[] ch, int l, int h, Map<Character,Integer> mp)
    {
        if(l >= h) {
            return new char[0];
        }
        
        int mid = l + (h-l)/2;
        char[] firstArray = mergeSort(ch,0,mid,mp);
        char[] secondArray = mergeSort(ch,mid+1,h,mp);
        char[] result = merge(firstArray,secondArray, mp);
        return result;
        
    }
    public String frequencySort(String s) {
        if(s.length() <= 1) {
            return s;
        }
        Map<Character,Integer> mp = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            mp.put(ch, mp.getOrDefault(ch,0)+1);
        }
        char ch[] = s.toCharArray();
        char[] result = mergeSort(ch, 0, ch.length, mp);
        return new String(result);
    }


}