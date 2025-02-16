class Solution {
    public String reverseWords(String s) {


        //Optimized

        String ans = "";
        String temp = "";
        for(int i = 0;i<s.length();i++) {
            if(s.charAt(i) == ' ') {
                if(ans.equals("")) {
                    ans = temp;
                }
                else {
                    if(!temp.equals("")) {
                        ans = temp + ' ' + ans;
                    }
                    
                }
                temp = "";
            } else {
                temp += s.charAt(i);
            }
        }
        if(!temp.equals("")) {
            if(!ans.equals("")) {
                ans = temp + ' ' +ans;
            } else {
                ans = temp;
            }
            
        }
        return ans;


        //Brute force
        s = s.trim().replaceAll("\\s+"," ");
        String temp[] = s.split(" ");
        if(temp.length == 1) {
            return s;
        }
        int i = 0;
        int j = temp.length -1;
        while(i < j) {
            String tempVar = temp[i];
            temp[i] = temp[j];
            temp[j] = tempVar;
            i++;
            j--;
        }

        return String.join(" ",temp);

    }
}