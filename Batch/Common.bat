rem This is a file with reusable batch scripts

rem getLen and lenLoop are one function!
rem Get string length arg1 string, arg2 length var
:getLen
setlocal enabledelayedexpansion

:lenLoop
if not "!%1:~%len%!"=="" set /A len += 1 & goto :lenLoop
endlocal & set /A %2=%len%-1
exit /b


rem Convert relative path to absolute path
rem Args: relative_path, absolute_path_var
:getAbsolute
pushd %1%
set "%2=%cd%"
popd
exit /b


rem Quotation marks from string
rem Args: path, path_var
:remQuot
setlocal enabledelayedexpansion
set "s=""
set "text=%1%"

if "!s!" == "!text:~0,1!" (
    set "text=%text:~1,-1%"
) else (
    set "text=%text%"
)
endlocal & set "%~2=%text%"
exit /b


rem Depends on :getLen, :remQuot and :getAbsolute!
rem Copy all files in dir (retaining folder structure)
rem args: source_dir, target_dir
:copyAllFiles
setlocal enabledelayedexpansion

set "s=""
set /a lenOff=0

set "from=%1%"
set "to=%2%"

call :getAbsolute %from% from
call :getAbsolute %to% to

set /a length=0
call :getLen to length

echo %from%
echo %to%
set /a "length=%length%-%lenOff%"

for /r "%from%" %%f in (*) do (
set "absPath=%%~pf"
if not exist "%to%\!absPath:~%length%!"  mkdir "%to%\!absPath:~%length%!"
copy "%%f" "%to%\!absPath:~%length%!\%%~nxf"
)

endlocal
exit /b


rem For files in dir(including sub directories)
for /r %directory% %%f in (*) do (

    rem Get file path: %%f
    rem Get name: %%~nf
    rem Get extension: %%~xf
    rem Get name with extension: %%~nxf
    rem Get path: %%~pf
)


:end
pause