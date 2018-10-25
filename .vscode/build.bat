set PATH=%PATH:C:\Program Files\Git\usr\bin;=%
set SFML_DIR=..\SFML
xcopy /y ..\SFML\bin\*.dll .\
xcopy /y ..\assets .\

cmake -G "MinGW Makefiles" ..
mingw32-make


