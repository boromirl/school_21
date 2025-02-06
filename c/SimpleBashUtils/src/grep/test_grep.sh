#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

test(){
    test_num=$1
    program=$2
    parameters=$3
    file=$4
    echo "Test $test_num: $file : testing flags $parameters:"
    grep $parameters $file > grep_output.txt
    ./$program $parameters $file > my_output.txt

    diff grep_output.txt my_output.txt

    if [ $? -eq 0 ]; then
        echo "${GREEN}SUCCESS${NC}"
    else
        echo "${RED}FAIL${NC}"
    fi

    leaks --atExit -- ./$program $parameters $file 1>my_output.txt 2> leaks_output.txt

    grep -q "leaks for" leaks_output.txt

    if [ $? -eq 0 ]; then
        echo "${RED}Memory leaks found${NC}"
    else
        echo "${GREEN}No leaks${NC}"
    fi


    rm grep_output.txt my_output.txt leaks_output.txt
}

echo "  -- Tests start --"

if [ $# -lt 2 ]; then
    echo "Usage: $0 <program> <file.txt>"
    exit 1
fi

program=$1

shift
test 1 $program "-e Lorem -e 2" "$@"
test 2 $program "-e Lorem sit" "$@"
test 3 $program "-i lor" "$@"
test 4 $program "-i -e SIT -e lorem" "$@"
test 5 $program "-v sit" "$@"
test 6 $program "-v -i SIT" "$@"
test 7 $program "-c sit" "$@"
test 8 $program "-c -v sit" "$@"
test 9 $program "-c -i SIT" "$@"
test 10 $program "-l sit" "$@"
test 11 $program "-l -v sit" "$@"
test 12 $program "-l -i SIT" "$@"
test 13 $program "-n sit" "$@"
test 14 $program "-n -v sit" "$@"
test 15 $program "-h sit" "$@"
test 16 $program "-h -c sit" "$@"
test 17 $program "-h -l sit" "$@"
test 18 $program "-s sit" "$@"
test 19 $program "-f patterns.txt" "$@"
test 20 $program "-o -e sit -e Lorem" "$@"
test 21 $program "Lorem" "$@"
test 22 $program "-ivnhso sit" "$@"
test 23 $program "-ivnhs sit" "$@"
test 24 $program "-ivnhs -f patterns.txt" "$@"
test 25 $program "-e sit -f patterns.txt" "$@"
test 26 $program "-e sit -f patterns.txt -f patterns2.txt" "$@"
test 27 $program "-f patterns.txt -i -o" "$@"

echo "${GREEN}--------------------------------------${NC}"




echo "  -- Tests end --"