
![Screenshot (103)](https://github.com/user-attachments/assets/19807aaa-b561-4b48-80ef-6ec47faf68ec)
![Screenshot (104)](https://github.com/user-attachments/assets/4d474b14-66a5-42dc-9014-74d6e6973616)
![Screenshot (105)](https://github.com/user-attachments/assets/05daf71b-5a2d-49be-94f3-1f34af9cc9bc)
![Screenshot 2025-05-28 181817](https://github.com/user-attachments/assets/5cdc978d-44c1-4f2f-80e9-518b473c791e)
![Screenshot (106)](https://github.com/user-attachments/assets/68d029fa-323e-43fc-b803-bdb775c1c2bc)
![Screenshot (107)](https://github.com/user-attachments/assets/82874229-a2b5-4bd3-9587-be8734bbdab0)
![Screenshot (108)](https://github.com/user-attachments/assets/4ddfbdfd-25fc-4ee0-bc07-c7ad82072261)


### ✅ **Goals Achieved by the Script:**

1. Create a folder named `CSC2244 Marks Exam` on the desktop.
2. Inside `CSC2244`, create folders: `practical`, `theory`, and `exam papers`.
3. Inside each, create dummy files with `.txt`, `.docx`, and `.pptx` extensions.
4. Create two Excel files on the desktop and move them into a folder named `Marks`.
5. Copy all content from `Marks` into `Exam`.
6. Hide the `Exam` folder.

---

### ✅ **Corrected Script:**

```bat
@echo off

:: Navigate to Desktop
cd /d "%USERPROFILE%\Desktop"

:: Create the folder structure
mkdir "CSC2244 Marks Exam"
cd "CSC2244 Marks Exam"
mkdir CSC2244
cd CSC2244
mkdir practical theory "exam papers"

:: Create files in practical folder
cd practical
type nul > practical.txt
type nul > practical.docx
type nul > practical.pptx

:: Create files in theory folder
cd ..
cd theory
type nul > theory.txt
type nul > theory.docx
type nul > theory.pptx

:: Create files in exam papers folder
cd ..
cd "exam papers"
type nul > exam.txt
type nul > exam.docx
type nul > exam.pptx

:: Go back to desktop
cd /d "%USERPROFILE%\Desktop"

:: Create and move marks files
type nul > "Icae Marks.xlsx"
type nul > "Final Exam Marks.xlsx"
mkdir Marks
move "Icae Marks.xlsx" Marks
move "Final Exam Marks.xlsx" Marks

:: Copy contents of Marks to Exam folder
xcopy Marks "CSC2244 Marks Exam\Exam" /E /I

:: Hide the Exam folder
attrib +h "CSC2244 Marks Exam\Exam"
```

---

### 🔍 Notes:

* `type nul > filename` is more reliable than `echo. >` for creating empty files.
* Enclose folder and file names with spaces in **quotes**.
* Added `/d` in `cd` to ensure it works across different drives.
* Created the `Marks` folder before using `move`.
* The original script attempted to copy from `Marks Exam`, which didn’t exist. This version uses a clearly named `Exam` folder.



---

### ✅ **Improved Script:**

```bash
#!/bin/bash

# Read user input
read -p "Enter String_1: " str1
read -p "Enter String_2: " str2

# Get string lengths
len1=${#str1}
len2=${#str2}

# Compare lengths and display result
if [ "$len1" -gt "$len2" ]; then
    echo "\"$str1\" is longer than \"$str2\""
elif [ "$len1" -lt "$len2" ]; then
    echo "\"$str2\" is longer than \"$str1\""
else
    echo "Both strings are of equal length"
fi
```

---

### 🔍 Optional Enhancements:

1. **Handle empty input:**

   ```bash
   if [ -z "$str1" ] || [ -z "$str2" ]; then
       echo "Both strings must be non-empty."
       exit 1
   fi
   ```

2. **Ignore leading/trailing spaces:**
   Use `str1=$(echo "$str1" | xargs)` to trim spaces if needed.

