package cz2002DionToh;

import java.util.Scanner;

public class P4 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Height: ");
        int height = sc.nextInt();
        if (height == 0) {
            System.out.println("Error input!");
        }

        else {
            for (int i =0; i<height;i++) {
                for (int j=0; j<i+1; j++) {
                    if (i%2 == 0) {
                        if (j%2 == 0) {
                            System.out.print("AA");
                        }
                        else {
                            System.out.print("BB");
                        }
                    }
                    else {
                        if (j%2 != 0) {
                            System.out.print("AA");
                        }
                        else {
                            System.out.print("BB");
                        }
                    }
                }
                System.out.println();
            }
        }
    }
}
