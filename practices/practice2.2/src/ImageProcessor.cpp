#include "../include/ColorsMap.hpp"
#include "../include/ImageProcessor.hpp"
#include <fstream>
#include <print>
#include <sstream>
#include <algorithm>

bool Color::isValid() const {
    return r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255;
}

bool operator==(const Color& a, const Color& b) {
    return a.r == b.r && a.g == b.g && a.b == b.b;
}

ImageProcessor::ImageProcessor(const std::string& inputFilename, const std::string& outputFilename, const std::string& colorName)
        : inputFilename(inputFilename), outputFilename(outputFilename), colorName(colorName) {
    readImage();
}

void ImageProcessor::readImage() {
    std::ifstream fileStream(inputFilename);

    if (!fileStream.is_open()) {
        std::println("Error opening file {}", inputFilename);
        exit(1);
    }

    image.reserve(NUM_ROWS_OR_NUM_PIXELS_PER_ROW);
    std::string line;
    int r_count = 0;

    while (std::getline(fileStream, line)) {
        std::vector<Color> row;
        row.reserve(NUM_ROWS_OR_NUM_PIXELS_PER_ROW);
        std::stringstream ss(line);
        std::string pixel;
        int p_count = 0;

        while (std::getline(ss, pixel, ' ')) {
            std::stringstream ps(pixel);
            Color p{};
            char comma;

            if (!(ps >> p.r >> comma >> p.g >> comma >> p.b) || !p.isValid()) {
                std::println("Invalid pixel in line {}", r_count);
                exit(1);
            }

            row.push_back(p);
            p_count++;
        }
        if (p_count != NUM_ROWS_OR_NUM_PIXELS_PER_ROW) {
            std::println("Invalid amount of pixels in line {}", r_count);
            exit(1);
        }
        image.push_back(row);
        r_count++;
    }

    if (r_count != NUM_ROWS_OR_NUM_PIXELS_PER_ROW) {
        std::println("Invalid amount of lines in file");
        exit(1);
    }

    fileStream.close();
}

void ImageProcessor::processImage() {
    Color favoriteColor = reinterpret_cast<Color &&>(colorsRgb[colorName]);

    for (size_t row = 0; row < image.size(); ++row) {
        for (size_t col = 0; col < image[row].size(); ++col) {
            if (image[row][col] == favoriteColor) {
                if (row > 0) image[row - 1][col] = favoriteColor;
                if (col > 0) image[row][col - 1] = favoriteColor;
            }
        }
    }
}

void ImageProcessor::writeImage() {
    std::ofstream file(outputFilename);

    for (const auto & row : image) {
        std::ranges::for_each(row, [&file](const Color& pixel) {
            file << pixel.r << "," << pixel.g << "," << pixel.b << " ";
        });
        file << std::endl;
    }

    file.close();
}