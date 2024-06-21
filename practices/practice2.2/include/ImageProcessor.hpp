#pragma once
#include <string>
#include <vector>

struct Color {
    int r, g, b;

    [[nodiscard]] bool isValid() const;
};

class ImageProcessor {
public:
    explicit ImageProcessor(const std::string& inputFilename);
    void processImage(const Color& favoriteColor);
    void writeImage(const std::string& outputFilename);

private:
    constexpr static int NUM_ROWS_OR_NUM_PIXELS_PER_ROW = 16;
    const std::string& inputFilename;
    std::vector<std::vector<Color>> image;
    void readImage();
};
