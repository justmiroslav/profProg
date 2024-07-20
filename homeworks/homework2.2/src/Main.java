import java.io.IOException;
import java.util.Map;

public class Main {
    private static final String dir = "C:/Users/miros/IdeaProjects/profProg/homeworks/homework2.2/data/";

    public static void main(String[] args) throws IOException {
        if (args.length < 3 || args.length > 4) {
            System.out.println("Usage: java Main <input_filename> <output_filename> <favorite_color> [<unfavorite_color>]");
            System.exit(1);
        }

        String inputFilename = args[0];
        String outputFilename = args[1];
        String favoriteColorName = args[2];
        String unfavoriteColorName = args.length == 4 ? args[3] : null;

        Map<String, Color> colorsRgb = ColorsMap.colorsRgb;

        if (!colorsRgb.containsKey(favoriteColorName)) {
            System.out.println("Color not found");
            System.exit(1);
        }

        Color favoriteColor = colorsRgb.get(favoriteColorName);
        Color unfavoriteColor = unfavoriteColorName != null ? colorsRgb.get(unfavoriteColorName) : null;

        if (unfavoriteColorName != null && unfavoriteColor == null) {
            System.out.println("Unfavorite color not found");
            System.exit(1);
        }

        try {
            ImageProcessor imageProcessor = new ImageProcessor(inputFilename, dir);
            imageProcessor.processImage(favoriteColor, unfavoriteColor);
            imageProcessor.writeImage(outputFilename);
            System.out.println("Favorite color has been successfully expanded" + (unfavoriteColor != null ? " and unfavorite color has been successfully replaced" : ""));
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
            System.exit(1);
        }
    }
}
