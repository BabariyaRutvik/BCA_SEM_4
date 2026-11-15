package Exam;

import hotel.Room; // Import Room from hotel package

/*
  49. Hotel package: Write Java programs to create a package hotel and demonstrate the access rules 
      (public, protected, default and private) by accessing its members from another package.
*/
public class HotelPackage_49 extends Room {

    public void checkAccess() {
        // 1. PUBLIC: Accessible directly from any package
        System.out.println(publicMember);

        // 2. PROTECTED: Accessible in another package ONLY via Subclass (inheritance)
        System.out.println(protectedMember);

        // 3. DEFAULT: NOT accessible from outside package (Will give compile error)
        // System.out.println(defaultMember);

        // 4. PRIVATE: NOT accessible outside class (Will give compile error)
        // System.out.println(privateMember);
    }

    public static void main(String[] args) {
        System.out.println("===== Access Rules from Another Package =====\n");
        HotelPackage_49 test = new HotelPackage_49();
        test.checkAccess();
    }
}
