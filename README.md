
![Screenshot (103)](https://github.com/user-attachments/assets/a3ab2def-456f-4b43-8df2-9b6985c4b34b)
![Screenshot (104)](https://github.com/user-attachments/assets/059b775c-3364-4874-b588-c1e5a555d9c1)
![Screenshot (105)](https://github.com/user-attachments/assets/79944d63-75fa-4cc8-9400-e510d7e4a2b8)
![Screenshot 2025-05-28 181817](https://github.com/user-attachments/assets/22e62687-a472-4f01-a45b-1796cd798012)
![Screenshot (106)](https://github.com/user-attachments/assets/46e6538a-6602-43ee-99da-524d77b1e3ef)
![Screenshot (107)](https://github.com/user-attachments/assets/9a0aacb0-779d-43b0-b0d4-95966c735289)
![Screenshot (108)](https://github.com/user-attachments/assets/074fccc7-6d04-462d-b444-3b972ac3c7f3)



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
