#pragma once
#include "ModernCalculators.hpp"
#include "LegacyCalculator.hpp"

class MegaAdapter : public BaseMegaCalculator {
public:
    explicit MegaAdapter(std::unique_ptr<LegacyCalculator> legacyCalculator)
            : legacyCalculator_(std::move(legacyCalculator)) {}

    [[nodiscard]] double getPrice() const override {
        return legacyCalculator_->calculatePricePart1() + legacyCalculator_->calculatePricePart2();
    }

    [[nodiscard]] double getMinimalValue() const override {
        return legacyCalculator_->getOurTheMostAndMinimalValue();
    }

    [[nodiscard]] std::string getReport() const override {
        return legacyCalculator_->getSomeDocumentRepresentation();
    }

private:
    std::unique_ptr<LegacyCalculator> legacyCalculator_;
};
