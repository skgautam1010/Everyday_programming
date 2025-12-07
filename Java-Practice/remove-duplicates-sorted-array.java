class RemoveDuplicates {
    private int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int i = 0;
        for(int j=1;j<nums.length;j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i;
        
    }
    
    public static void main(String[] args) {
        int[] nums = new int[]{0,0,1,1,1,2,2,2,3,3,4};
        RemoveDuplicates rd = new RemoveDuplicates();
        int val = rd.removeDuplicates(nums);
        for(int j=0;j<=val;j++) {
            System.out.print(nums[j] + " ");
        }
        System.out.println("\n");

    }
}