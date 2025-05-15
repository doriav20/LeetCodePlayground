#include "colored.hpp"
#include "colored_priv.hpp"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace colored {
namespace detail {
StyleState::StyleState(const Color color, const FontStyle font_style) : color(color), font_style(font_style) {}

void apply_color(const Color color, const StyleState& current_state) {
    StyleState new_style_state(current_state);
    new_style_state.color = color;
    apply_style_state(new_style_state);
}

void apply_font_style(const FontStyle font_style, const StyleState& current_state) {
    StyleState new_style_state(current_state);
    new_style_state.font_style = font_style;
    apply_style_state(new_style_state);
}

void apply_style_state(const StyleState& current_state) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD color_attributes = 0;

    switch (current_state.color) {
        case Color::RED:
            color_attributes |= FOREGROUND_RED;
            break;
        case Color::GREEN:
            color_attributes |= FOREGROUND_GREEN;
            break;
        case Color::BLUE:
            color_attributes |= FOREGROUND_BLUE;
            break;
        case Color::YELLOW:
            color_attributes |= FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        case Color::MAGENTA:
            color_attributes |= FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        case Color::CYAN:
            color_attributes |= FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        case Color::WHITE:
            color_attributes |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        default:
            break;
    }

    switch (current_state.font_style) {
        case FontStyle::BOLD:
            color_attributes |= FOREGROUND_INTENSITY;
            break;
        case FontStyle::NORMAL:
            color_attributes &= ~FOREGROUND_INTENSITY;
            break;
        default:
            break;
    }

    SetConsoleTextAttribute(hConsole, color_attributes);
#else
    std::string color_code;
    std::string font_style_code;
    switch (current_state.color) {
        case Color::RED:
            color_code = "31";
            break;
        case Color::GREEN:
            color_code = "32";
            break;
        case Color::BLUE:
            color_code = "34";
            break;
        case Color::YELLOW:
            color_code = "33";
            break;
        case Color::MAGENTA:
            color_code = "35";
            break;
        case Color::CYAN:
            color_code = "36";
            break;
        case Color::WHITE:
            color_code = "37";
            break;
        default:
            color_code = "0";
            break;
    }

    switch (current_state.font_style) {
        case FontStyle::BOLD:
            font_style_code = "1";
            break;
        case FontStyle::NORMAL:
            font_style_code = "0";
            break;
        default:
            font_style_code = "0";
            break;
    }

    const std::string escape_code = std::format("\033[{};{}m", font_style_code, color_code);
    std::cout << escape_code;
#endif
}

void update_style_state(StyleState& style_state) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return;
    }

    const DWORD color_attributes = csbi.wAttributes & (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    switch (color_attributes) {
        case FOREGROUND_RED:
            style_state.color = Color::RED;
            break;
        case FOREGROUND_GREEN:
            style_state.color = Color::GREEN;
            break;
        case FOREGROUND_BLUE:
            style_state.color = Color::BLUE;
            break;
        case FOREGROUND_RED | FOREGROUND_GREEN:
            style_state.color = Color::YELLOW;
            break;
        case FOREGROUND_GREEN | FOREGROUND_BLUE:
            style_state.color = Color::CYAN;
            break;
        case FOREGROUND_RED | FOREGROUND_BLUE:
            style_state.color = Color::MAGENTA;
            break;
        case FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE:
            style_state.color = Color::WHITE;
            break;
        default:
            style_state.color = Color::NO_COLOR;
            break;
    }

    const DWORD font_attributes = csbi.wAttributes & (FOREGROUND_INTENSITY);
    switch (font_attributes) {
        case FOREGROUND_INTENSITY:
            style_state.font_style = FontStyle::BOLD;
            break;
        default:
            style_state.font_style = FontStyle::NORMAL;
            break;
    }
#endif
}
}
}
