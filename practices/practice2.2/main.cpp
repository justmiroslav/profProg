#include "ImageProcessor.hpp"
#include <map>
#include <print>

std::map<std::string, std::tuple<int, int, int>> colorsRgb = {
        {"light_green", std::make_tuple(123, 234, 45)},
        {"light_blue", std::make_tuple(67, 89, 123)},
        {"red", std::make_tuple(255, 0, 0)},
        {"green", std::make_tuple(0, 255, 0)},
        {"blue", std::make_tuple(0, 0, 255)},
        {"yellow", std::make_tuple(255, 255, 0)},
        {"magenta", std::make_tuple(255, 0, 255)},
        {"cyan", std::make_tuple(0, 255, 255)},
        {"gray", std::make_tuple(128, 128, 128)},
        {"light_gray", std::make_tuple(192, 192, 192)},
        {"dark_gray", std::make_tuple(64, 64, 64)},
        {"darker_gray", std::make_tuple(32, 32, 32)},
        {"orange", std::make_tuple(255, 128, 0)},
        {"teal", std::make_tuple(0, 128, 255)},
        {"purple", std::make_tuple(128, 0, 255)},
        {"pink", std::make_tuple(255, 128, 128)},
        {"light_blue_green", std::make_tuple(100, 150, 200)},
        {"brown", std::make_tuple(200, 150, 100)},
        {"dark_gray_2", std::make_tuple(50, 50, 50)},
        {"medium_gray", std::make_tuple(150, 150, 150)},
        {"lime", std::make_tuple(100, 200, 50)},
        {"greenish", std::make_tuple(50, 200, 100)},
        {"tan", std::make_tuple(200, 100, 50)},
        {"white", std::make_tuple(255, 255, 255)},
        {"maroon", std::make_tuple(128, 0, 0)},
        {"forest_green", std::make_tuple(0, 128, 0)},
        {"navy", std::make_tuple(0, 0, 128)},
        {"light_orange", std::make_tuple(255, 128, 64)},
        {"sky_blue", std::make_tuple(64, 128, 255)},
        {"violet", std::make_tuple(128, 64, 255)},
        {"mint", std::make_tuple(64, 255, 128)},
        {"salmon", std::make_tuple(255, 64, 128)},
        {"gold", std::make_tuple(255, 255, 128)},
        {"indigo", std::make_tuple(64, 64, 128)},
        {"chocolate", std::make_tuple(128, 64, 64)},
        {"olive", std::make_tuple(64, 128, 64)},
        {"mauve", std::make_tuple(200, 100, 150)},
        {"turquoise", std::make_tuple(100, 200, 150)},
        {"lavender", std::make_tuple(150, 100, 200)},
        {"chartreuse", std::make_tuple(50, 150, 100)},
        {"plum", std::make_tuple(100, 50, 150)},
        {"fuchsia", std::make_tuple(150, 50, 100)},
        {"mustard", std::make_tuple(200, 150, 50)}
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::println("Usage: <output_file> <input_filename> <output_filename> <color_name>");
        return 1;
    }
    std::string colorName = argv[3];
    if (colorsRgb.find(colorName) == colorsRgb.end()) {
        std::println("Color not found");
        return 1;
    }

    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];
    try {
        ImageProcessor imageProcessor(inputFilename);
        Color favoriteColor = reinterpret_cast<Color &&>(colorsRgb[colorName]);

        imageProcessor.processImage(favoriteColor);
        imageProcessor.writeImage(outputFilename);
        std::println("Favorite color has been successfully expanded");
        return 0;
    } catch (const std::exception& e) {
        std::println("{}", e.what());
        return 1;
    }
}
