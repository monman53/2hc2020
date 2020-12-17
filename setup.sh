#!/bin/bash

set -e

toolkit_A_zip_name=e23f0cbab29d3e414781820a7de3793f
toolkit_B_zip_name=1f53ec496de0fcb80f1b05485c0195ba

# download
wget https://img.atcoder.jp/hokudai-hitachi2020/${toolkit_A_zip_name}.zip
wget https://img.atcoder.jp/hokudai-hitachi2020/${toolkit_B_zip_name}.zip
unzip -f ${toolkit_A_zip_name}
unzip -f ${toolkit_B_zip_name}
rm -f ${toolkit_A_zip_name}.zip 
rm -f ${toolkit_B_zip_name}.zip

ls
