package cz2002DionToh;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int choice;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Perform the following methods:");
            System.out.println("1: multiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    mulTest();
                    break;
                case 2:
                    System.out.print("Enter the dividend: ");
                    int op1 = sc.nextInt();
                    System.out.print("Enter the divisor: ");
                    int op2 = sc.nextInt();
                    divide(op1, op2);
                    break;
                case 3:
                    System.out.print("Enter the first operand: ");
                    op1 = sc.nextInt();
                    System.out.print("Enter the second operand: ");
                    op2 = sc.nextInt();
                    System.out.println("\n" + op1 + " % " + op2 + " = " + modulus(op1, op2) + "\n");
                    break;
                case 4:
                    System.out.print("Enter the integer: ");
                    op1 = sc.nextInt();
                    int result = countDigits(op1);
                    if (result == -1)
                        System.out.println("\nn: " + op1 + " - Error input!\n");
                    else
                        System.out.println("\nn: " + op1 + " - count = " + result + "\n");
                    break;
                case 5:
                    System.out.print("Enter the number: ");
                    op1 = sc.nextInt();
                    System.out.print("Enter the digit: ");
                    op2 = sc.nextInt();
                    System.out.println("position = " + position(op1, op2));
                    break;
                case 6:
                    System.out.print("Enter a number: ");
                    op1 = sc.nextInt();
                    long no = extractOddDigits(op1);
                    if (no == 0)
                        System.out.println("Error input!\n");
                    else
                        System.out.println(no + "\n");
                    break;
                case 7:
                    System.out.println("Program  terminating ....");
            }
        } while  (choice  <  7);
    }

    public static void mulTest() {
        Scanner sc = new Scanner(System.in);
        int counter = 0, userInput;
        for (int i =0; i<5; i++) {
            int op1, op2, result;
            op1 = (int) Math.floor(Math.random() * 9 + 1);
            op2 = (int) Math.floor(Math.random() * 9 + 1);
            result = op1 * op2;
            System.out.print("How much is " + op1 + " times " + op2 + "? ");
            userInput = sc.nextInt();
            if (userInput == result) {
                counter++;
            }
        }
        System.out.println("\n" + counter + " answers out of 5 are correct.\n");
    }

    public static void divide(int m, int n) {
        int counter = 0, op1 = m;

        while (m > 0) {
            m -= n;
            if (m >= 0)
                counter++;
        }
        System.out.println("\n" + op1 + "/" + n + " = " + counter + "\n");
    }

    public static int modulus(int m, int n) {
        while ((m-n) >= 0) {
            m -= n;
        }
        return m;
    }

    public static int countDigits(int n) {
        if (n < 0) {
            return -1;
        }
        int counter = 0;
        do {
            n /= 10;
            counter++;
        } while (n != 0);

        return counter;
    }

    public static int position(int n, int digit) {
        int len = countDigits(n);
        for (int i=0; i<len; i++) {
            if ((n - ((n/10)) * 10) == digit) {
                return (len-i);
            }
            else {
                n = n/10;
            }
        }
        return -1;
    }

    public static long extractOddDigits(long n) {
        if (n < 0) {
            System.out.print("\noddDigits = ");
            return 0;
        }
        int extracted = 0;
        double counter = 0;
        while (n != 0) {
            if (((n - ((n/10)) * 10) % 2) != 0) {
                extracted += (n - ((n/10)) * 10) * (int) Math.pow(10.0, counter);
                counter++;
            }
            n = n/10;
        }
        System.out.print("\noddDigits = ");
        if (extracted == 0) return -1;
        else return extracted;
    }

}