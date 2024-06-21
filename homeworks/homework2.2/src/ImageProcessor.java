import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ImageProcessor {
    private static final int NUM_ROWS_OR_NUM_PIXELS_PER_ROW = 16;
    private final String inputFilename;
    private final String dir;
    private final List<List<Color>> image;

    public ImageProcessor(String inputFilename, String dir) {
        this.inputFilename = inputFilename;
        this.dir = dir;
        this.image = new ArrayList<>();
        readImage();
    }

    private void readImage() {
        try (Scanner scanner = new Scanner(new File(dir + inputFilename))) {
            int r_count = 0;
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] pixels = line.split(" ");
                if (pixels.length != NUM_ROWS_OR_NUM_PIXELS_PER_ROW) {
                    throw new RuntimeException("Invalid amount of pixels in line " + r_count);
                }

                List<Color> row = getColors(pixels, r_count);
                image.add(row);
                r_count++;
            }
            if (r_count != NUM_ROWS_OR_NUM_PIXELS_PER_ROW) {
                throw new RuntimeException("Invalid amount of lines in file");
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException("Error opening file " + inputFilename);
        }
    }

    private static List<Color> getColors(String[] pixels, int r_count) {
        List<Color> row = new ArrayList<>();
        for (String pixel : pixels) {
            String[] rgb = pixel.split(",");
            if (rgb.length != 3) {
                throw new RuntimeException("Invalid pixel in line " + r_count);
            }
            try {
                Color color = new Color(Integer.parseInt(rgb[0]), Integer.parseInt(rgb[1]), Integer.parseInt(rgb[2]));
                if (!color.isValid()) {
                    throw new RuntimeException("Invalid pixel in line " + r_count);
                }
                row.add(color);
            } catch (NumberFormatException e) {
                throw new RuntimeException("Invalid pixel in line " + r_count);
            }
        }
        return row;
    }

    public void processImage(Color favoriteColor, Color unfavoriteColor) {
        for (int row = 0; row < image.size(); row++) {
            for (int col = 0; col < image.get(row).size(); col++) {
                Color currentColor = image.get(row).get(col);
                if (currentColor.equals(favoriteColor)) {
                    if (row > 0) image.get(row - 1).set(col, favoriteColor);
                    if (col > 0) image.get(row).set(col - 1, favoriteColor);
                } else if (unfavoriteColor != null && currentColor.equals(unfavoriteColor)) {
                    image.get(row).set(col, favoriteColor);
                }
            }
        }
    }

    public void writeImage(String outputFilename) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(dir + outputFilename));
        
        for (List<Color> row : image) {
            List<String> colorStrings = new ArrayList<>();
            for (Color color : row) {
                colorStrings.add(color.r + "," + color.g + "," + color.b);
            }
            bw.write(String.join(" ", colorStrings));
            bw.newLine();
        }
        
        bw.close();
    }
}
