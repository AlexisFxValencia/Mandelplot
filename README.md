# Mandelplot
a C++ command line program to generate mandelbrot images.

  ![mandelbrot_8000_50](https://user-images.githubusercontent.com/84465552/218670477-5d80f7e5-6488-4e05-95cb-c8f3096cac2a.jpeg)

## HOW TO COMPILE IT (only g++ tested):
g++ used to compile it like this :   </br>
g++ -fopenmp -o mandelplot *.cpp  </br>
-fopenmp option is used to parallelize it with openmp.

## HOW USE IT (eg on Linux) :
a typical command : </br>
./mandelplot -s 1024 -i 50 </br>
s : for the size in pixel of the width and height of the generated image. </br>
i : number of iterations according to the Mandelbrot algorithm.

please use ./mandelplot -h to get help.


## INTERESTING POINTS
./mandelplot -x -0.749 -y 0.1 -w 0.005 </br>
![mandelbrot_512_100](https://user-images.githubusercontent.com/84465552/218671610-0fd697e4-6fac-4dcf-ac8b-2e358a9e9307.jpg)
