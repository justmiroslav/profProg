import java.util.Map;
import java.util.function.Consumer;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.*;

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
    private final BlockingQueue<Runnable> messageQueue = new LinkedBlockingQueue<>();
    private final ExecutorService dispatchThread = Executors.newSingleThreadExecutor();
    private volatile boolean running = true;

    public MessageDispatcher() {
        dispatchThread.submit(this::dispatchMessages);
    }

    public void shutdown() {
        running = false;
        dispatchThread.shutdownNow();
    }

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
        messageQueue.add(() -> dispatch(message));
    }

    private <T> void dispatch(T message) {
        Map<Integer, Consumer<?>> subscriberMap = subscribers.get(message.getClass());
        subscriberMap.values().forEach(subscriber -> ((Consumer<T>) subscriber).accept(message));
    }

    private void dispatchMessages() {
        while (running) {
            try {
                messageQueue.take().run();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
