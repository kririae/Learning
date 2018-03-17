@echo off
:loop
pai2.exe>a.txt
gamma.exe<a.txt>b.txt
±©Á¦2.exe<a.txt>c.txt
fc b.txt c.txt
if errorlevel 1 pause
goto loop