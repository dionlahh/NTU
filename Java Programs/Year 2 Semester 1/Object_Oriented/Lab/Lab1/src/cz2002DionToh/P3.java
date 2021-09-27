package cz2002DionToh;

import java.util.Scanner;

public class P3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Start: ");
        int start = sc.nextInt();
        System.out.print("End: ");
        int end = sc.nextInt();
        System.out.print("Increment: ");
        int increment = sc.nextInt();
        if (start > end || (start == 0 && end == 0))
        {
            System.out.println("Invalid input!");
        }
        else {
            System.out.println();
            System.out.println();
            System.out.println("US$       S$");
            System.out.println("-------------");

            for (int i = start; i<= end; i+=increment) {
                System.out.println(i + "       " + i*1.82);
            }

            int j=start;
            System.out.println();
            System.out.println();
            System.out.println("US$       S$");
            System.out.println("-------------");
            while (j<=end) {
                System.out.println(j + "       " + j*1.82);
                j += increment;
            }

            int k=start;
            System.out.println();
            System.out.println();
            System.out.println("US$       S$");
            System.out.println("-------------");
            do {
                System.out.println(k + "       " + k*1.82);
                k += increment;
            } while (k<=end);
        }

    }
}
