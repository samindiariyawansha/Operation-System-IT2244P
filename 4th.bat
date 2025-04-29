@echo off

cls
setlocal EnableDelayedExpansion

set /P year=Enter your birth year: 

for /F "tokens=2 delims==" %%Y in ('wmic os get LocalDateTime /value ^| find "LocalDateTime"') do set currentYear=%%Y
set currentYear=!currentYear:~0,4!

set /A age=%currentYear% - %year%

echo Age: %age% years old.

pause
