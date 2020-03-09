mkdir build
cd build
del /q *.*
cmake .. -DCMAKE_TOOLCHAIN_FILE=../pgm.cmake -G"Unix Makefiles"
make
pause
cd ..
libkov
copy ytzy_v201cn_o.rom fbas\roms\ytzyws_prg.rom
cd fbas\roms
"C:\Program Files\WinRAR\winrar.exe" a -r kovytzyws.zip ytzyws_prg.rom
cd ..
fbas -g kovytzyws -w -r 480*224