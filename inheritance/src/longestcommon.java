// find the longest common subsequence in an given array
import java.util.HashSet;
import java.util.Set;
public class longestcommon {
    int longestCommon(int arr[]){
        Set<Integer> s=new HashSet<>();
        for(int i:arr){
            s.add(i);
        }
        int res=1;
        for(int i:arr){
            if(s.contains(i-1)==false){
                int curr=i;
                int currstreak=1;
                while(s.contains(curr+1)){
                    curr++;
                    currstreak+=1;
                }
                res=Math.max(res,currstreak);
            }
    }
    return res;
    }
    public static void main(String[] args) {
        longestcommon lc=new longestcommon();
        int arr[]={10,4,20,1,3,2};
        System.out.println("Length of longest consecutive sequence is: " + lc.longestCommon(arr));
    }
}
