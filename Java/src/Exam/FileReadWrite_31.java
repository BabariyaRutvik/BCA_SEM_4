package Exam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/*
 31. Write a Java program to read and write text files using FileReader and FileWriter.
 */
public class FileReadWrite_31 {
    static void main(String[] args) {
        // writing to the file

        String fileName = "sample.txt";
        try {
            FileWriter writer = new FileWriter(fileName);

            writer.write("Hello This is java File read and write Program");
            writer.write("\n This text written using FileWriter.");

            writer.close();

            System.out.println("Data Written Successfully");
        }catch (IOException e){
            System.out.println("Error while writing file: " + e.getMessage());
        }
        // reading from the file
        try {
            FileReader fileReader = new FileReader(fileName);

            int character;

            System.out.println("\n File Contents:");

            while ((character = fileReader.read()) != -1){
                System.out.print((char) character);
            }
            fileReader.close();
        }catch (IOException e){
            System.out.println("Error while reading file: " + e.getMessage());
        }
    }
}
