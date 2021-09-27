package cz2002DionToh;
import java.util.Scanner;

public class P2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Salary: $");
        int salary = sc.nextInt();
        System.out.print("Merit points: ");
        int meritPoints = sc.nextInt();

        if  (salary >= 500 && salary <= 599) {
            System.out.println("Grade C!");
        }

        else if (salary >= 600 && salary <= 649) {
            if (meritPoints < 10) {
                System.out.println("Grade C!");
            } else {
                System.out.println("Grade B!");
            }
        }

        else if (salary >= 650 && salary <= 699) {
            System.out.println("Grade B!");
        }

        else if (salary >= 700 && salary <= 799) {
            if (meritPoints < 20) {
                System.out.println("Grade B!");
            } else {
                System.out.println("Grade A!");
            }
        }

        else if (salary >= 800 && salary <= 899) {
            System.out.println("Grade A!");
        }
    }
}