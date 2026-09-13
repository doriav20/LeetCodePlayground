#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "colored.hpp"

#include <cstdio>
#include <cstdlib>

#include <sys/stat.h>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <io.h>
#include <windows.h>
#endif

namespace colored::_internal
{
namespace
{
bool is_env_set(const char* name)
{
    const char* value = std::getenv(name);
    return value != nullptr && value[0] != '\0';
}

bool is_redirected_to_file(std::FILE* file)
{
#ifdef _WIN32
    struct _stat info{};
    return _fstat(_fileno(file), &info) == 0 && (info.st_mode & _S_IFMT) == _S_IFREG;
#else
    struct stat info{};
    return fstat(fileno(file), &info) == 0 && S_ISREG(info.st_mode);
#endif
}

#ifdef _WIN32
bool enable_escape_codes(std::FILE* file)
{
    const HANDLE handle = reinterpret_cast<HANDLE>(_get_osfhandle(_fileno(file)));
    DWORD mode = 0;
    if (GetConsoleMode(handle, &mode) == 0)
    {
        return true;
    }
    return SetConsoleMode(handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING) != 0;
}
#else
bool enable_escape_codes(std::FILE*)
{
    return true;
}
#endif

bool detect_colors(std::FILE* file)
{
    if (is_env_set("FORCE_COLOR"))
    {
        enable_escape_codes(file);
        return true;
    }
    if (is_env_set("NO_COLOR"))
    {
        return false;
    }
    return !is_redirected_to_file(file) && enable_escape_codes(file);
}
}

bool is_colored_output(const Output output)
{
    static const bool standard_colored = detect_colors(stdout);
    static const bool error_colored = detect_colors(stderr);
    return output == Output::standard ? standard_colored : error_colored;
}
}
