#pragma once

#ifdef __cplusplus
namespace _ctype {
extern "C" {
#endif

int isdigit(int c);
int isxdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isblank(int c);
int isspace(int c);
int iscntrl(int c);

#ifdef __cplusplus
}
}

namespace std {
using namespace ::_ctype;
}

using namespace ::_ctype;
#endif
