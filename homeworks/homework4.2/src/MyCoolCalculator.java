public class MyCoolCalculator implements BaseMegaCalculator {
    private final double coef1;
    private final double coef2;
    private final double coef3;

    private static final double VAL1 = 12.0;
    private static final double VAL2 = 3.0;
    private static final double VAL3 = 0.05;

    public MyCoolCalculator(double in_coef1, double in_coef2, double in_coef3) {
        this.coef1 = in_coef1;
        this.coef2 = in_coef2;
        this.coef3 = in_coef3;
    }

    @Override
    public double getPrice() {
        return coef1 * VAL1 + coef2 * VAL2 - coef3 * VAL3;
    }

    @Override
    public double getMinimalValue() {
        return Math.min(coef1 * VAL1, coef2 * VAL2);
    }

    @Override
    public String getReport() {
        return String.format("Some1 %s, another2 %.3f, and3 %.2f", coef1, coef2, coef3 * VAL2);
    }
}
