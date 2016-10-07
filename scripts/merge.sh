#/bin/bash
# Merge all .cpp and .hpp files into merged.cpp deleting #include lines and
# inluding only local libraries.

CXX=clang

main="$1" # The main to merge into one file
to="$2" # The file where to merge

temp=/tmp/tempMerge.cpp

# Get all "#include <*>" and copy them to top of $to file
grep -he "#include <.*>" -r include src | sort -u > $to

# Get all hpp and cpp and add them to temp file
find ./include/ -name "*.hpp" -print0 | xargs -0 cat >> $temp
find ./src/ -name "*.cpp" -print0 | xargs -0 cat >> $temp

# Remove all "#include <*>" from the temp file
sed '/#include <*>/d' $temp > /dev/null

# Precompile the temps file and put add the result to $to file
gcc -P -E $temp >> $to
