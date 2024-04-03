#pragma once

void panic(const char *message);

#define ASSERT_DETAIL_STRINGIZE_DETAIL(x) #x
#define ASSERT_DETAIL_STRINGIZE(x) ASSERT_DETAIL_STRINGIZE_DETAIL(x)
#define assert(condition) do {if (!(condition)) panic("Assertion failure (" ASSERT_DETAIL_STRINGIZE(__LINE__) "@" __FILE__ "): " #condition);} while (0)
