#pragma once

#include <variant>
#include <iostream>

namespace colored {
enum class Color {
    NO_COLOR,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN,
    WHITE,
};

enum class FontStyle {
    NORMAL,
    BOLD,
};

std::ostream& operator<<(std::ostream& os, const std::variant<Color, FontStyle> style);
}
