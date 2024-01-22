#!/bin/bash

# Test inverted Polish mathematical expression program
# https://paodayag.dev/reverse-polish-notation-js-parser/

make
RET=$?;
if [ $RET -ne 0 ]; then
	echo	"Makefile failed";
	exit $RET;
fi


# Define test cases
test_cases=(
    "2"
    "4 1 -"
    "1 8 +"
    "2 4 1 / *"
    "1 2 + 3 * 4 - 5 /"
    "1 2 3 4 5 + * - /"
    "9 2 / 3 2 * + 4 2 * -"
    "9 9 *"
    "4 0 /"
    "0 4 /"
    "2 2 /"
    " 1   1 +"
)

corr_answer=(
    "2"
    "3"
    "9"
    "8"
    "1"
    "-0.04"
    "2.5"
    "81"
    "inf"
    "0"
    "1"
    "2"
)

# Run the tests
for i in "${!test_cases[@]}"; do
   output=$(./RPN "${test_cases[$i]}")
    if [ "$output" = "${corr_answer[$i]}" ]; then
        echo -n "Test $i passed "
		echo "Output: $output"
    else
        echo -n "Test $i failed "
		echo "Output: $output"
    fi
done
