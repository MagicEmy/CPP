#!/bin/bash

function run() {
    if [ "$(uname)" == "Linux" ]; then
        ./PmergeMe $(shuf -i 0-1000000 -n $1 | tr "\n" " ")
    elif [ "$(uname)" == "Darwin" ]; then
        ./PmergeMe $(jot -r $1 0 1000000 | tr "\n" " ")
    fi
}


run 3000