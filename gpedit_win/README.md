# Gpedit Windows
If you can’t find gpedit.msc (gpedit.msc not found error) on Windows 10.
You need  to make a gpedit_enabler.bat file: 

1 Create a new text file -> copy & paste the following content into it -> give it a name (like gpedit_enabler) and save it as a bat file.

@echo off

pushd "%~dp0"

 

dir /b %SystemRoot%\servicing\Packages\Microsoft-Windows-GroupPolicy-ClientExtensions-Package~3*.mum >List.txt

dir /b %SystemRoot%\servicing\Packages\Microsoft-Windows-GroupPolicy-ClientTools-Package~3*.mum >>List.txt

 

for /f %%i in ('findstr /i . List.txt 2^>nul') do dism /online /norestart /add-package:"%SystemRoot%\servicing\Packages\%%i"

pause

2.save file GPedit.bat

  File type to all

3. then run this file as administrator

# Resources
https://answers.microsoft.com/en-us/windows/forum/all/gpeditmsc-missing/cc1d05b2-457d-4aa6-839f-8136d0eddc35
