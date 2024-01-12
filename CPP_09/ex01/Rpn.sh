#!/bin/bash

# Test inverted Polish mathematical expression program

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
    "23 4.2 1.5 / *"
    "1 2 + 3 * 4 - 5 /"
    "1 2 3 4 5 +*-/"
    "9 2 / 3 2 * + 4 2 * -"
    "2 23 *"
    "4 0 /"
    "23 2.5 /"
    " 1 1 +"
)

corr_answer=(
    "2"
    "23"
    "9.526"
    "64.4"
    "1"
    "-0.04"
    "2.5"
    "46"
    "inf"
    "23 2.5 /"
    " 1 1 +"
)

# Run the tests
for i in "${!test_cases[@]}"; do
   output=$(./RPN "${test_cases[$i]}")
    if [ "$output" = "${corr_answer[$i]}" ]; then
        echo "Test $i passed"
    else
        echo "Test $i failed"
    fi
done
