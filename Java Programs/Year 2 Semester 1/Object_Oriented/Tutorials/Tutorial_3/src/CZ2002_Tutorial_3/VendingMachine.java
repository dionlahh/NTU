package CZ2002_Tutorial_3;

import java.util.ArrayList;
import java.util.Scanner;

public class VendingMachine {

    private ArrayList<Drink> menu;
    private double credit;

    public VendingMachine(ArrayList<Drink> menu) {
        this.menu = menu;
        credit = 0.0;
    }

    public ArrayList<Drink> getMenu() {
        return menu;
    }

    public double selectDrink() {

        System.out.println("====== Vending Machine ======" );
        for (int i = 0; i < menu.size(); i++) {
            System.out.println("|" + (i + 1) + ". Buy " + menu.get(i).getName() + " ($" + menu.get(i).getPrice() + ") |");
        }
        Scanner sc = new Scanner(System.in);
        int selection = sc.nextInt();
        return menu.get(selection-1).getPrice();
    }

    public double insertCoins(double drinkCost) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Please insert coins:\n" +
                "========== Coins Input ===========\n" +
                "|Enter 'Q' for ten cents input |\n" +
                "|Enter 'T' for twenty cents input|\n" +
                "|Enter 'F' for fifty cents input |\n" +
                "|Enter 'N' for a dollar input |\n" +
                "==================================");


        do {
            char selection = sc.next().charAt(0);

            switch (selection) {
                case 'Q' :
                case 'q' :
                    credit += 0.1;
                    break;

                case 'T' :
                case 't' :
                    credit += 0.2;
                    break;

                case 'F' :
                case 'f' :
                    credit += 0.5;
                    break;

                case 'N' :
                case 'n' :
                    credit += 1.0;
                    break;
            }
            System.out.printf("Coins inserted: %.2f\n", credit);
        } while (credit < drinkCost);

        return credit;
    }

    public double checkChange(double amount, double drinkCost) {
        System.out.printf("Change: $%.2f\n" , (amount - drinkCost));
        return amount - drinkCost;
    }

    public void printReceipt() {
        System.out.println("Please collect your drink\n" +
                "Thank You !!\n");
    }

}
