public class WordsPrinter implements Runnable {
    private final String word;

    public WordsPrinter(String word) {
        this.word = word;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        if (word.isEmpty()) {
            System.out.println("No input");
        } else {
            ConfigurationLoader configLoader = ConfigurationLoader.getInstance();
            String[] prePost = configLoader.getConfiguration(word.charAt(0));
            System.out.println(prePost[0] + " " + word + " " + prePost[1]);
        }
    }
}
