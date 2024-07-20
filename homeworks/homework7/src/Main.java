import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        FSM fsm = new FSM();
        Song currentSong = Song.INTRO;
        Scanner scanner = new Scanner(System.in);
        System.out.println("You are listening to the song: " + currentSong.getSong());

        while (true) {
            System.out.println("Enter your mood (sad, fun, silly, dangerous): ");
            String mood = scanner.nextLine().toUpperCase();

            Command command;
            try {
                command = Command.valueOf(mood);
            } catch (IllegalArgumentException e) {
                System.out.println("You cannot be in this mood. Try again.");
                continue;
            }

            Song nextSong = fsm.nextSong(currentSong, command);

            if (nextSong == Song.BUT_IN_THE_END) {
                System.out.println("Playlist is over. Goodbye!");
                break;
            } else if (nextSong == currentSong) {
                System.out.println("Nice choice! Replaying song: " + currentSong.getSong());
            } else {
                System.out.println("Switching to the song: " + nextSong.getSong());
                currentSong = nextSong;
            }
        }

        scanner.close();
    }
}