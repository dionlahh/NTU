package cz2002DionToh;

import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int appSelect;
        int userInput;
        System.out.println("""
                ====    App Selection    ====
                |1. Circle App              |
                |2. Dice App                |""");
        appSelect = sc.nextInt();

        switch (appSelect) {
            case 1:
                Circle created = null;
                do {
                    System.out.println("""
                            ==== Circle Computation =====
                            |1. Create a new circle     |\s
                            |2. Print Area              |\s
                            |3. Print circumference     |\s
                            |4. Quit                    |\s
                            =============================""");
                    System.out.print("Choose option (1-3): ");
                    userInput = sc.nextInt();
                    if (userInput == 4) {
                        System.out.println("Terminating...");
                        break;
                    }

                    switch (userInput) {
                        case 1:
                            System.out.print("\nEnter the radius to compute the area  and circumference: ");
                            double userRadius = sc.nextDouble();
                            if (created == null) {
                                created = new Circle(userRadius);
                            } else {
                                created.setRadius(userRadius);
                            }
                            System.out.println("\nA new circle is created!\n");
                            break;
                        case 2:
                            if (created == null) {
                                System.out.println("No object created!\n");
                                continue;
                            } else {
                                created.printArea();
                                System.out.println();
                            }
                            break;
                        case 3:
                            if (created == null) {
                                System.out.println("No object created!\n");
                                continue;
                            } else {
                                created.printCircumference();
                                System.out.println();
                            }
                    }
                } while (true);
                break;
            case 2:
                int UPPER = 6;
                int LOWER = 1;
                do {
                    int total = 0;
                    Random r = new Random();
                    String enterPressed = sc.nextLine();
                    System.out.println("Press <Enter> to roll the first dice");
                    enterPressed = sc.nextLine();
                    Dice firstDice = new Dice();
                    firstDice.printDiceValue();
                    System.out.println();
                    total += firstDice.getDiceValue();
                    System.out.println("Press <Enter> to roll the second dice");
                    enterPressed = sc.nextLine();
                    firstDice.setDiceValue();
                    firstDice.printDiceValue();
                    total += firstDice.getDiceValue();
                    System.out.println();
                    System.out.println("Your total number is: " + total);
                    System.out.println("\nPress <1> to roll again!");
                    System.out.println("Press any other key to terminate");
                    userInput = sc.nextInt();

                } while (userInput == 1);
                System.out.println("Terminating...");
        }


    }
}
