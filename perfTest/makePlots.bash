#!/bin/bash


declare -A titles
titles[0]="packed strings:USE_PACKED_STRINGS_0.times"
titles[1]="for each:USE_STD_STRING_USE_FOR_EACH.times"
titles[2]="c style:USE_STD_STRING_USE_C_STYLE.times"
titles[3]="mismatch:USE_STD_STRING_USE_MISMATCH.times"


plotFile="makePlots.gnuplot"

echo "set yrange [0:]" > "${plotFile}"
echo "set grid" >> "${plotFile}"
echo "plot \\" >> "${plotFile}"


for config in "${titles[@]}" ; do
    title=$(echo "${config}" | cut -d ':' -f1)
    file=$(echo "${config}" | cut -d ':' -f2)
    echo "'"${file}"' using 2 with line title '" ${title}"' , \\" >> "${plotFile}"
done

echo "" >> "${plotFile}"


gnuplot -persist "${plotFile}"
