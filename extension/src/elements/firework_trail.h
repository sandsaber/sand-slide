#ifndef FIREWORK_TRAIL_H
#define FIREWORK_TRAIL_H

#include "element.h"

class FireworkTrail: public Element {
public:
    const double POWDER = 1 / 1.5;
    const double DECAY = 1.0 / 24;
    const double FLAME = 1.0 / 4;

    void process(SandSimulation *sim, int row, int col) override {
        if (sim->randf() >= POWDER) {
            return;
        }

        if (sim->randf() < DECAY) {
            sim->set_cell(row, col, sim->randf() < FLAME ? 5 : 0);
            return;
        }

        sim->move_and_swap(row, col, row + 1, col);
    }

    double get_density() override {
        return 4.0;
    }

    double get_explode_resistance() override {
        return 0.4;
    }

    double get_acid_resistance() override {
        return 0.2;
    }
};

#endif // FIREWORK_TRAIL_H