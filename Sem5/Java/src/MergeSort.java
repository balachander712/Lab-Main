public class MergeSort {

    public void sort(int[] nums){
        mergeSort(nums, 0, nums.length);
    }

    public void mergeSort(int[] nums, int start, int end){
        if(end - start < 2) return;

        int mid = (start + end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid, end);
        merge(nums, start, mid, end);
    }

    public void merge(int[] nums, int start, int mid, int end){
        int i = start;
        int j = mid;

        int[] temp = new int[end - start];
        int tempIndex = 0;
        while (i < mid && j < end){
            if(nums[i] <= nums[j]){
                temp[tempIndex++] = nums[i++];
            } else {
                temp[tempIndex++] = nums[j++];
            }
        }

        while (i < mid){
            temp[tempIndex++] = nums[i++];
        }

        while (j < end){
            temp[tempIndex++] = nums[j++];
        }

        System.arraycopy(temp, 0, nums, start, tempIndex);
    }

    public static void main(String[] args) {
        int[] arr = {10, 11, 23, 50, 21};
        MergeSort ob = new MergeSort();
        ob.sort(arr);
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }

}
