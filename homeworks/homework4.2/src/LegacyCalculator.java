public class LegacyCalculator {
    private final double megaDelta;
    private final double megaMultiplier;

    private static final double STRANGE_VAL1 = 6.0;
    private static final double STRANGE_VAL2 = 13.0;

    public LegacyCalculator(double in_megaDelta, double in_megaMultiplier) {
        this.megaDelta = in_megaDelta;
        this.megaMultiplier = in_megaMultiplier;
    }

    public double calculatePricePart1() {
        return STRANGE_VAL1 - megaDelta;
    }

    public double calculatePricePart2() {
        return STRANGE_VAL2 * megaMultiplier + 1 - megaDelta;
    }

    public double getOurTheMostAndMinimalValue() {
        return megaDelta * megaMultiplier;
    }

    public String getSomeDocumentRepresentation() {
        return String.format("The man %s who sold the %s world",
                STRANGE_VAL1 - megaDelta,
                megaMultiplier * STRANGE_VAL2);
    }
}
