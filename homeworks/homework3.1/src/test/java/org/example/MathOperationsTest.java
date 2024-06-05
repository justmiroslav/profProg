package org.example;

import static org.junit.Assert.*;
import org.junit.Test;
import java.util.Arrays;
import java.util.List;

public class MathOperationsTest {
    private final MathOperations operations = new MathOperations();

    @Test
    public void testProductInverseExists() {
        List<Double> arguments = Arrays.asList(2.0, 3.0, 4.0);
        Object result = operations.calculate(arguments);
        assertTrue(result instanceof Double);
        assertEquals(1 / (2.0 * 3.0 * 4.0), result);
    }

    @Test
    public void testSumInverseExists() {
        List<Double> arguments = Arrays.asList(0.0, 2.0, 1.0);
        Object result = operations.calculate(arguments);
        assertTrue(result instanceof Double);
        assertEquals(1 / (0.0 + 2.0 + 1.0), result);
    }

    @Test
    public void testSumAndProductInverseDoNotExist() {
        List<Double> arguments = Arrays.asList(0.0, 4.0, -4.0);
        Object result = operations.calculate(arguments);
        assertTrue(result instanceof Double);
        assertEquals(0.0 + (4.0 + 1) * (-4.0 - 1), result);
    }

    @Test
    public void testInvalidArgumentListSize() {
        List<Double> invalidList = Arrays.asList(1.0, 2.0);
        Object result = operations.calculate(invalidList);
        assertEquals("Exactly 3 elements are required", result);
    }
}
