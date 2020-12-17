#!/bin/bash

set -e

mkdir -p inputs

echo "generate inputs of problem A"

./toolkit_A/generator_A -d 0 > inputs/a_d0.txt
./toolkit_A/generator_A -d 1 > inputs/a_d1.txt
./toolkit_A/generator_A -d 2 > inputs/a_d2.txt
./toolkit_A/generator_A -d 3 > inputs/a_d3.txt

echo "generate inputs of problem B"

./toolkit_B/generator_B -d 0 > inputs/b_d0.txt
./toolkit_B/generator_B -d 1 > inputs/b_d1.txt
./toolkit_B/generator_B -d 2 > inputs/b_d2.txt
./toolkit_B/generator_B -d 3 > inputs/b_d3.txt
