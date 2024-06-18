#pragma once
#include <string>
#include <vector>

struct Color {
    int r, g, b;

    [[nodiscard]] bool isValid() const;
};

class ImageProcessor {
public:
    ImageProcessor(const std::string& inputFilename, const std::string& outputFilename, const std::string& colorName);
    void processImage();
    void writeImage();
private:
    constexpr static int NUM_ROWS_OR_NUM_PIXELS_PER_ROW = 16;
    const std::string& inputFilename;
    const std::string& outputFilename;
    const std::string& colorName;
    std::vector<std::vector<Color>> image;

    void readImage();
};