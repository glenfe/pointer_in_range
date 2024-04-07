/*
Copyright 2024 Glen Joseph Fernandes (glenjofe@gmail.com)
Distributed under the Boost Software License, Version 1.0.
*/
#ifndef GTL_POINTER_IN_RANGE_HPP
#define GTL_POINTER_IN_RANGE_HPP

#include <functional>
#include <type_traits>

namespace gtl {

template<class T>
constexpr bool pointer_in_range(const T* p, const T* b, const T* e)
{
    if (std::is_constant_evaluated()) {
        for (; b != e; ++b) {
            if (b == p) {
                return true;
            }
        }
        return false;
    }
    return std::less_equal<>()(b, p) && std::less<>()(p, e);
}

} /* gtl */

#endif
