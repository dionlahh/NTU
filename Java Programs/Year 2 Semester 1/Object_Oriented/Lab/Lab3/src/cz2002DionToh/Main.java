package cz2002DionToh;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter the total number of seats: ");
        System.out.println();
        int noOfSeats = sc.nextInt();
        Plane plane = new Plane(noOfSeats);
        int userInput;
        System.out.println("(1) Show number of empty seats\n" +
                "(2) Show the list of empty seats\n" +
                "(3) Show the list of seat assignments by seat ID\n" +
                "(4) Show the list of seat assignments by customer ID\n" +
                "(5) Assign a customer to a seat\n" +
                "(6) Remove a seat assignment\n" +
                "(7) Exit\n");
        do {
            System.out.print("Enter the number of your choice: ");
            userInput = sc.nextInt();
            System.out.println();

            switch (userInput) {
                case 1:
                    plane.showNumEmptySeats();
                    break;
                case 2:
                    plane.showEmptySeats();
                    break;
                case 3:
                    plane.showAssignedSeats(true);
                    break;
                case 4:
                    plane.showAssignedSeats(false);
                    break;
                case 5:
                    System.out.print("Please enter SeatID: ");
                    int seatID = sc.nextInt();
                    System.out.println();
                    System.out.print("Please enter Customer ID: ");
                    int custID = sc.nextInt();
                    System.out.println();
                    plane.assignSeat(seatID, custID);
                    break;
                case 6:
                    System.out.print("Please enter SeatID: ");
                    seatID = sc.nextInt();
                    System.out.println();
                    plane.unAssignSeat(seatID);
                    break;
                case 7:
                    System.out.println("Terminating...");
                    break;
                default:
                    System.out.println("Invalid input!");
                    break;
            }
        } while (userInput != 7);
    }
}
