package com.Abhi;

public class Kadanes_algo {
    public static void main(String[] args) {
        int[] req= {-2,1,-3,4,-1,2,1,-5,4};
        int answer=maxSubArray(req);
        System.out.println(answer);
    }
    public static int maxSubArray(int[] nums) {
        //Kadane's algorithm
        int max_so_far=Integer.MIN_VALUE;
        int max_ending_here= 0;
        for (int num : nums) {
            max_ending_here += num;
            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
            }
        }

        return max_so_far;

    }
}