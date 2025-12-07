class Solution {
    public boolean isAnagram(String s, String t) {
        //approach 2
        if(s.length() != t.length()) {
            return false;
        }
        Map<Character,Integer> mp = new HashMap<>();
        for(int i =0;i<s.length();i++) {
            char ch = s.charAt(i);
            mp.put(ch, mp.getOrDefault(ch,0)+1);
        }
        for(int i=0;i<t.length();i++){
            char ch = t.charAt(i);
            mp.put(ch,mp.getOrDefault(ch,-1)-1);
        }
        for(int i=0;i<s.length();i++){
           
            int sVal = mp.get(s.charAt(i));
            
            if(sVal != 0) {
                return false;
            }
        }
        return true;
    }

    //approach 1

    public String sortString(String s) {
        char c[] = s.toCharArray();
        Arrays.sort(c);
        return new String(c);
    }
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }
        s = sortString(s);
        t = sortString(t);

        for(int i=0;i<s.length();i++){
           if(s.charAt(i) != t.charAt(i)) {
            return false;
           }
        }
        return true;
    }
}