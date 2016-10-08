#!/bin/bash

# compile
make

if $?=='0' 
    then echo "Compiled successfully"
    else echo "no success"
fi

# white space to become beautiful
echo -e "\n"

# exec
./build/snake