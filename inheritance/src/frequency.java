// cont the frequency of each character in a string using tree map amd ignore spaces
import java.util.TreeMap;
public class frequency {
    public static void main(String[] args) {
        String str ="databyte computers";
        TreeMap<Character,Integer> fmap = new TreeMap<>();
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            if(ch != ' '){
                fmap.put(ch,fmap.getOrDefault(ch, 0) + 1);
            }

        }
        System.out.println(fmap);
    }

}
