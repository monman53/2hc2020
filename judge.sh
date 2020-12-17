#!/bin/bash

set -e

# echo "judge problem A"
#
# ./toolkit_A/judge_A ./a < inputs/a_d0.txt
# ./toolkit_A/judge_A ./a < inputs/a_d1.txt
# ./toolkit_A/judge_A ./a < inputs/a_d2.txt
# ./toolkit_A/judge_A ./a < inputs/a_d3.txt

echo "judge problem B"

./toolkit_B/judge_B ./b < inputs/b_d0.txt
./toolkit_B/judge_B ./b < inputs/b_d1.txt
./toolkit_B/judge_B ./b < inputs/b_d2.txt
./toolkit_B/judge_B ./b < inputs/b_d3.txt
