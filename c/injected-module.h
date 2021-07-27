#ifndef INJECTED_MODULE_H
#   define INJECTED_MODULE_H

#   ifdef __cplusplus
#       define EXPORT extern "C"
#   else
#       define EXPORT extern
#   endif

#   include <assert.h>
#   include <math.h>
#   include <stdbool.h>
#   include <stdint.h>
#   include <stdlib.h>

EXPORT double hypothenuse(double x, double y);

#endif