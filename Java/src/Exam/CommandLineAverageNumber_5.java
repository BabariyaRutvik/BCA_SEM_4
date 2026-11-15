package Exam;

/*
  5. Demonstrate the use of command line arguments by calculating the average of N numbers.
 */
public class CommandLineAverageNumber_5 {
    static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Please enter the number of commands you want to run.");
            return;
        }

        double sum =0;

        for (int i = 0; i<args.length;i++){
            sum = sum + Double.parseDouble(args[i]);
        }
        double average = sum/args.length;

        System.out.println("Sum : " +sum);
        System.out.println("Average : " +average);
    }



}
