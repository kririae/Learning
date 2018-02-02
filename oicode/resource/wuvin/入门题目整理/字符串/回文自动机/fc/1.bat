@echo off
:ST
echo running...
sj.exe >1.in
a.exe <1.in >a.out
ans.exe <1.in >ans.out
fc a.out ans.out >nul
if not errorlevel 1 goto ST