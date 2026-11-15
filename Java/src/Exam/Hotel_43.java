package Exam;

/*
  43. Hotel: Write a Java program using an array of objects to
   store the details of 5 Room objects
   (room no, type, rent, availability) and display the available
   rooms.
*/
class Room {
    private int roomNo;
    private String type;
    private double rent;
    private boolean isAvailable;

    // Constructor to initialize Room object
    public Room(int roomNo, String type, double rent, boolean isAvailable) {
        this.roomNo = roomNo;
        this.type = type;
        this.rent = rent;
        this.isAvailable = isAvailable;
    }

    // Method to check room availability
    public boolean isAvailable() {
        return isAvailable;
    }

    // Method to display room details
    public void displayDetails() {
        System.out.println("Room No      : " + roomNo);
        System.out.println("Room Type    : " + type);
        System.out.println("Rent/Night   : ₹" + rent);
        System.out.println("Availability : " + (isAvailable ? "Available" : "Occupied"));
        System.out.println("----------------------------------------");
    }
}

public class Hotel_43 {
    public static void main(String[] args) {
        Room[] rooms = new Room[5];

        // Initialize the 5 room objects
        rooms[0] = new Room(101, "Standard Non-AC", 1200.00, true);
        rooms[1] = new Room(102, "Standard AC", 1800.00, false);
        rooms[2] = new Room(201, "Deluxe AC", 2500.00, true);
        rooms[3] = new Room(202, "Super Deluxe", 3500.00, false);
        rooms[4] = new Room(301, "Executive Suite", 5000.00, true);

        System.out.println("--------------List of All Available Room ------------------- ");
        int availableCount = 0;

        for (int i = 0; i < rooms.length; i++) {
            if (rooms[i].isAvailable()) {
                rooms[i].displayDetails();
                availableCount++;
            }
        }

        System.out.println("Total Available Rooms : " + availableCount);
    }
}
