package com.Abhi;
import java.util.*;



public class RotateArray {
    public static void main(String[] args) {

    }
    public void rotate(int[] nums, int k) {
        List<Integer> req = new ArrayList<>();
            if(k<nums.length){
                for(int i=nums.length-k; i<nums.length; i++){
                    req.add(nums[i]);

                }
                for(int i=0; i< nums.length-k; i++){
                    req.add(nums[i]);
                }
                for(int i=0; i<nums.length; i++){
                    nums[i]= req.get(i);
                }


            }
            else{
                for(int i= (nums.length-1); i>=0;i--){
                    req.add(nums[i]);
                }
                for(int i=0; i<nums.length;i++){
                    nums[i]=req.get(i);
                }
            }


    }
}
/*
class FindPivot {
    public void rotate(int[] nums, int k) {
        List<Integer> req = new ArrayList<>();
        if(k<=nums.length){
            for(int i=nums.length-k; i<nums.length; i++){
            req.add(nums[i]);

            }
            for(int i=0; i< nums.length-k; i++){
                req.add(nums[i]);
            }
            for(int i=0; i<nums.length; i++){
                nums[i]= req.get(i);
            }


        }
        else{
            k=k%nums.length;
            for(int i=nums.length-k; i<nums.length; i++){
            req.add(nums[i]);

            }
            for(int i=0; i< nums.length-k; i++){
                req.add(nums[i]);
            }
            for(int i=0; i<nums.length; i++){
                nums[i]= req.get(i);
            }


        }


    }
}
 */

