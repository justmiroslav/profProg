package org.example;

import static org.junit.Assert.*;
import org.junit.Test;

public class TriangleTest {
    @Test
    public void testCalculateAreaValidTriangle() {
        Triangle triangle = new Triangle(3.0, 4.0, 5.0);
        double area = triangle.calculateArea();
        assertEquals(6.0, area, 0.0001);
    }

    @Test
    public void testCalculateAreaInvalidTriangle() {
        Triangle triangle = new Triangle(4.0, 0.0, -6.0);
        double area = triangle.calculateArea();
        assertEquals(0.0, area, 0.0001);
    }

    @Test
    public void testGetHeightForSide() {
        Triangle triangle = new Triangle(3.0, 4.0, 5.0);
        double height = triangle.getHeight("a");
        assertEquals(4.0, height, 0.0001);
    }
}
