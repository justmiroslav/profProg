#include "ImageProcessor.hpp"
#include <fstream>
#include <sstream>
#include <ranges>

bool Color::isValid() const {
    return r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255;
}

bool operator==(const Color& a, const Color& b) {
    return a.r == b.r && a.g == b.g && a.b == b.b;
}

ImageProcessor::ImageProcessor(const std::string& inputFilename) : inputFilename(inputFilename) {
    readImage();
}

void ImageProcessor::readImage() {
    std::ifstream fileStream(inputFilename);

    if (!fileStream.is_open()) {
        throw std::runtime_error("Error opening file " + inputFilename);
    }

    image.reserve(NUM_ROWS_OR_NUM_PIXELS_PER_ROW);
    std::string line;
    int r_count = 0;

    while (std::getline(fileStream, line)) {
        image.emplace_back();
        auto& row = image.back();
        row.reserve(NUM_ROWS_OR_NUM_PIXELS_PER_ROW);

        std::stringstream ss(line);
        std::string pixel;
        int p_count = 0;

        while (std::getline(ss, pixel, ' ')) {
            std::stringstream ps(pixel);
            Color p{};
            char comma;

            if (!(ps >> p.r >> comma >> p.g >> comma >> p.b) || !p.isValid()) {
                throw std::runtime_error("Invalid pixel in line " + std::to_string(r_count));
            }

            row.push_back(p);
            p_count++;
        }
        if (p_count != NUM_ROWS_OR_NUM_PIXELS_PER_ROW) {
            throw std::runtime_error("Invalid amount of pixels in line " + std::to_string(r_count));
        }

        r_count++;
    }

    if (r_count != NUM_ROWS_OR_NUM_PIXELS_PER_ROW) {
        throw std::runtime_error("Invalid amount of lines in file");
    }

    fileStream.close();
}

void ImageProcessor::processImage(const Color& favoriteColor) {
    for (size_t row = 0; row < image.size(); ++row) {
        for (size_t col = 0; col < image[row].size(); ++col) {
            if (image[row][col] == favoriteColor) {
                if (row > 0) image[row - 1][col] = favoriteColor;
                if (col > 0) image[row][col - 1] = favoriteColor;
            }
        }
    }
}

void ImageProcessor::writeImage(const std::string& outputFilename) {
    std::ofstream file(outputFilename);

    for (const auto & row : image) {
        auto row_string = row | std::views::transform([](const Color& pixel) {
            return std::format("{},{},{}", pixel.r, pixel.g, pixel.b);
        }) | std::views::join_with(' ');

        file << std::ranges::to<std::string>(row_string) << std::endl;
    }
    file.close();
}
