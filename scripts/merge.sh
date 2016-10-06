#/bin/bash
# Merge all .cpp and .hpp files into merged.cpp deleting #include lines.

find ./include/ -name "*.hpp" -print0 | xargs -0 cat > merged.cpp
find ./src/ -name "*.cpp" -print0 | xargs -0 cat >> merged.cpp
sed '/#include/d' merged.cpp
sed '/# include/d' merged.cpp
