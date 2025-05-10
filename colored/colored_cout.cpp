#include "colored_cout.hpp"

#include <iostream>

namespace colored {
ColoredCout& ColoredCout::operator<<(const Color new_color) {
    m_current_color = new_color;
    return *this;
}

ColoredCout& ColoredCout::operator<<(std::ostream&(*manip)(std::ostream&)) {
    manip(std::cout);
    return *this;
}

void ColoredCout::setup_color(const colored::Color color) {}

void ColoredCout::reset_color(const colored::Color color) {}

ColoredCout& ColoredCout::get_instance() {
    static ColoredCout instance;
    return instance;
}

ColoredCout::ColoredCout() : m_current_color(Color::NO_COLOR) {}

ColoredCout& cout = ColoredCout::get_instance();
}
