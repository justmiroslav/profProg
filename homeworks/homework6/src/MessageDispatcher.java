import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.function.Consumer;
import java.util.concurrent.atomic.AtomicInteger;

class GreenMessage {
    String message;
    int counter;

    public GreenMessage(String message, int counter) {
        this.message = message;
        this.counter = counter;
    }
}

class BlueMessage {
    double value1;
    double value2;

    public BlueMessage(double value1, double value2) {
        this.value1 = value1;
        this.value2 = value2;
    }
}

class OrangeMessage {
    String message1;
    String message2;
    int counter;
    double value;

    public OrangeMessage(String message1, String message2, int counter, double value) {
        this.message1 = message1;
        this.message2 = message2;
        this.counter = counter;
        this.value = value;
    }
}

public class MessageDispatcher {
    private final Map<Class<?>, Map<Integer, Consumer<?>>> subscribers = new ConcurrentHashMap<>();
    private final AtomicInteger idGenerator = new AtomicInteger(0);

    public <T> int subscribe(Class<T> messageType, Consumer<T> callback) {
        int id = idGenerator.incrementAndGet();
        subscribers.computeIfAbsent(messageType, _ -> new ConcurrentHashMap<>()).put(id, callback);
        return id;
    }

    public <T> void unsubscribe(Class<T> messageType, int subscriptionId) {
        Map<Integer, Consumer<?>> subscriberMap = subscribers.get(messageType);
        subscriberMap.remove(subscriptionId);
    }

    public <T> void publish(T message) {
        Map<Integer, Consumer<?>> subscriberMap = subscribers.get(message.getClass());
        subscriberMap.values().forEach(subscriber -> ((Consumer<T>) subscriber).accept(message));
    }
}
