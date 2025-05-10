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

ColoredCout& ColoredCout::operator<<(const FontStyle new_font_style) {
    m_font_style = new_font_style;
    return *this;
}

ColoredCout& ColoredCout::operator<<(std::ostream&(*manip)(std::ostream&)) {
    manip(std::cout);
    return *this;
}

void ColoredCout::setup_color(const colored::Color color, const colored::FontStyle font_style) {
#ifdef _WIN32
    const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

    WORD attributes = 0;
    switch (color) {
        case Color::RED:
            attributes |= FOREGROUND_RED;
            break;
        case Color::GREEN:
            attributes |= FOREGROUND_GREEN;
            break;
        case Color::BLUE:
            attributes |= FOREGROUND_BLUE;
            break;
        case Color::YELLOW:
            attributes |= FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        case Color::MAGENTA:
            attributes |= FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        case Color::CYAN:
            attributes |= FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        case Color::WHITE:
            attributes |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
    }

    switch (font_style) {
        case FontStyle::NORMAL:
            break;
        case FontStyle::BOLD:
            attributes |= FOREGROUND_INTENSITY;
            break;
    }

    if (attributes != 0) {
        SetConsoleTextAttribute(console_handle, attributes);
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

    switch (font_style) {
        case FontStyle::NORMAL:
            break;
        case FontStyle::BOLD:
            std::cout << "\033[1m";
            break;
    }
#endif
}

void ColoredCout::reset_color(const colored::Color color, const colored::FontStyle font_style) {
#ifdef _WIN32
    const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_handle, (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) & ~FOREGROUND_INTENSITY);
#else
    std::cout << "\033[0m";
#endif
}

ColoredCout& ColoredCout::get_instance() {
    static ColoredCout instance;
    return instance;
}

ColoredCout::ColoredCout() : m_current_color(Color::NO_COLOR), m_font_style(FontStyle::NORMAL) {}

ColoredCout& cout = ColoredCout::get_instance();
}
