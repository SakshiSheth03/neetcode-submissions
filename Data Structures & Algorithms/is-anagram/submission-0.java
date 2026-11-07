class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.compareTo(t) != 0) {
            if(s.length() == t.length()) {
                int arr[] = new int[26];
                for(int i=0; i<s.length(); i++) {
                    int indexS = s.charAt(i) - 97;
                    int indexT = t.charAt(i) - 97;
                    arr[indexS]++;
                    arr[indexT]--;
                }
                for(int i=0; i<arr.length; i++) {
                    if(arr[i] != 0) {
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
