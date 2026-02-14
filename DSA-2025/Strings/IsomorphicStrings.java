import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }
        Map<Character, Character> result = new HashMap<>();
       

        for(int i=0;i<s.length();i++) {
            if(!result.containsKey(s.charAt(i))) {
                if(!result.containsValue(t.charAt(i))) {
                    result.put(s.charAt(i),t.charAt(i));
                } else {
                    return false;
                }
                
            }
            else {
                if(result.get(s.charAt(i)) != t.charAt(i)) {
                    return false;
                }
        
            }
        }
        
        return true;


    }
}