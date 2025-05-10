#include "colored_cout.hpp"

#include <iostream>
#include <windows.h>

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
}

void ColoredCout::reset_color(const colored::Color color) {
    const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

ColoredCout& ColoredCout::get_instance() {
    static ColoredCout instance;
    return instance;
}

ColoredCout::ColoredCout() : m_current_color(Color::NO_COLOR) {}

ColoredCout& cout = ColoredCout::get_instance();
}
