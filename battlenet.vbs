Dim WinScriptHost
Set WinScriptHost = CreateObject("WScript.Shell")
WinScriptHost.Run Chr(34) & "C:\Users\Daniel\.bin\battlenet.bat" & Chr(34), 0
Set WinScriptHost = Nothing
