// given int array.Determine the lagrest sum of subarray wirh size w using sliding window technique.


public class sumsubarray {
   public static int maxSumSubarray(int[] arr, int w) {
    int n= arr.length;
    if (n < w) {
        System.out.println("Array size is smaller than the subarray size.");
        return -1;
    }
    int maxsum=0;
    for(int i=0;i<w;i++){
        maxsum+=arr[i];
    }
    int windowSum=maxsum;
    for(int i=w;i<n;i++){
        windowSum+=arr[i]-arr[i-w];
        maxsum=Math.max(maxsum,windowSum);
    }

    return maxsum;
   } 
    public static void main(String[] args) {
     int[] arr={3,8,2,6,9,10,4};
     int w=3;
     int result=maxSumSubarray(arr,w);
     if(result!=-1){
          System.out.println("Maximum sum of subarray of size "+w+" is: "+result);
     }
    }
}
