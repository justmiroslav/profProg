package org.example;

import java.util.ArrayList;
import java.util.List;

public class MegaDataPool {
    private final List<MegaData> dataPool = new ArrayList<>();
    private final List<Boolean> isDataUsed = new ArrayList<>();

    public MegaDataPool(int size) {
        for (int i = 0; i < size; i++) {
            dataPool.add(new MegaData());
            isDataUsed.add(false);
        }
    }

    public MegaData acquire() {
        for (int i = 0; i < isDataUsed.size(); i++) {
            if (!isDataUsed.get(i)) {
                isDataUsed.set(i, true);
                return dataPool.get(i);
            }
        }
        return null;
    }

    public void release(MegaData obj) {
        int index = dataPool.indexOf(obj);
        if (index != -1 && isDataUsed.get(index)) {
            isDataUsed.set(index, false);
            obj.reset();
        }
    }

    public int getSize() {
        return dataPool.size();
    }

    public int getUsedCount() {
        return (int) isDataUsed.stream().filter(b -> b).count();
    }
}
