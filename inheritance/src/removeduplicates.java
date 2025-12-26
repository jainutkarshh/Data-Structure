//wap to remove duplicates from an array

import java.util.LinkedHashSet;

public class removeduplicates {
    public static void main(String[] args) {
        int arr[] = {10, 20, 10, 30, 40, 20, 50, 30};
        int i;
        System.out.println("Original array:");
        for (i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        int[] nos = removeDuplicates(arr);
        // we want to have nos reloacted in memoery bcoz its length is going to change.
        System.out.println("\nArray after removing duplicates:");
        for (i = 0; i < nos.length; i++) {
            System.out.print(nos[i] + " ");
        }
    }
        static int[] removeDuplicates(int[] arr) {
        LinkedHashSet<Integer> set = new LinkedHashSet<>();
        //add one by one element to set
        for (int num : arr) {
            set.add(num);
        }
        // declare new array of size equal to set size
        int[] result = new int[set.size()];
        int index = 0;
        //copy elements from set to array
        for (int num : set) {
            result[index++] = num;
        }
        return result;
    }
}
    