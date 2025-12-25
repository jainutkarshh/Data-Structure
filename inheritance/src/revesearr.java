//reverse an array array can contaain odd or even no of elements

public class revesearr {
    
    public static void reverseArray(int[] arr) {
        int low=0,high=arr.length-1;
        while(low<high){
            int temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
            low++;
            high--;
        }
    }
    public static void main(String[] args) {
        int[] arr={1,2,3,4,5};
        reverseArray(arr);
        System.out.print("Reversed array: ");
        for(int num:arr){
            System.out.print(num+" ");
        }
    }
}
