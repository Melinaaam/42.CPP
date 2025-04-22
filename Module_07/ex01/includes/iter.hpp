#ifndef ITER_HPP
#define ITER_HPP
#include<iostream>
#include<string>

/* template function */

template <typename T, typename Func>
void iter(T* array, std::size_t length, Func f) {
    for(size_t i = 0; i < length; i++){
        f(array[i]);
    }
}

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[38;5;220m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35;1m"
#define MAGENTA1 "\033[0;35;2m"
#define MAGENTA2 "\033[0;35;4m"
#define CYAN    "\033[38;5;45m"
#define PINK    "\033[38;5;213m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"
#define CLIGNOTE "\033[0;35;5m"
#define UNDER_	"\x1b[4m"

#endif