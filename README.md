1. **Create a file `bcd.tsv`**: 
   - `touch bcd.tsv`: Creates an empty file named `bcd.tsv`.

2. **View content of `bcd.tsv`**: 
   - `more bcd.tsv`: Displays file contents page by page.

3. **Extract the first column (tab-separated)**: 
   - `cut -d$'\t' -f1 bcd.tsv`: Extracts the first column using tab as a delimiter.

4. **Extract the third column using space as delimiter**: 
   - `cut -d " " -f3 bcd.tsv`: Extracts the third column using space as a delimiter.

5. **Display first 2 lines**: 
   - `head -n2 bcd.tsv`: Shows the first two lines of the file.

6. **Display last 2 lines**: 
   - `tail -n2 bcd.tsv`: Shows the last two lines of the file.

7. **Extract first column using space as delimiter**: 
   - `cut -d ' ' -f1 bcd.tsv`: Extracts the first column using space as a delimiter.

8. **Edit `bcd.tsv` to remove tabs and add spaces**: 
   - Edited with `vi`, then extracted columns again using space delimiter.

9. **Extract second column using space delimiter**: 
   - `cut -d ' ' -f2 bcd.tsv`: Extracts the second column using space as delimiter.

10. **Display first 10 lines**: 
    - `head bcd.tsv`: Shows the first 10 lines of the file.

11. **Display first 8 lines**: 
    - `head -8 bcd.tsv`: Shows the first 8 lines.

12. **Display first line**: 
    - `head -1 bcd.tsv`: Shows only the first line.

13. **Display last line**: 
    - `tail -1 bcd.tsv`: Shows only the last line.

14. **Display first 100 lines**: 
    - `head -100 bcd.tsv`: Displays the first 100 lines.

15. **Extract the 8th line**: 
    - `head -n8 bcd.tsv | tail -n1`: Extracts the 8th line.

16. **Print the number of columns (separated by space)**: 
    - `awk '{print NF; exit}' bcd.tsv`: Prints the number of columns based on space delimiter.

17. **Print the number of columns (separated by tab)**: 
    - `awk -F'\t' '{print NF; exit}' bcd.tsv`: Prints the number of columns based on tab delimiter.

18. **Print the 3rd column using `awk`**: 
    - `awk '{print $3}' bcd.tsv`: Prints the third column.

19. **Count the number of lines**: 
    - `wc -l bcd.tsv`: Counts the number of lines in the file.

20. **Search for "dd" in the first 10 lines**: 
    - `head -n10 bcd.tsv | grep 'dd'`: Searches for "dd" in the first 10 lines.

21. **Search for "88" in the first 7 lines**: 
    - `head -n7 bcd.tsv | grep '88'`: Searches for "88" in the first 7 lines.
