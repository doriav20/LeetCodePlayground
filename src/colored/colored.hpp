#pragma once

#include <cstdint>
#include <iostream>
#include <type_traits>

namespace colored
{
namespace _internal
{
template<typename CharT>
bool is_supported_stream(std::basic_ostream<CharT>& stream)
{
    if constexpr (std::is_same_v<CharT, char>)
    {
        return (&stream == &std::cout || &stream == &std::cerr || &stream == &std::clog);
    }
    else if constexpr (std::is_same_v<CharT, wchar_t>)
    {
        return (&stream == &std::wcout || &stream == &std::wcerr || &stream == &std::wclog);
    }
    else
    {
        return false;
    }
}

template<typename CharT, typename... Parts>
std::basic_ostream<CharT>& write_code(std::basic_ostream<CharT>& stream, const Parts&... parts)
{
    if (!is_supported_stream(stream))
    {
        return stream;
    }

    stream << "\033[";
    (stream << ... << parts);
    stream << "m";
    return stream;
}
}

template<typename CharT>
std::basic_ostream<CharT>& reset(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 0);
}

template<typename CharT>
std::basic_ostream<CharT>& bold(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 1);
}

template<typename CharT>
std::basic_ostream<CharT>& dark(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 2);
}

template<typename CharT>
std::basic_ostream<CharT>& italic(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 3);
}

template<typename CharT>
std::basic_ostream<CharT>& underline(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 4);
}

template<typename CharT>
std::basic_ostream<CharT>& blink(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 5);
}

template<typename CharT>
std::basic_ostream<CharT>& reverse(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 7);
}

template<typename CharT>
std::basic_ostream<CharT>& concealed(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 8);
}

template<typename CharT>
std::basic_ostream<CharT>& crossed(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, 9);
}

template<uint8_t code, typename CharT>
std::basic_ostream<CharT>& color(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, "38;5;", +code);
}

template<uint8_t code, typename CharT>
std::basic_ostream<CharT>& bg_color(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, "48;5;", +code);
}

template<uint8_t r, uint8_t g, uint8_t b, typename CharT>
std::basic_ostream<CharT>& color(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, "38;2;", +r, ";", +g, ";", +b);
}

template<uint8_t r, uint8_t g, uint8_t b, typename CharT>
std::basic_ostream<CharT>& bg_color(std::basic_ostream<CharT>& stream)
{
    return _internal::write_code(stream, "48;2;", +r, ";", +g, ";", +b);
}

template<typename CharT>
std::basic_ostream<CharT>& grey(std::basic_ostream<CharT>& stream)
{
    return colored::color<8>(stream);
}

template<typename CharT>
std::basic_ostream<CharT>& red(std::basic_ostream<CharT>& stream)
{
    return colored::color<1>(stream);
}

template<typename CharT>
std::basic_ostream<CharT>& green(std::basic_ostream<CharT>& stream)
{
    return colored::color<2>(stream);
}

template<typename CharT>
std::basic_ostream<CharT>& yellow(std::basic_ostream<CharT>& stream)
{
    return colored::color<3>(stream);
}

template<typename CharT>
std::basic_ostream<CharT>& blue(std::basic_ostream<CharT>& stream)
{
    return colored::color<4>(stream);
}

template<typename CharT>
std::basic_ostream<CharT>& magenta(std::basic_ostream<CharT>& stream)
{
    return colored::color<5>(stream);
}

template<typename CharT>
std::basic_ostream<CharT>& cyan(std::basic_ostream<CharT>& stream)
{
    return colored::color<6>(stream);
}

template<typename CharT>
std::basic_ostream<CharT>& white(std::basic_ostream<CharT>& stream)
{
    return colored::color<15>(stream);
}
}
