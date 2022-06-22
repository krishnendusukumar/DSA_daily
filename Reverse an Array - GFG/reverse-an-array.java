/*package whatever //do not write package name here */

import java.util.*;

class GFG {

    public static void main(String[] args) {
        // code

        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        while (t > 0) {
            int n = scn.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scn.nextInt();
            }
            int i = 0, j = arr.length - 1;
            while (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
            for (int y = 0; y < arr.length; y++) {
                System.out.print(arr[y] + " ");
            }
            System.out.println();
            t--;
        }
    }
}