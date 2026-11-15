package Exam;

import java.io.*;

/*
  55. Hotel booking records: Store customer booking records using byte streams 
      (FileOutputStream, DataOutputStream) and read back with FileInputStream, DataInputStream.
*/
public class HotelBooking_55 {
    public static void main(String[] args) {
        System.out.println("===== Hotel Booking Records (Byte Streams) =====\n");

        String fileName = "hotel_bookings.dat";

        // 1. Writing records using FileOutputStream & DataOutputStream (Byte Streams)
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(fileName))) {
            // Write record 1: Booking ID, Customer Name, Room No, Total Bill
            dos.writeInt(101);
            dos.writeUTF("Rutvik Babariya");
            dos.writeInt(302);
            dos.writeDouble(4500.00);

            // Write record 2
            dos.writeInt(102);
            dos.writeUTF("Amit Patel");
            dos.writeInt(205);
            dos.writeDouble(3200.50);

            System.out.println("Records successfully written to " + fileName + "\n");
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }

        // 2. Reading records back using FileInputStream & DataInputStream (Byte Streams)
        System.out.println("--- Reading Booking Records from File ---");
        try (DataInputStream dis = new DataInputStream(new FileInputStream(fileName))) {
            while (dis.available() > 0) {
                int bookingId = dis.readInt();
                String customerName = dis.readUTF();
                int roomNo = dis.readInt();
                double bill = dis.readDouble();

                System.out.println("Booking ID  : " + bookingId);
                System.out.println("Customer    : " + customerName);
                System.out.println("Room No     : " + roomNo);
                System.out.println("Total Bill  : ₹" + bill);
                System.out.println("----------------------------------------");
            }
        } catch (IOException e) {
            System.out.println("Error reading from file: " + e.getMessage());
        }
    }
}
