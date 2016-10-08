#!/bin/bash

# function to start the compiled application
function Start {
    # white space to become beautiful
    echo -e "Compiled successfully\n"

    # exec
    ./build/snake debug
}

function Abort {    
    echo -e "Got error during compilation stage.\n"
    echo -e "Exit code of the make is: $1"    
}

# compile
make

if [ $? -eq 0 ]
    then Start
    else Abort $? 
fi