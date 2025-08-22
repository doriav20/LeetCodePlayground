#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>

template<typename T>
std::string vector_to_string(const std::vector<T>& vec)
{
    if (vec.empty())
    {
        return "[]";
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        oss << ", " << vec[i];
    }

    oss << " ]";

    return oss.str();
}

template<typename T>
std::string matrix_to_string(const std::vector<std::vector<T> >& mat)
{
    if (mat.empty())
    {
        return "[]";
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << vector_to_string(mat[0]);
    for (int i = 1; i < mat.size(); i++)
    {
        oss << ", " << vector_to_string(mat[i]);
    }

    oss << " ]";

    return oss.str();
}

template<typename T>
std::string stack_to_string(const std::stack<T>& stk)
{
    if (stk.empty())
    {
        return "[]";
    }

    std::stack<T> stk_copy = stk;
    std::queue<T> q;
    while (!stk_copy.empty())
    {
        q.push(stk_copy.top());
        stk_copy.pop();
    }

    std::ostringstream oss;

    oss << "[ ";

    oss << q.front();
    q.pop();

    while (!q.empty())
    {
        oss << ", " << q.front();
        q.pop();
    }

    oss << " ]";

    return oss.str();
}
