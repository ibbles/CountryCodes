#!/bin/bash

set -e

baseDirectory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

sourceFile="${baseDirectory}/../src/LinearSearch/LinearSearch.cpp"

function set_string_format {
    stringFormat=$1
    sed -ri 's,#define STRING_FORMAT .+,#define STRING_FORMAT '${stringFormat}',' "${sourceFile}"
}

function set_match_algorithm {
    algorithm=$1
    sed -ri 's,#define MATCH_ALGORITHM .+,#define MATCH_ALGORITHM '${algorithm}',' "${sourceFile}"
}


function run_test {
    echo "Running $1, $2"

    stringFormat=$1
    algorithm=$2

    set_string_format "${stringFormat}"
    set_match_algorithm "${algorithm}"

    ninja

    outputFile="${stringFormat}_${algorithm}.times"
    echo -n "" > "${outputFile}"
    for ((i=0 ; i < 20; ++i)) ; do
        ./src/LinearSearch/LinearSearch | cut -d ' ' -f2,5,7 >> "${outputFile}"
    done
}



run_test USE_STD_STRING USE_MISMATCH
run_test USE_STD_STRING USE_C_STYLE
run_test USE_STD_STRING USE_FOR_EACH

run_test USE_PACKED_STRINGS "0"
