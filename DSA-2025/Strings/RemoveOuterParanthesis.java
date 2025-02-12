class Solution {
    public String removeOuterParentheses(String s) {


        //Optimal Approach
         String ans = "";
        int counter = 0;
        for(int i=0;i<s.length();i++) {

            if(s.charAt(i) == '(') {
            if(counter != 0) {
                ans += s.charAt(i);
                counter++;

            }else {
                counter++;
            }
                
            }
            if(s.charAt(i) == ')') {
                counter--;
                if(counter != 0) {
                    ans += s.charAt(i);
                }
            }
            
        }
        return ans;


        //Brute Force Approach
        Stack<Character> validPara = new Stack<>();

        String ans = "";
       
        for(int i=0;i<s.length();i++) {

            if(s.charAt(i) == '(') {
            if(validPara.isEmpty()) {
                validPara.push(s.charAt(i));
            }else {
                validPara.push(s.charAt(i));
                ans += s.charAt(i);
            }
                
            }
            if(s.charAt(i) == ')') {
                validPara.pop();
                if(!validPara.isEmpty()) {
                    ans += s.charAt(i);
                }
            }
            
        }
        return ans;
    }
}