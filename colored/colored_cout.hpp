#pragma once

#include <iostream>

#include "color.hpp"

namespace colored {
class ColoredCout {
public:
    ColoredCout& operator<<(const Color new_color);

    ColoredCout& operator<<(std::ostream& (*manip)(std::ostream&));

    template<typename T>
    ColoredCout& operator<<(const T& value) {
        if (m_current_color == Color::NO_COLOR) {
            std::cout << value;
            return *this;
        }

        setup_color(m_current_color);
        std::cout << value;
        reset_color(m_current_color);
        return *this;
    }

    static ColoredCout& get_instance();

private:
    ColoredCout();

    static void setup_color(const colored::Color color);

    static void reset_color(const colored::Color color);

    Color m_current_color;
};

extern ColoredCout& cout;
}
