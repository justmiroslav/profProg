package org.example;

public class Main {
    public static void main(String[] args) {
        MegaDataPool pool = new MegaDataPool(5);

        try {
            MegaData obj1 = pool.acquire();
            MegaData obj2 = pool.acquire();

            System.out.println("Acquired obj1 and obj2");

            double[] bigArray = obj1.getBigArray();
            bigArray[0] = 2.71;

            float[] smallArray = obj2.getSmallArray();
            smallArray[1] = 3.14f;

            System.out.println("obj1 bigArray first element: " + bigArray[0]);
            System.out.println("obj2 smallArray second element: " + smallArray[1]);
            System.out.println("Pool size: " + pool.getSize() + ", Used size: " + pool.getUsedCount());

            pool.release(obj1);
            pool.release(obj2);

            System.out.println("Released obj1 and obj2");
            System.out.println("Pool size: " + pool.getSize() + ", Used size: " + pool.getUsedCount());
        } catch (Exception e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}
