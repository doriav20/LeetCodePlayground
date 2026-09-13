#include "colored.hpp"

#include <cstdio>

#include <sys/stat.h>

namespace colored::_internal
{
namespace
{
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

bool detect_colors(std::FILE* file)
{
    return !is_redirected_to_file(file);
}
}

bool is_colored_output(const Output output)
{
    static const bool standard_colored = detect_colors(stdout);
    static const bool error_colored = detect_colors(stderr);
    return output == Output::standard ? standard_colored : error_colored;
}
}
