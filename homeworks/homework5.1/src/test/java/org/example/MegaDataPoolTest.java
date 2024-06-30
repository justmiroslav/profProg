package org.example;

import static org.junit.Assert.*;
import org.junit.Test;

public class MegaDataPoolTest {
    @Test
    public void PoolConstructorTest() {
        MegaDataPool pool = new MegaDataPool(5);
        assertEquals(0, pool.getUsedCount());
    }

    @Test
    public void PoolAcquireTest() {
        MegaDataPool pool = new MegaDataPool(5);
        MegaData obj1 = pool.acquire();
        assertNotNull(obj1);
        assertEquals(1, pool.getUsedCount());
    }

    @Test
    public void PoolReleaseTest() {
        MegaDataPool pool = new MegaDataPool(5);
        MegaData obj1 = pool.acquire();
        pool.release(obj1);
        assertEquals(0, pool.getUsedCount());
    }

    @Test
    public void PoolAcquireNullTest() {
        MegaDataPool pool = new MegaDataPool(1);
        pool.acquire();
        assertNull(pool.acquire());
    }
}