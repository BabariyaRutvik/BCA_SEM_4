package Exam;

/*
  45. Employee payroll: Write a Java program to demonstrate dynamic method dispatch
      using an Employee reference that points to Manager and Developer objects to calculate salary.
*/
public class Payroll_45 {

    // Base Class
    static class Employee {
        String name;
        double baseSalary;

        public Employee(String name, double baseSalary) {
            this.name = name;
            this.baseSalary = baseSalary;
        }

        // Method to be overridden by subclasses
        public void calculateSalary() {
            System.out.println("Employee: " + name + " | Base Salary: ₹" + baseSalary);
        }
    }

    // Subclass: Manager
    static class Manager extends Employee {
        double bonus;

        public Manager(String name, double baseSalary, double bonus) {
            super(name, baseSalary);
            this.bonus = bonus;
        }

        @Override
        public void calculateSalary() {
            double totalSalary = baseSalary + bonus;
            System.out.println("Role: Manager");
            System.out.println("Name         : " + name);
            System.out.println("Base Salary  : ₹" + baseSalary);
            System.out.println("Bonus        : ₹" + bonus);
            System.out.println("Total Salary : ₹" + totalSalary);
            System.out.println("----------------------------------------");
        }
    }

    // Subclass: Developer
    static class Developer extends Employee {
        double projectAllowance;

        public Developer(String name, double baseSalary, double projectAllowance) {
            super(name, baseSalary);
            this.projectAllowance = projectAllowance;
        }

        @Override
        public void calculateSalary() {
            double totalSalary = baseSalary + projectAllowance;
            System.out.println("Role: Developer");
            System.out.println("Name              : " + name);
            System.out.println("Base Salary       : ₹" + baseSalary);
            System.out.println("Project Allowance : ₹" + projectAllowance);
            System.out.println("Total Salary      : ₹" + totalSalary);
            System.out.println("----------------------------------------");
        }
    }

    public static void main(String[] args) {
        System.out.println("===== Dynamic Method Dispatch (Payroll Demo) =====\n");

        // Superclass reference variable
        Employee emp;

        // 1. Employee reference pointing to a Manager object
        emp = new Manager("Rutvik Babariya", 60000.00, 15000.00);
        emp.calculateSalary();

        // 2. Same Employee reference pointing to a Developer object
        emp = new Developer("Amit Sharma", 45000.00, 10000.00);
        emp.calculateSalary();
    }
}
