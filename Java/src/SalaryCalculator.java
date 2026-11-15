import java.util.Scanner;

public class SalaryCalculator
{
    static void main() {
        String name ;
        double basic_salary;
        int experience = 0;

        // taking the input from the user
        System.out.println("Welcome to SalaryCalculator");

        Scanner input = new Scanner(System.in);

        System.out.print("Enter your name: ");
        name = input.nextLine();

        System.out.print("Enter your basic salary: ");
        basic_salary = input.nextDouble();

        System.out.println("Enter your Experience:");
        experience = input.nextInt();


        double hra = basic_salary * 0.20;
        double da =  basic_salary * 0.1;
        double salary = basic_salary + hra + da;


        double bonus;

        if (experience >= 5){
            bonus = 5000;

        }
        else {
            bonus = 2000;
        }

        double netSalary = salary + bonus;

        System.out.println("------------------------Salary Details-------------------------------");
        System.out.println("Employee Name: " + name);
        System.out.println("Employee Salary: " + salary);
        System.out.println("Employee Basic Salary: " + basic_salary);
        System.out.println("Employee Experience Rate: " + experience);
        System.out.println("Employee Net Salary: " + netSalary);

    }
}
