#include "include/ColorsMap.hpp"
#include "include/ImageProcessor.hpp"
#include <print>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::println("Usage: ./program.exe <input_filename> <output_filename> <color_name>");
        return 1;
    }

    std::string colorName = argv[3];
    if (colorsRgb.find(colorName) == colorsRgb.end()) {
        std::println("Color not found");
        return 1;
    }

    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];

    ImageProcessor imageProcessor(inputFilename, outputFilename, colorName);
    imageProcessor.processImage();
    imageProcessor.writeImage();
    std::println("Favorite color has been successfully expanded");
    return 0;
}
