package Exam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/*
  32. Develop a Java program to copy the contents of one file into another.
 */
public class FileCopy_32 {
    static void main(String[] args) {

        String sourceFile = "source.txt";
        String destinationFile = "destination.txt";

        try {
            FileReader reader = new FileReader(sourceFile);

            FileWriter writer = new FileWriter(destinationFile);

            int character;

            while ((character = reader.read()) != -1) {
                writer.write(character);
            }

            reader.close();
            writer.close();

            System.out.println("File Content Copied Successfully!");
        }catch (IOException e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}
