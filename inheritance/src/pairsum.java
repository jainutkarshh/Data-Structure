//given an array and a number k, find if there exists a pair in the array whose sum is equal to k and print the pair.if no such pair exists print appropriate message.

import java.util.Set;
import java.util.HashSet;

public class pairsum {
    public static void findPair(int arr[],int k){
        Set<Integer> set=new HashSet<>();
        for(int num:arr){
            
            if(set.contains(k-num)){
                System.out.println("Pair found: ("+(k-num)+", "+num+")");
                return;
            }
            set.add(num);
        }
        System.out.println("No pair found with sum " + k);

    }
    public static void main(String[] args) {
        int arr[]={10,15,3,7};
        int k=17;
        findPair(arr,k);
    }
}
