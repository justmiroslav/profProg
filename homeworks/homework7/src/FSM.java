import java.util.HashMap;
import java.util.Map;

enum Song {
    INTRO("Intro"),
    STARMAN("Starman"),
    SHOW_MUST_GO_ON("Show must go on"),
    LET_IT_BE("Let it be"),
    BUT_IN_THE_END("But in the end, it doesn't even matter");

    private final String song;

    Song(String song) {
        this.song = song;
    }

    public String getSong() {
        return song;
    }
}

enum Command {
    SAD,
    FUN,
    SILLY,
    DANGEROUS
}

public class FSM {
    private static final Map<Song, Map<Command, Song>> transitions = new HashMap<>();

    public FSM() {
        transitions.put(Song.INTRO, Map.of(
                Command.DANGEROUS, Song.LET_IT_BE,
                Command.FUN, Song.STARMAN,
                Command.SAD, Song.BUT_IN_THE_END
        ));

        transitions.put(Song.STARMAN, Map.of(
                Command.SILLY, Song.INTRO,
                Command.DANGEROUS, Song.SHOW_MUST_GO_ON,
                Command.FUN, Song.BUT_IN_THE_END
        ));

        transitions.put(Song.SHOW_MUST_GO_ON, Map.of(
                Command.SAD, Song.LET_IT_BE,
                Command.FUN, Song.STARMAN
        ));

        transitions.put(Song.LET_IT_BE, Map.of(
                Command.DANGEROUS, Song.INTRO,
                Command.SILLY, Song.SHOW_MUST_GO_ON
        ));
    }

    public Song nextSong(Song currentSong, Command command) {
        return transitions.get(currentSong).getOrDefault(command, currentSong);
    }
}
