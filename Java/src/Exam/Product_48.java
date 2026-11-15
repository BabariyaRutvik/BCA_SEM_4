package Exam;

import java.util.Objects;

/*
  48. Shop/product: Write a Java program to override toString(), equals()
      and hashCode() of the Object class in a Product class and compare two products.
*/
class Product {
    int id;
    String name;

    public Product(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return "Product{id=" + id + ", name='" + name + "'}";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Product p = (Product) obj;
        return id == p.id && Objects.equals(name, p.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name);
    }
}

public class Product_48 {
    public static void main(String[] args) {
        Product p1 = new Product(101, "Laptop");
        Product p2 = new Product(101, "Laptop");
        Product p3 = new Product(102, "Mobile");

        // 1. toString()
        System.out.println("Product: " + p1);

        // 2. equals()
        System.out.println("p1 equals p2? " + p1.equals(p2)); // true
        System.out.println("p1 equals p3? " + p1.equals(p3)); // false

        // 3. hashCode()
        System.out.println("Same HashCode? " + (p1.hashCode() == p2.hashCode())); // true
    }
}
