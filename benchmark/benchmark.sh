#!/bin/bash
blue=$(tput setaf 4)
gray=$(tput setaf 7)
green=$(tput setaf 2)
teal=$(tput setaf 6)
normal=$(tput sgr0)

for representation in "representations/"*; do
    for routine in "routines/"*; do
        for benchmark in "benchmark/generate."*; do #Using file extensions to denote instance size, since extracting extension is trivial in Linux
            instance_size=${benchmark##*.}
            #Initial log - before program completion
            tmpLogFile=$(mktemp) #tmpfile to allow for pretty colors using printf
            cat > $tmpLogFile <<EOF
$normal============================[INSTANCE SIZE $instance_size]============================$green
Running the $routine benchmark for $representation. 
$normal============================[Input]============================$gray
$(cat  $representation $benchmark $routine <(echo $instance_size) <(echo exit))
$normal============================[Program Output]===================$teal 

EOF
            printf "$(more $tmpLogFile)" #printf allows for pretty colors
            tmpFile=$(mktemp) #saving to tmp file so it can be logged in follow up log
            run_project="python3 ../../mit3r/03_Graphs/main.py -generate"
            #Please note that <(echo $instance_size) is unnecesarry for routines kahn_sort and tarjan_sort, but the program should ignore invalid `actions`.
            result=$(/usr/bin/time -f "%S|%M" $run_project < <(cat $representation $benchmark $routine <(echo $instance_size) <(echo exit)) 2>&1 >$tmpFile)
            mem=${result##*|}
            time=${result%|*}

            #Save to .csv
            echo "$(basename $representation),$instance_size,$time" >> $(basename $routine)_benchmark_time.csv
            echo "$(basename $representation),$instance_size,$mem" >> $(basename $routine)_benchmark_memory.csv
            
            #Follow up log - after program completion
            cat > $tmpLogFile <<EOF

$(cat $tmpFile)
$normal============================[usr/bin/time]=====================$green
time = $(echo $time) seconds | memory used = $(echo $mem) KBi
Saved to $(basename $routine)_benchmark_time.csv $(basename $routine)_benchmark_memory.csv

$normal
EOF
        printf "$(more $tmpLogFile)" #printf allows for pretty colors

        done
    done
done
