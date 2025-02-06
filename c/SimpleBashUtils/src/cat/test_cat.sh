#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

test(){
    test_num=$1
    program=$2
    flags=$3
    file=$4
    echo "Test $test_num: $file : testing flags $flags:"
    cat $flags $file > cat_output.txt > /dev/null
    ./$program $flags $file > my_output.txt > /dev/null

    diff cat_output.txt my_output.txt

    if [ $? -eq 0 ]; then
        echo "${GREEN}SUCCESS${NC}"
    else
        echo "${RED}FAIL${NC}"
    fi
    rm cat_output.txt my_output.txt
}

echo "  -- Tests start --"

if [ $# -lt 2 ]; then
    echo "Usage: $0 <program> <file.txt>"
    exit 1
fi

program=$1
shift

test 1 $program "-b" "$@"
test 2 $program "-e" "$@"
test 3 $program "-n" "$@"
test 4 $program "-s" "$@"
test 5 $program "-t" "$@"
test 6 $program "-v" "$@"
test 7 $program "" "$@"
test 8 $program "-k" "$@"
test 9 $program "-b" "doesnt_exist.txt"

echo "${GREEN}--------------------------------------${NC}"




echo "  -- Tests end --"