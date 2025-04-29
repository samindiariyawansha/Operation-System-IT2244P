vi test.csv: Open/creates a file using the vi editor.

more test.csv: Displays file contents one page at a time.

cut -d, -f1,2 test.csv: Extracts the first two columns from test.csv.

head -3 test.csv: Shows the first 3 lines of the file.

tail -3 test.csv: Displays the last 3 lines of the file.

wc -l test1.csv: Counts the lines in test1.csv.

awk -F, '{print $1}' test.csv: Prints the first field (column) from test.csv.

chmod 444 test.csv: Sets test.csv as read-only.

chmod 744 test.csv: Makes test.csv readable, writable, and executable by the owner.# Operation-System-IT2244P
