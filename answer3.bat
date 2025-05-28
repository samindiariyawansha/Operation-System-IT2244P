# Read user input
read -p "Enter String_1: " str1
read -p "Enter String_2: " str2

# Get string lengths
len1=${#str1}
len2=${#str2}

# Compare lengths
if [ $len1 -gt $len2 ]; then
    echo "$str1 is larger than $str2"
elif [ $len1 -lt $len2 ]; then
    echo "$str2 is larger than $str1"
else
    echo "Both strings are of equal length"
fi