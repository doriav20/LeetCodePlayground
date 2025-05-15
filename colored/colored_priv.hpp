#pragma once

namespace colored {
namespace detail {
struct StyleState {
    Color color;
    FontStyle font_style;

    StyleState(const Color color, const FontStyle font_style);
};

void apply_color(const Color color, const StyleState& current_state);

void apply_font_style(const FontStyle font_style, const StyleState& current_state);

void apply_style_state(const StyleState& current_state);

void update_style_state(StyleState& style_state);
}
}
