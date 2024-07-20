public class Color {
    public int r, g, b;

    public Color(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public boolean isValid() {
        return r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255;
    }

    public boolean equals(Color other) {
        return r == other.r && g == other.g && b == other.b;
    }
}
