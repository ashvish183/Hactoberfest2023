package com.Abhi;

import java.util.Scanner;

public class checkAscending {
    public static void main(String[] args) {
        // Input an array of numbers and check if they are in ascending order.

        Scanner in = new Scanner(System.in);
        System.out.print("Size of the array: ");
        int size = in.nextInt();
        int[] list = new int[size];

        //taking input
        for (int i = 0; i < size; i++) {
            list[i] = in.nextInt();
        }

        //printing the array.
        System.out.print("Given array: { ");
        for (int i = 0; i < size; i++) {
            System.out.print(list[i] + " ");
        }
        System.out.println("}");

        //check for order.
        int count = 0;
        for (int i = 1; i < size; i++) {
            if(list[i-1]>list[i]){
                count++;
            }

        }
        if (count == 0) {
            System.out.println("The given array is sorted in ascending order.");
        } else {
            System.out.println("The given array is not sorted in ascending order.");
        }

        //Arranging in ascending order.
        for (int i = 0; i < size-1; i++) {
            for (int j = i+1; j < size; j++) {
                if (list[i] > list[j]) {
                    int temp= list[i];                   //This is better I think.
                    list[i]=list[j];
                    list[j]=temp;

/*
                    int temp = list[j];                 //Not the most optimised form.
                    list[j] = list[j - 1];
                    list[j - 1] = temp;
*/
                }
            }

        }

        //Printing the sorted list...
        for (int i = 0; i < size; i++) {
            System.out.print(list[i]+" ");

        }
    }
}
