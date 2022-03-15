#include "validator.h"

#include <string.h>

bool validate_int (const int var, const validator rule)
{
    return (var >= rule.min && var <= rule.max) ? true : false;
}

bool validate_str (const char *var, const validator rule)
{
    if (!var) return false;

    if (rule.equal && strlen(rule.equal) > 0) {
        return (!!strncmp(var, rule.equal, strlen(rule.equal))) ? false : true;
    }

    return (strlen(var) >= rule.min_length && strlen(var) <= rule.max_length) ? true : false;
}