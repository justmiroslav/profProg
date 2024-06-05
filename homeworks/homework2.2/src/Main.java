import java.io.IOException;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        String dir = "C:/Users/miros/IdeaProjects/profProg/homeworks/homework2.2/data/";
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

        List<List<Color>> image = ImageProcessor.readImage(dir, inputFilename);

        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image.get(i).size(); j++) {
                Color currentColor = image.get(i).get(j);
                if (ImageProcessor.isValid(currentColor, unfavoriteColor)) {
                    image.get(i).set(j, favoriteColor);
                }
                if (ImageProcessor.isValid(currentColor, favoriteColor)) {
                    if (i > 0) image.get(i - 1).set(j, favoriteColor);
                    if (j > 0) image.get(i).set(j - 1, favoriteColor);
                }
            }
        }

        ImageProcessor.writeImage(dir, outputFilename, image);
        System.out.println("Favorite color has been successfully expanded");
    }
}
