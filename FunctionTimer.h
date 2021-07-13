#ifndef FUNCTIONTIMER_H
#define FUNCTIONTIMER_H

#include <iostream>
#include <limits>
#include <sys/time.h>

class FunctionStats {
private:
    int64_t longest_time = 0;   // the longest function running time
    int64_t shortest_time = std::numeric_limits<int>::max();    // the shortest function running time
    int64_t total_time = 0;
    int64_t count = 0;          // number of times the function being called
    std::string time_unit;

public:
    FunctionStats(std::string time_unit_): time_unit(time_unit_){}

    void update_time(int running_time) {
        ++count;
        total_time += running_time;
        
        if (running_time > longest_time) longest_time = running_time;
        if (running_time < shortest_time) shortest_time = running_time;
    }

    void print_stats() const{
        std::cout << "=========================================================" << std::endl;
        std::cout << "this function has run " << count << " times" << std::endl;
        std::cout << "average function running time: " << (int64_t)(total_time / count) << time_unit << std::endl;
        std::cout << "longest function running time: " << longest_time << time_unit << std::endl;
        std::cout << "shortest function running time: " << shortest_time << time_unit << std::endl;
        std::cout << "=========================================================" << std::endl;
    }
};

// time the function for running once, default unit is millisecond
class FunctionTimer {
private:
    timeval start;
    timeval end;

public:
    void start_timer () {
        gettimeofday(&start, NULL);
    }

    void calculate_time() {
        gettimeofday(&end, NULL);
    }

    int64_t get_elapsed_time_in_milliseconds() const {
        return (end.tv_usec - start.tv_usec) / 1000;
    }

    int64_t get_elapsed_time_in_microseconds() const {
        return end.tv_usec - start.tv_usec;
    }
}; 

#endif
