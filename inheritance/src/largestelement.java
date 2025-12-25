// Find top 3 largest elements in an array
public class largestelement {
    int[] arr = {12, 35, 1, 10, 34, 1};
    
    public void findLargestElements() {
        int first, second, third;
        first = second = third = Integer.MIN_VALUE;
        
        for (int number : arr) {
            if (number > first) {
                third = second;
                second = first;
                first = number;
            } else if (number > second && number != first) {
                third = second;
                second = number;
            } else if (number > third && number != second && number != first) {
                third = number;
            }
        }
        
        System.out.println("The largest element is: " + first);
        System.out.println("The second largest element is: " + second);
        System.out.println("The third largest element is: " + third);
    }
    
    public static void main(String[] args) {
        largestelement obj = new largestelement();
        obj.findLargestElements();
    }
}
//optimesised code
