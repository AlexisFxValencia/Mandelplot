# Mandelplot
a C++ command line program to generate mandelbrot images.

  ![mandelbrot_8000_50](https://user-images.githubusercontent.com/84465552/218670477-5d80f7e5-6488-4e05-95cb-c8f3096cac2a.jpeg)

## HOW TO COMPILE IT :
g++ used to compile it like this :   </br>
g++ -fopenmp -o mandelbrot *.cpp  </br>
-fopenmp option is used to parallelize it with openmp.

## HOW USE IT :
a typical command : </br>
./mandelplot -s 1024 -i 50 </br>
s : for the size in pixel of the width and height of the enerated image. </br>
i : number of iterations according to the Mandelbrot algorithm.

