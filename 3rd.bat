@echo off
set /P num = Enter the number:
set /A mod = %num% %% 2
if %mod%==0 (echo this is even number) else (echo this is odd number)
pause