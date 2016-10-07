#/bin/bash
# Merge all .cpp and .hpp files into merged.cpp deleting #include lines.

main="$1" # The main to merge into one file
to="$2" # The file where to merge

clang -E -P $main > $2

#find ./include/ -name "*.hpp" -print0 | xargs -0 cat > merged.cpp
#find ./src/ -name "*.cpp" -print0 | xargs -0 cat >> merged.cpp
#sed '/#include "*"/d' merged.cpp > /dev/null
