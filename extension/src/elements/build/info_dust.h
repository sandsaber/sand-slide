#ifndef INFO_DUST_H
#define INFO_DUST_H

class SandSimulation;

#include "../element.h"

class InfoDust: public Element {
public:
    const double DECAY = 1 / 32.0;

    void process(SandSimulation *sim, int row, int col) override {
        if (sim->randf() < DECAY) {
            sim->set_cell(row, col, 6);
            return;
        }
    }

    double get_density() override {
        return 8.0;
    }

    double get_explode_resistance() override {
        return 0.01;
    }

    double get_acid_resistance() override {
        return 0.01;
    }
};

#endif // INFO_DUST_H