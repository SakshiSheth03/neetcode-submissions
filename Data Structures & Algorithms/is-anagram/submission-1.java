class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.compareTo(t) != 0) {
            if(s.length() == t.length()) {
                Map<Character, Integer> count = new HashMap<>();
        
                for (char x : s.toCharArray()) {
                    count.put(x, count.getOrDefault(x, 0) + 1);
                }
                
                for (char x : t.toCharArray()) {
                    count.put(x, count.getOrDefault(x, 0) - 1);
                }
                
                for (int val : count.values()) {
                    if (val != 0) {
                        return false;
                    }
                }
                
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
}
