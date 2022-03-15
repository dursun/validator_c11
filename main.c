/**
 * @file main.c
 * @author Dursun Can Turan (dursun.turan@braxp.com)
 * @brief Basic validator with C11 features (Type-generic expressions and Anonymous structures and unions)
 */

#include "validator.h"

#include <stdio.h>

int main (int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    // Define validation rules
    validator rule_int_between = {.min=1, .max=127};
    validator rule_str_equal = {.equal="dursun"};
    validator rule_str_length = {.min_length=5, .max_length=10};
    
    printf("true=%s\n", validate(5, rule_int_between) ? "true" : "false");
    printf("false=%s\n", validate(-1, rule_int_between) ? "true" : "false");
    printf("false=%s\n", validate(128, rule_int_between) ? "true" : "false");
    
    printf("true=%s\n", validate((char*)"dursun", rule_str_equal) ? "true" : "false");
    printf("false=%s\n", validate((char*)"turan", rule_str_equal) ? "true" : "false");

    printf("true=%s\n", validate((char*)"dursun can", rule_str_length) ? "true" : "false");
    printf("false=%s\n", validate((char*)"dursun can turan", rule_str_length) ? "true" : "false");

    return 0;
}