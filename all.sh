#!/bin/bash

set -e

./clean.sh
./setup.sh
./make.sh
./generate.sh
./judge.sh
