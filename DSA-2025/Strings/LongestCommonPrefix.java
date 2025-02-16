import java.util.*;


class Solution {
    public static String longestCommonPrefix(String[] strs) {
        
        //Optimized Code
         String answer = "";
        if(strs==null || strs.length == 0) {
            return answer;
        }
        
        //Arrays.sort(strs);
        int l = 0;
        int h = strs.length-1;
        mergeSort(strs,l,h);
        for(int i =0;i<strs.length;i++) {
            System.out.println( "The value is: " +strs[i]);
        }
        
        
        String firstString = strs[0];
        String lastString = strs[strs.length - 1];
        for(int i = 0; i < firstString.length();i++) {
            if(firstString.charAt(i) != lastString.charAt(i)) {
                break;
            }
            answer += firstString.charAt(i);
        }
        return answer;

    

        //Brute Force Approach
        // String firstString = strs[0];
        // String answer = "";
        // for(int i = 0; i < firstString.length();i++) {
        //     for(int j = 1; j < strs.length; j++) {
        //         if( i >= strs[j].length() || strs[j].isEmpty()) {
        //             return answer;
        //         }
        //         if(strs[j].charAt(i) != firstString.charAt(i) ) {
        //             return answer;
        //         }
                
        //     }
        //     answer += firstString.charAt(i);
        // }
        // return answer;
    }

    public static void merge(String[] input, int l, int mid, int h) {
        int n1 = (mid - l) + 1;
        int n2 = (h-mid);
        String[] firstArray = new String[n1];
        String[] secondArray = new String[n2];

        for(int i=0;i<n1;i++) {
            firstArray[i] = input[l+i];
        }
        for(int j=0;j<n2;j++) {
            secondArray[j] = input[mid+1+j];
        }

        int i = 0;
        int j = 0;
        int k = l;
        while(i<n1 && j<n2) {
            if(compareTo(firstArray[i],secondArray[j])<=0) {
                input[k] = firstArray[i];
                i++; 
            }
            else {
                input[k] = secondArray[j];
                j++;
            }
            k++;
        }
        while(i<n1) {
            input[k] = firstArray[i];
            i++;
            k++;
        }
        while(j<n2) {
            input[k] = secondArray[j];
            j++;
            k++;
        }
    }

    private static int compareTo(String firstString, String secondString) {
        int n = Math.min(firstString.length(), secondString.length());
        for(int i=0;i<n;i++) {
            int result = firstString.charAt(i) - secondString.charAt(i);
            if(result != 0) {
                return result;
            }
        }
        return firstString.length() - secondString.length();
    }

    public static void mergeSort(String[] input, int l, int h) {
        if(l<h) {
            
        int mid = l + (h-l) / 2;  // to avoid integer overflow this is done just a safe method

        mergeSort(input, l, mid);
        mergeSort(input, mid+1, h);
        merge(input,l,mid,h);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of string: ");
        int n = sc.nextInt();
        String[] input = new String[n];
        for(int i=0;i<n;i++) {
            System.out.println("Enter the " + (i+1) + " value: ");
            input[i] = sc.next();
        }
        String result = longestCommonPrefix(input);
        System.out.println("Longest Common Prefix: " + result);
    }
}