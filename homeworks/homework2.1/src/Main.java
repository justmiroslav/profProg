import java.io.IOException;

public class Main {
    private static final String RESET_ALL_COMMAND = "bread";
    private static final String DELETE_USER_COMMAND = "delete";

    public static void main(String[] args) {
        if (args.length < 1 || args.length > 2) {
            System.out.println("Error: Incorrect number of arguments.");
            System.exit(1);
        }

        String name = args[0];

        try {
            UserHistory.loadHistory();

            if (name.equals(RESET_ALL_COMMAND)) {
                UserHistory.resetAllUsers();
            } else if (args.length == 2 && args[1].equals(DELETE_USER_COMMAND)) {
                UserHistory.resetUser(name);
            } else {
                UserHistory.greetUser(name);
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
            System.exit(1);
        }
    }
}
