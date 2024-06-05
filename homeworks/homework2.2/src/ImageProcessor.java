import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ImageProcessor {

    public static boolean isValid(Color a, Color b) {
        return a.equals(b);
    }

    public static List<List<Color>> readImage(String dir, String filename) throws IOException {
        File file = new File(dir + filename);
        if (!file.exists()) {
            System.out.println("Error opening file " + filename);
            System.exit(1);
        }

        List<List<Color>> image = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(file));
        String line;
        int rCount = 0;

        while ((line = br.readLine()) != null) {
            List<Color> row = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(line, " ");
            int pCount = 0;

            while (st.hasMoreTokens()) {
                String[] pixel = st.nextToken().split(",");
                if (pixel.length != 3) {
                    System.out.println("Invalid pixel in line " + rCount);
                    System.exit(1);
                }
                int r = Integer.parseInt(pixel[0]);
                int g = Integer.parseInt(pixel[1]);
                int b = Integer.parseInt(pixel[2]);
                if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                    System.out.println("Invalid pixel in line " + rCount);
                    System.exit(1);
                }
                row.add(new Color(r, g, b));
                pCount++;
            }
            if (pCount != 16) {
                System.out.println("Invalid amount of pixels in line " + rCount);
                System.exit(1);
            }
            image.add(row);
            rCount++;
        }
        if (rCount != 16) {
            System.out.println("Invalid amount of lines in file");
            System.exit(1);
        }
        return image;
    }

    public static void writeImage(String dir, String filename, List<List<Color>> image) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(dir + filename));

        for (List<Color> row : image) {
            for (int j = 0; j < row.size(); j++) {
                Color color = row.get(j);
                bw.write(color.r + "," + color.g + "," + color.b);
                if (j != row.size() - 1) {
                    bw.write(" ");
                }
            }
            bw.newLine();
        }
        bw.close();
    }
}
