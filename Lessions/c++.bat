
@echo off

:loop 
if "%1"=="--external" ( 
    goto external
) else if "%1"=="-e" ( 
    goto external 
) else if "%1"=="--code" ( 
    goto code 
) else if "%1"=="-c" ( 
    goto code 
) else if "%1"=="-h" ( 
    goto help 
) else if "%1"=="--help" ( 
    goto help
) else if "%1" neq "" ( 
    goto help 
) else ( 
    goto exit 
)
goto exit

:external
start D:\useful\Books\C++.pdf
shift
goto loop

:code
powershell code D:\useful\Books\C++.pdf
shift
goto loop

:help
echo. 
echo To open pdf(Book) of C++ written by Ulla Kirch-Prinz $ Peter Prinz
echo. 
echo C++.bat [options]
echo. 
echo -e --external              To run open pdf in your default pdf reader
echo -c --code                  To run pdf in code
echo -h --help                  To see this menue
echo.
shift
goto loop

:exit
