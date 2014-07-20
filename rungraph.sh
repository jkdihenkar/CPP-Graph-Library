rm *.*~
rm *.o
rm jd
g++ -c functions.cpp
g++ gmain.cpp functions.o -o jd
