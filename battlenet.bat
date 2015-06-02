@echo off
prompt :

set outfile="C:\Users\Daniel\.bin\battlenet_log.txt"

:: Launch Battle.net and WKey Disabler
echo Launching Battle.net... > %outfile%
start "" "C:\Program Files (x86)\Battle.net\Battle.net Launcher.exe"
start "" "C:\Program Files (x86)\WKey Disabler\WKey Disabler.exe"

echo Waiting for WoW to be launched... >> %outfile%
:loop1
:: Check if wow is running
tasklist /fi "imagename eq Wow-64.exe" |find ":" > nul
:: If it is, goto second loop
if errorlevel 1 goto :break1
ping -n 6 127.0.0.1>NUL
goto :loop1

:break1
echo Waiting for WoW to close... >> %outfile%

:loop2
:: Check if wow is running
tasklist /fi "imagename eq Wow-64.exe" |find ":" > nul
:: If it isn't, kill WKey Disabler
if not errorlevel 1 goto :break2
ping -n 6 127.0.0.1>NUL
goto :loop2

:break2
echo Killing WKey Disabler... >> %outfile%
taskkill /f /im "WKey Disabler.exe" >> %outfile%
