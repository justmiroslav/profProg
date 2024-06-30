import java.util.Random;

public class Main {
    private static void messageGenerator(MessageDispatcher dispatcher) {
        Random random = new Random();
        for (int i = 0; i < 5; i++) {
            int msgType = random.nextInt(3) + 1;
            if (msgType == 1) {
                GreenMessage msg = new GreenMessage("Green Message", random.nextInt(10));
                dispatcher.publish(msg);
            } else if (msgType == 2) {
                BlueMessage msg = new BlueMessage(random.nextDouble() * 10, random.nextDouble() * 10);
                dispatcher.publish(msg);
            } else {
                OrangeMessage msg = new OrangeMessage("Orange Msg 1", "Orange Msg 2", random.nextInt(10), random.nextDouble() * 10);
                dispatcher.publish(msg);
            }
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        MessageDispatcher dispatcher = new MessageDispatcher();

        int greenSubscriptionId = dispatcher.subscribe(GreenMessage.class, msg -> System.out.println("Green Message: " + msg.message + " " + msg.counter));

        dispatcher.subscribe(BlueMessage.class, msg -> System.out.println("Blue Message: " + msg.value1 + " " + msg.value2));
        dispatcher.subscribe(OrangeMessage.class, msg -> System.out.println("Orange Message: " + msg.message1 + " " + msg.message2 + " " + msg.counter + " " + msg.value));

        Thread t1 = new Thread(() -> messageGenerator(dispatcher));
        Thread t2 = new Thread(() -> messageGenerator(dispatcher));

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        dispatcher.unsubscribe(GreenMessage.class, greenSubscriptionId);
        System.out.println("Unsubscribed GreenMessage subscriber with ID: " + greenSubscriptionId);

        Thread t3 = new Thread(() -> messageGenerator(dispatcher));
        Thread t4 = new Thread(() -> messageGenerator(dispatcher));

        t3.start();
        t4.start();
    }
}
