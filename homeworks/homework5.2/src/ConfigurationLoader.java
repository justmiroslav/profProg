import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;

public class ConfigurationLoader {
    private static final String CONFIG_FILE = "data/config.txt";
    private static ConfigurationLoader instance;
    private final HashMap<Character, String[]> configMap = new HashMap<>();

    private ConfigurationLoader() {
        loadConfiguration();
    }

    private void loadConfiguration() {
        try {
            BufferedReader br = new BufferedReader(new FileReader(CONFIG_FILE));
            br.lines().forEach(line -> {
                String[] parts = line.split(" ");
                for (char c = parts[0].charAt(0); c <= parts[0].charAt(2); c++) {
                    configMap.put(c, new String[]{parts[1], parts[2]});
                }
            });
        } catch (Exception e) {
            System.err.println("Failed to load configuration: " + e.getMessage());
        }
    }

    public static ConfigurationLoader getInstance() {
        if (instance == null) {
            instance = new ConfigurationLoader();
        }
        return instance;
    }

    public String[] getConfiguration(char c) {
        return configMap.getOrDefault(c, new String[]{"default_first", "default_second"});
    }
}
