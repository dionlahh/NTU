package cz2002DionToh;

import java.util.Arrays;

public class Plane {

    private PlaneSeat[] seats;
    private int numEmptySeat;
    private int noOfSeats;
//    private final int TOTAL = 12;

    public Plane(int noOfSeats) {
        seats = new PlaneSeat[noOfSeats];              // Creates array
        for (int i = 0; i <noOfSeats ; i++) {          // Assigns object to each array element
            seats[i] = new PlaneSeat(i+1);
        }
        numEmptySeat = noOfSeats;
        this.noOfSeats = noOfSeats;
    }

    private PlaneSeat[] sortSeats() {               // Sorts by customerID
        PlaneSeat[] copy = new PlaneSeat[noOfSeats];
        int[] cus = new int[noOfSeats];
        for (int i = 0; i < noOfSeats; i++) {
            cus[i] = seats[i].getCustomerID();
        }
        Arrays.sort(cus);
        for (int i = 0; i < noOfSeats; i++) {
            for (int j = 0; j < noOfSeats; j++) {
                if (cus[i] == seats[j].getCustomerID()) {
                    copy[i] = seats[j];
                    break;
                }
            }
        }
        return copy;
    }

    public void showNumEmptySeats() {
        System.out.println("There are " + numEmptySeat + " empty seats\n");
    }

    public void showEmptySeats() {
        System.out.print("The following seats are empty: \n");
        for (int i = 0; i < noOfSeats; i++) {
            if (!seats[i].isOccupied())
            System.out.println("SeatID " + seats[i].getSeatID());
        }
        System.out.println();
    }

    public void showAssignedSeats(boolean bySeatID) {
        System.out.print("The seat assignments are as follows: \n");
        if (bySeatID) {
            for (int i = 0; i < noOfSeats; i++) {
                if (seats[i].isOccupied())
                    System.out.println("SeatID " + seats[i].getSeatID() + " is assigned to CustomerID " + seats[i].getCustomerID());
            }
        }
        else {
            PlaneSeat[] copy = sortSeats();
            for (int i = 0; i < noOfSeats; i++) {
                if (copy[i].isOccupied())
                    System.out.println("SeatID " + copy[i].getSeatID() + " is assigned to CustomerID " + copy[i].getCustomerID());
            }
        }
        System.out.println();
        return;
    }

    public void assignSeat(int SeatID, int cust_ID) {
        for (int i = 0; i < noOfSeats; i++) {
            if (seats[i].getSeatID() == SeatID) {
                if (seats[i].isOccupied()) {
                    System.out.println("Seat is already occupied!");
                }
                else {
                    seats[i].assign(cust_ID);
                    numEmptySeat--;
                    System.out.println("Assigned Customer " + cust_ID + " to Seat " + SeatID + "!");
                }
                return;
            }
        }
        System.out.println("Invalid Seat ID!");
    }

    public void unAssignSeat(int SeatID) {
        for (int i = 0; i < noOfSeats; i++) {
            if (seats[i].getSeatID() == SeatID) {
                if (seats[i].isOccupied()) {
                    seats[i].unAssign();
                    numEmptySeat++;
                    System.out.println("Seat " + SeatID + " has been successfully unassigned!");
                }
                else {
                    System.out.println("Seat " + SeatID + " is not currently assigned.");
                }
                return;
            }
        }
        System.out.println("Invalid Seat ID!");
    }
}
