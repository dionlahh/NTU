package cz2002DionToh;

public class PlaneSeat {

    private int seatID;
    private boolean assigned;
    private int customerID;

    public PlaneSeat(int seatID) {
        this.seatID = seatID;
        assigned = false;
        customerID = -1;
    }

    public int getSeatID() {
        return seatID;
    }

    public int getCustomerID() {
        return customerID;
    }

    public boolean isOccupied() {
        return assigned;
    }

    public void assign(int customerID) {
        this.customerID = customerID;
        assigned = true;
    }

    public void unAssign() {
        assigned = false;
    }
}
