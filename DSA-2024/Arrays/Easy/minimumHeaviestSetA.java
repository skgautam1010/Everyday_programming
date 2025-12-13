import java.util.*;
class MinimumHeaviestSet {
    public static List<Integer> reverseIntegers(List<Integer> arr) {
        List<Integer>answer = new LinkedList<>();
    Collections.sort(arr);
    int n = arr.size();
    if(n==1 || n==0) {
        return answer;
    }
    
    int sum=0;
    for(int i=0;i<n;i++) {
        sum = sum + arr.get(i);
    }
    int rem=0;
    for(int i=n-2;i>=0;i--) {
        rem = rem + arr.get(i+1);
        if(sum-(rem)<rem) {
            answer.add(arr.get(i+1));
            Collections.reverse(answer);
            return answer;
        } else {
            answer.add(arr.get(i+1));
        }
    }
    Collections.reverse(answer);
    return answer;
    }
    
}