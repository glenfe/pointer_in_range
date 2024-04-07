/*
Copyright 2024 Glen Joseph Fernandes (glenjofe@gmail.com)
Distributed under the Boost Software License, Version 1.0.
*/
#include <gtl/pointer_in_range.hpp>
#include <cstdio>

int result = 0;

void test(const char* e, int l, bool v)
{
    if (!v) {
        std::fprintf(stderr, "%d: '%s' failed\n", l, e);
        result = 1;
    }
}

#define TEST(e) test(#e, __LINE__, (e))

int a[4] = { 0, 0, 0, 0 };
int n = 0;
const int b[4] = { 0, 0, 0, 0 };
const int m = 0;

static_assert(!gtl::pointer_in_range(&a[0], &a[1], a + 4));
static_assert(gtl::pointer_in_range(&a[1], &a[1], a + 4));
static_assert(gtl::pointer_in_range(&a[2], &a[1], a + 4));
static_assert(gtl::pointer_in_range(&a[3], &a[1], a + 4));
static_assert(!gtl::pointer_in_range(a + 4, &a[1], a + 4));
static_assert(!gtl::pointer_in_range(&n, &a[0], &a[3]));
static_assert(!gtl::pointer_in_range(&m, &a[0], &a[3]));
static_assert(!gtl::pointer_in_range(&b[0], &b[1], b + 4));
static_assert(gtl::pointer_in_range(&b[1], &b[1], b + 4));
static_assert(gtl::pointer_in_range(&b[2], &b[1], b + 4));
static_assert(gtl::pointer_in_range(&b[3], &b[1], b + 4));
static_assert(!gtl::pointer_in_range(b + 4, &b[1], b + 4));
static_assert(!gtl::pointer_in_range(&n, &b[0], &b[3]));
static_assert(!gtl::pointer_in_range(&m, &b[0], &b[3]));

int main()
{
    TEST(!gtl::pointer_in_range(&a[0], &a[1], a + 4));
    TEST(gtl::pointer_in_range(&a[1], &a[1], a + 4));
    TEST(gtl::pointer_in_range(&a[2], &a[1], a + 4));
    TEST(gtl::pointer_in_range(&a[3], &a[1], a + 4));
    TEST(!gtl::pointer_in_range(a + 4, &a[1], a + 4));
    TEST(!gtl::pointer_in_range(&n, &a[0], &a[3]));
    TEST(!gtl::pointer_in_range(&m, &a[0], &a[3]));
    TEST(!gtl::pointer_in_range(&b[0], &b[1], b + 4));
    TEST(gtl::pointer_in_range(&b[1], &b[1], b + 4));
    TEST(gtl::pointer_in_range(&b[2], &b[1], b + 4));
    TEST(gtl::pointer_in_range(&b[3], &b[1], b + 4));
    TEST(!gtl::pointer_in_range(b + 4, &b[1], b + 4));
    TEST(!gtl::pointer_in_range(&n, &b[0], &b[3]));
    TEST(!gtl::pointer_in_range(&m, &b[0], &b[3]));
    return result;
}
