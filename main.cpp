#include <iostream>
#include "FunctionTimer.h"

using namespace std;

FunctionStats STAT("u");

void func() {
    int x = 0;
    for (int i = 0; i < 1000000; ++i) {
        x += 1;
    }
}

int main() {
    FunctionTimer timer(1000000);
    cout << "Program starts" << endl;

    for (int i = 0; i < 10; ++i) {
        timer.start_timer();
        func();
        timer.calculate_time();
        STAT.update_time(timer.get_elapsed_time());
    }
    STAT.print_stats();

    return 0;
}
