#!/bin/bash

set -e

echo ""
echo "# Build toolkits"

pushd toolkit_A
make
popd

pushd toolkit_B
make
popd

echo ""
echo "# Build answer code"

make
