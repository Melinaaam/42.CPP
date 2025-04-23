#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include<iostream>
#include<string>

template <typename T>
void swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}


template <typename T>
T const & min(const T& a, const T& b) {
    return (a<b?a:b);
}

template <typename T>
T const & max(const T& a, const T& b) {
    return (a>b?a:b);
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