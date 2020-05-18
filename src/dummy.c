#include "myctestexec/dummy.h"

int g_x = 1;

int dummy_func(int x) 
{
    return x == g_x;
}
