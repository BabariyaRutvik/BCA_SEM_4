package Exam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/*
  33. Write a Java program to count the number of words, characters, and lines in a file.
 */
public class FileCount_33 {
    static void main(String[] args) {
        String fileName = "sample.txt";

        int characters = 0;
        int words = 0;
        int lines = 0;

        try {
            System.out.println("File Contents:");

            try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
                String line;

                while ((line = reader.readLine()) != null) {
                    System.out.println(line);
                    lines++;
                    characters += line.length();

                    String trimmedLine = line.trim();
                    if (!trimmedLine.isEmpty()) {
                        words += trimmedLine.split("\\s+").length;
                    }
                }
            }

            System.out.println();
            System.out.println("Number of Lines: " + lines);
            System.out.println("Number of Words: " + words);
            System.out.println("Number of Characters: " + characters);
        }catch (IOException e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}
