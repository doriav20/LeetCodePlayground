#pragma once

#include <iostream>

namespace colored {
class ColoredCout {
public:
    ColoredCout& operator<<(std::ostream& (*manip)(std::ostream&));

    template<typename T>
    ColoredCout& operator<<(const T& value) {
        std::cout << value;
        return *this;
    }

    static ColoredCout& get_instance();

private:
    ColoredCout() = default;
};

extern ColoredCout& cout;
}
