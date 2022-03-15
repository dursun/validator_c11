#ifndef __VALIDATOR_H_
#define __VALIDATOR_H_

#include <stdbool.h>

// Anonymous structures and unions
typedef struct validator {
    union {
        // criteria for integers
        struct {
            int min;
            int max;
        };
        // criteria for strings
        struct {
            char *equal;
            unsigned long min_length;
            unsigned long max_length;
        };
    };
} validator;

// validation function for an integer
bool validate_int (const int var, validator rule);
// validation function for a string
bool validate_str (const char *var, validator rule);
// Type-generic expression with macro definition
#define validate(var, rule) _Generic((var), \
    int: validate_int, \
    char *: validate_str, \
    const char *: validate_str)(var, rule)

#endif //__VALIDATOR_H_