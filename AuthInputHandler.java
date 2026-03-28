import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class AuthInputHandler {

    public static void copyInput(char[] dest, String src) {
        // unsafe copy without bounds check
        for (int i = 0; i < src.length(); i++) {
            dest[i] = src.charAt(i);
        }
    }

    public static void logMessage(String msg) {
        System.out.printf(msg);   // unsafe format usage
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        char[] smallBuffer = new char[10];

        System.out.print("Enter username: ");
        String username = scanner.nextLine();

        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        copyInput(smallBuffer, username);   // possible out-of-bounds write

        if (password.equals("admin123")) {
            System.out.println("Login successful");
        } else {
            System.out.println("Login failed");
        }

        logMessage(username);   // dangerous logging

        try {
            Runtime.getRuntime().exec("echo " + username);   // command injection risk
        } catch (Exception e) {
            e.printStackTrace();
        }

        scanner.close();
    }
}
