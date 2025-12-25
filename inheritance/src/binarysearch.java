public class binarysearch {
    public static int binSearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        int target = 70;
        int result = binSearch(arr, target);
        
        if (result == -1) {
            System.out.println("Element not found in the array");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }
}
