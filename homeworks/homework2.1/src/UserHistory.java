import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class UserHistory {
    private static final String filename = "data/history.txt";
    private static Map<String, Integer> userCount = new HashMap<>();

    public static void loadHistory() throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                if (parts.length == 2) {
                    userCount.put(parts[0], Integer.parseInt(parts[1]));
                }
            }
        }
    }

    public static void saveHistory() throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Map.Entry<String, Integer> entry : userCount.entrySet()) {
                writer.write(entry.getKey() + " " + entry.getValue());
                writer.newLine();
            }
        }
    }

    public static void resetUser(String name) throws IOException {
        userCount.remove(name);
        saveHistory();
    }

    public static void resetAllUsers() throws IOException {
        userCount.clear();
        saveHistory();
    }

    public static void greetUser(String name) throws IOException {
        if (!userCount.containsKey(name)) {
            System.out.println("Welcome, " + name + "!");
        } else {
            System.out.println("Hello again(x" + userCount.get(name) + "), " + name);
        }
        userCount.put(name, userCount.getOrDefault(name, 0) + 1);
        saveHistory();
    }
}
