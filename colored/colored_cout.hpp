#pragma once

#include <iostream>

#include "enums.hpp"

namespace colored {
class ColoredCout {
public:
    ColoredCout& operator<<(const Color new_color);
    ColoredCout& operator<<(const FontStyle new_font_style);

    ColoredCout& operator<<(std::ostream& (*manip)(std::ostream&));

    template<typename T>
    ColoredCout& operator<<(const T& value) {
        if (m_current_color == Color::NO_COLOR) {
            std::cout << value;
            return *this;
        }

        setup_color(m_current_color, m_font_style);
        std::cout << value;
        reset_color(m_current_color, m_font_style);
        return *this;
    }

    static ColoredCout& get_instance();

private:
    ColoredCout();

    static void setup_color(const colored::Color color, const colored::FontStyle font_style);

    static void reset_color(const colored::Color color, const colored::FontStyle font_style);

    Color m_current_color;
    FontStyle m_font_style;
};

extern ColoredCout& cout;
}
