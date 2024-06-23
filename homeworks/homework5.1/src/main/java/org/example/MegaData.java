package org.example;

import java.util.Arrays;

public class MegaData {
    public static final int DATA_COUNT = 1024;
    private final float[] smallArray = new float[DATA_COUNT];
    private final double[] bigArray = new double[DATA_COUNT * DATA_COUNT];

    public MegaData() {
        reset();
    }

    public void reset() {
        Arrays.fill(smallArray, 42.0f);
        Arrays.fill(bigArray, 42.0);
    }

    public float[] getSmallArray() {
        return smallArray;
    }

    public double[] getBigArray() {
        return bigArray;
    }
}
