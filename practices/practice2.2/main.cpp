#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "include/colorsMap.hpp"

bool isValid(const Color& a, const Color& b) {
    return a.r == b.r && a.g == b.g && a.b == b.b;
}

std::vector<std::vector<Color>> readImage(const std::string& dir, const std::string& filename) {
    std::ifstream file(dir + filename);

    if (!file.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
        exit(1);
    }

    std::vector<std::vector<Color>> image;
    std::string line;
    int r_count = 0;

    while (std::getline(file, line)) {
        std::vector<Color> row;
        std::stringstream ss(line);
        std::string pixel;
        int p_count = 0;

        while (std::getline(ss, pixel, ' ')) {
            std::stringstream ps(pixel);
            Color p{};
            char comma;

            if (!(ps >> p.r >> comma >> p.g >> comma >> p.b) || comma != ',' || p.r < 0 || p.r > 255 || p.g < 0 || p.g > 255 || p.b < 0 || p.b > 255) {
                std::cout << "Invalid pixel in line " << r_count << std::endl;
                exit(1);
            }
            row.push_back(p);
            p_count++;
        }
        if (p_count != 16) {
            std::cout << "Invalid amount of pixels in line " << r_count << std::endl;
            exit(1);
        }
        image.push_back(row);
        r_count++;
    }
    if (r_count != 16) {
        std::cout << "Invalid amount of lines in file" << std::endl;
        exit(1);
    }
    return image;
}

void writeImage(const std::string& dir, const std::string& filename, const std::vector<std::vector<Color>>& image) {
    std::ofstream file(dir + filename);

    for (const auto & i : image) {
        for (size_t j = 0; j < i.size(); ++j) {
            file << i[j].r << "," << i[j].g << "," << i[j].b;
            if (j != i.size() - 1) {
                file << " ";
            }
        }
        file << "\n";
    }
}

int main(int argc, char* argv[]) {
    std::string const dir = "C:/Users/miros/CLionProjects/profProg/practices/practice2.2/data/";
    if (argc != 4) {
        std::cout << "Usage: ./program.exe <input_filename> <output_filename> <color_name>" << std::endl;
        return 1;
    }
    std::string inputFilename = argv[1];
    std::string outputFilename = argv[2];
    std::string colorName = argv[3];

    if (colorsRgb.find(colorName) == colorsRgb.end()) {
        std::cout << "Color not found" << std::endl;
        return 1;
    }

    Color color = {std::get<0>(colorsRgb[colorName]), std::get<1>(colorsRgb[colorName]), std::get<2>(colorsRgb[colorName])};
    auto image = readImage(dir, inputFilename);

    for (size_t i = 0; i < image.size(); ++i) {
        for (size_t j = 0; j < image[i].size(); ++j) {
            if (isValid(image[i][j], color)) {
                if (i > 0) image[i-1][j] = color;
                if (j > 0) image[i][j-1] = color;
            }
        }
    }

    writeImage(dir, outputFilename, image);
    std::cout << "Favorite color has been successfully expanded" << std::endl;
    return 0;
}
