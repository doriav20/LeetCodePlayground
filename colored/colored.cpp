#include "colored.hpp"
#include "colored_priv.hpp"

#include <iostream>

namespace colored {
std::ostream& operator<<(std::ostream& os, const std::variant<Color, FontStyle> style) {
    if (&os != &std::cout) {
        return os;
    }

    static detail::StyleState state(Color::NO_COLOR, FontStyle::NORMAL);

    if (std::holds_alternative<Color>(style)) {
        detail::apply_color(std::get<Color>(style), state);
        state.color = std::get<Color>(style);
    }
    else if (std::holds_alternative<FontStyle>(style)) {
        detail::apply_font_style(std::get<FontStyle>(style), state);
        state.font_style = std::get<FontStyle>(style);
    }

    return os;
}
}
