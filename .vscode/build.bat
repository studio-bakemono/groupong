set PATH=%PATH:C:\Program Files\Git\usr\bin;=%
set SFML_DIR=..\SFML

cmake -G "MinGW Makefiles" ..
mingw32-make

xcopy /y ..\SFML\bin\*.dll .\
