import java.util.Scanner;

public class selection {
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            swapped = false;
            
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                    swapped = true;
                }
            }
            
            if (swapped) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        
        int[] arr = new int[n];
        System.out.println("Enter array elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        selectionSort(arr);
        
        System.out.println("Sorted array: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        
        sc.close();
    }
}