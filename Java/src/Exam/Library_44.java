package Exam;
/*
44. Library: Write a Java program to demonstrate wrapper classes, autoboxing
      and unboxing by converting string inputs (fine amount, book count) into
      Integer and Double values.
 */
public class Library_44
{
    public static void main(String[] args) {
        System.out.println("---------Library Management System------------------\n");

        // 1. String inputs
        String bookCounts ="5";
        String finePerDay = "12.50";
        String lastDays = "4";

        System.out.println("--- String inputs ---");
        System.out.println("Book Counts : \"" + bookCounts + "\"");
        System.out.println("Fine Per Day : \"" + finePerDay + "\"");
        System.out.println("Last Days : \"" + lastDays + "\"");

        // converting String to wrapper class objects
        Integer bookCountObj = Integer.valueOf(bookCounts);
        Double finePerDayObj = Double.valueOf(finePerDay);
        Integer lastDaysObj = Integer.valueOf(lastDays);

        // Autoboxing: automatic conversion from a primitive to its wrapper
        int lateDaysPrimitive = 4;
        Integer lateDaysObj = lateDaysPrimitive;
        System.out.println("Autoboxing demonstrated   : primitive int (" + lateDaysPrimitive + ") -> Integer object (" + lateDaysObj + ")");


        //  Unboxing: Automatic conversion of Wrapper Class object into primitive type
        int books = bookCountObj;
        double fineAmountPerDay = finePerDayObj;
        int days = lateDaysObj;

        System.out.println("Unboxing demonstrated     : Integer object (" + bookCountObj + ") -> primitive int (" + books + ")");
        System.out.println("Unboxing demonstrated     : Double object (" + finePerDayObj + ") -> primitive double (" + fineAmountPerDay + ")\n");

        // 5. Calculations using unboxed primitive variables
        double totalFine = books * days * fineAmountPerDay;
        System.out.println("--- Calculation Summary ---");
        System.out.println("Total Books Borrowed : " + books);
        System.out.println("Days Late            : " + days);
        System.out.println("Fine Per Book Per Day: Rs. " + fineAmountPerDay);
        System.out.println("Total Fine Amount    : Rs. " + totalFine);

    }
}
