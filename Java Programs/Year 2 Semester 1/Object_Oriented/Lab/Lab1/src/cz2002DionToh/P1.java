package cz2002DionToh;

import jdk.swing.interop.SwingInterOpUtils;

import java.util.Scanner;

public class P1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter: ");
        char userInput = sc.next().charAt(0);

        switch (userInput) {
            case 'a':
            case 'A':
                System.out.println("Action movie fan");
                break;
            case 'c':
                System.out.println("Comedy movie fan");
                break;
            case 'C':
                System.out.println("Comedy movie fan");
                break;
            case 'D':
                System.out.println("Drama movie fan");
                break;
            case 'd':
                System.out.println("Drama movie fan");
                break;
            default:
                System.out.println("Invalid input");
                break;

        }
    }
}
