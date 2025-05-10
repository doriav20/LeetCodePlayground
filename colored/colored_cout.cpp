#include "colored_cout.hpp"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace colored {
ColoredCout& ColoredCout::operator<<(const Color new_color) {
    m_current_color = new_color;
    return *this;
}

ColoredCout& ColoredCout::operator<<(std::ostream&(*manip)(std::ostream&)) {
    manip(std::cout);
    return *this;
}

void ColoredCout::setup_color(const colored::Color color) {
#ifdef _WIN32
    const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (color) {
        case Color::RED:
            SetConsoleTextAttribute(console_handle, FOREGROUND_RED);
            break;
        case Color::GREEN:
            SetConsoleTextAttribute(console_handle, FOREGROUND_GREEN);
            break;
        case Color::BLUE:
            SetConsoleTextAttribute(console_handle, FOREGROUND_BLUE);
            break;
        case Color::YELLOW:
            SetConsoleTextAttribute(console_handle, FOREGROUND_RED | FOREGROUND_GREEN);
            break;
        case Color::MAGENTA:
            SetConsoleTextAttribute(console_handle, FOREGROUND_RED | FOREGROUND_BLUE);
            break;
        case Color::CYAN:
            SetConsoleTextAttribute(console_handle, FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case Color::WHITE:
            SetConsoleTextAttribute(console_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
    }
#else
    switch (color) {
        case Color::RED:
            std::cout << "\033[31m";
            break;
        case Color::GREEN:
            std::cout << "\033[32m";
            break;
        case Color::BLUE:
            std::cout << "\033[34m";
            break;
        case Color::YELLOW:
            std::cout << "\033[33m";
            break;
        case Color::MAGENTA:
            std::cout << "\033[35m";
            break;
        case Color::CYAN:
            std::cout << "\033[36m";
            break;
        case Color::WHITE:
            std::cout << "\033[37m";
            break;
    }
#endif
}

void ColoredCout::reset_color(const colored::Color color) {
#ifdef _WIN32
    const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
    std::cout << "\033[0m";
#endif
}

ColoredCout& ColoredCout::get_instance() {
    static ColoredCout instance;
    return instance;
}

ColoredCout::ColoredCout() : m_current_color(Color::NO_COLOR) {}

ColoredCout& cout = ColoredCout::get_instance();
}
