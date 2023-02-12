#include <vector>
#include "Point.hpp"
#include <iostream>
#include <unistd.h> 
using namespace std;

class Mandelbrot{
    public:
        int max_iteration;
        Point center;
        float width;
        int N_pixels;
        Mandelbrot();
        int mandelbrot_finite(float x_0, float y_0, int max_iteration);
        vector<int> choose_color(float x_color);       
        void parse_params(int argc, char *argv[]); 
        
};