import java.util.*;

class Solution {
    public static String largestOddNumber(String num) {
        String answer = "";
        for(int i = num.length()-1; i >= 0; i--) {
            int digit = num.charAt(i) - '0';
            if(digit % 2 != 0) {
                answer = num.substring(0,i+1);
                break;
            }
        }
        return answer;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String input = sc.nextLine();
        String result = largestOddNumber(input);
        System.out.println("The result is : " +result);
    }
}