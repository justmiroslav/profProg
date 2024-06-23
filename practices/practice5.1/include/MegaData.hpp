#pragma once

class MegaData {
public:
    MegaData();
    void reset();
    double* getBigArray();
    float* getSmallArray();

private:
    static constexpr auto DATA_COUNT = 1024;
    float smallArray[DATA_COUNT];
    double bigArray[DATA_COUNT * DATA_COUNT];
};
