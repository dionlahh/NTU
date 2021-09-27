package CZ2002_Tutorial_3;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Question 1 or Question 2?");
        System.out.print("Enter your selection: ");
        int userInput = sc.nextInt();
        switch (userInput) {
            case 1:
                double cost, amountedInserted, change;
                Drink Beer = new Drink("Beer", 3.0);
                Drink Coke = new Drink("Coke", 1.2);
                Drink Sprite = new Drink("Sprite", 1.2);
                Drink Pepsi = new Drink("Pepsi", 1.2);
                Drink GreenTea = new Drink("Green Tea", 5.0);
                ArrayList<Drink> menu = new ArrayList<Drink>();
                menu.add(Beer);
                menu.add(Coke);
                menu.add(Sprite);
                menu.add(Pepsi);
                menu.add(GreenTea);
                VendingMachine machine1 = new VendingMachine(menu);
                cost = machine1.selectDrink();
                amountedInserted = machine1.insertCoins(cost);
                machine1.checkChange(amountedInserted, cost);
                machine1.printReceipt();
                break;
            case 2:
                System.out.println("Create a Point:");
                System.out.print("Enter x coordinates: ");
                int x = sc.nextInt();
                System.out.print("Enter y coordinates: ");
                int y = sc.nextInt();
                Point point1 = new Point(x,y);
                System.out.println(point1.toString());
                System.out.println("Create a Circle from the Point:");
                System.out.print("Enter radius: ");
                double rad = sc.nextDouble();
                Circle circle1 = new Circle(x, y, rad);
                System.out.println(circle1.toString());
                System.out.println("Create a Cylinder from the Circle:");
                System.out.print("Enter height: ");
                double height = sc.nextDouble();
                Cylinder cylinder1 = new Cylinder(x, y, rad, height);
                System.out.println(cylinder1.toString());
        }
    }
}
