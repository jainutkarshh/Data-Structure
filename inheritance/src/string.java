//given 2 strings s &t ,return true if s is a subsequence of t ,else return false.a subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.

public class string {
    public static boolean isSubsequence(String s, String t, int n, int m) {
        int i = 0, j = 0;
        
        // n is length of s (subsequence), m is length of t (string)
        if (n > m) {
            return false;
        }
        
        while (i < n && j < m) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }
        
        return i == n;
    }
    public static void main(String[] args) {
        String s="ace";
        String t="abcde";
        int n=s.length();
        int m=t.length();
        boolean result=isSubsequence(s,t,n,m);
        System.out.println("Is '"+s+"' a subsequence of '"+t+"' : "+result);
    }
}

