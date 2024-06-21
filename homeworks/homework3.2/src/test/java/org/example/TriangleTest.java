package org.example;

import static org.junit.Assert.*;
import org.junit.Test;
import java.util.Optional;

public class TriangleTest {
    @Test
    public void testCalculateAreaValidTriangle() {
        Triangle triangle = new Triangle(3.0, 4.0, 5.0);
        double area = triangle.calculateArea();
        assertEquals(6.0, area, 0.0001);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testCalculateAreaInvalidTriangle() {
        Triangle triangle = new Triangle(1.0, 3.0, 5.0);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testCalculateAreaInvalidSides() {
        Triangle triangle = new Triangle(-3.0, -4.0, -5.0);
    }

    @Test
    public void testGetHeightValidSide() {
        Triangle triangle = new Triangle(3.0, 4.0, 5.0);
        Optional<Double> height = triangle.getHeight("a");
        assertTrue(height.isPresent());
        assertEquals(4.0, height.get(), 0.0001);
    }

    @Test
    public void testGetHeightInvalidSide() {
        Triangle triangle = new Triangle(3.0, 4.0, 5.0);
        Optional<Double> height = triangle.getHeight("d");
        assertFalse(height.isPresent());
    }
}
