public class SelectionSort {
    public void selectionSort(int[] nums){
        int n = nums.length;
        for(int i = 0; i < n; i++){
            int minIndex = i;
            for(int j = i + 1; j < n; j++){
                if(nums[j] < nums[minIndex]) minIndex = j;
            }

            //swap(nums[i], nums[minIndex]);
            int temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
        }
    }

    public void swap(int a, int b){
        int temp = b;
        b = a;
        a = temp;
    }

    public static void main(String[] args) {
        SelectionSort ob = new SelectionSort();
        int[] arr = {5,4,3,1,6,8,9};
        ob.selectionSort(arr);
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i]);
        }
    }
}
