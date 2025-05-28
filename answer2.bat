# Filter rows where GPA > 3.5
awk -F, 'NR==1 || $4 > 3.5' data.csv

# Calculate average GPA
awk -F, 'NR>1 {sum+=$4; count++} END {if (count > 0) print "Average GPA:", sum/count}' data.csv
