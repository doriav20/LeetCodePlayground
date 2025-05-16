#include "colored.hpp"
#include "colored_priv.hpp"

#include <iostream>
#include <format>

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
}
}
}
