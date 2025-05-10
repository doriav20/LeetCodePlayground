#include "colored_cout.hpp"

#include <iostream>

namespace colored {
ColoredCout& ColoredCout::operator<<(std::ostream&(*manip)(std::ostream&)) {
    manip(std::cout);
    return *this;
}

ColoredCout& ColoredCout::get_instance() {
    static ColoredCout instance;
    return instance;
}

ColoredCout& cout = ColoredCout::get_instance();
}
