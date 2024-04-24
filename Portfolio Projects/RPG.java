import java.security.SecureRandom;
import java.util.Scanner;

public class SecurePasswordGenerator {
    private static final String LOWERCASE_CHARACTERS = "abcdefghijklmnopqrstuvwxyz";
    private static final String UPPERCASE_CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String NUMBERS = "0123456789";
    private static final String SPECIAL_CHARACTERS = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the Secure Password Generator!");
        int length = promptPasswordLength(scanner);
        String characterSet = promptCharacterSet(scanner);
        String password = generatePassword(length, characterSet);

        System.out.println("Generated password: " + password);
    }

    private static int promptPasswordLength(Scanner scanner) {
        System.out.print("Enter the length of the password: ");
        return scanner.nextInt();
    }

    private static String promptCharacterSet(Scanner scanner) {
        System.out.println("Select character set options:");
        System.out.println("1. Lowercase characters");
        System.out.println("2. Uppercase characters");
        System.out.println("3. Numbers");
        System.out.println("4. Special characters");
        System.out.println("5. All characters (default)");

        int choice = scanner.nextInt();

        switch (choice) {
            case 1:
                return LOWERCASE_CHARACTERS;
            case 2:
                return UPPERCASE_CHARACTERS;
            case 3:
                return NUMBERS;
            case 4:
                return SPECIAL_CHARACTERS;
            default:
                return LOWERCASE_CHARACTERS + UPPERCASE_CHARACTERS + NUMBERS + SPECIAL_CHARACTERS;
        }
    }

    private static String generatePassword(int length, String characterSet) {
        SecureRandom random = new SecureRandom();
        StringBuilder password = new StringBuilder();

        for (int i = 0; i < length; i++) {
            int randomIndex = random.nextInt(characterSet.length());
            password.append(characterSet.charAt(randomIndex));
        }

        return password.toString();
    }
}
