package com.pizza;

public enum Command {
    ADD(1),
    REMOVE(2),
    DONE(3);

    private final int value;

    Command(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public static Command fromInt(int value) {
        for (Command command : Command.values()) {
            if (command.getValue() == value) {
                return command;
            }
        }
        return null;
    }
}