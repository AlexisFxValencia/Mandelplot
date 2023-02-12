#include "EasyBMP.hpp"
#include <iostream>
#include <vector>
#include "Mandelbrot.hpp"
#include "omp.h"
using namespace std;


int main(int argc, char *argv[])
{
  double t_start = omp_get_wtime();
  Mandelbrot mdlb = Mandelbrot();
  mdlb.parse_params(argc, argv);
  EasyBMP::RGBColor white(255, 255, 255);
  EasyBMP::RGBColor black(0, 0, 0); 
  
  string img_name = "mandelbrot_" + to_string(mdlb.N_pixels) + "_" + to_string(mdlb.max_iteration) + ".bmp";
  EasyBMP::Image img(mdlb.N_pixels, mdlb.N_pixels, img_name, white);
  cout << "Mandelbrot generation's name : " << img_name << endl;
  

  for (int y = 0; y < mdlb.N_pixels; ++y) {
    for (int x = 0; x < mdlb.N_pixels; ++x) {
      float x_normalized = ((float)x/(float)mdlb.N_pixels)*mdlb.width + mdlb.center.x - mdlb.width/2;
      float y_normalized = ((float)(mdlb.N_pixels-y)/(float)mdlb.N_pixels)*mdlb.width + mdlb.center.y - mdlb.width/2;
      int iteration = mdlb.mandelbrot_finite(x_normalized, y_normalized, mdlb.max_iteration);
      if (iteration >= mdlb.max_iteration){
        img.SetPixel(x, y, black);
      } else{
        float x_color = (float)iteration/(float)mdlb.max_iteration;
        vector<int> colors = mdlb.choose_color(x_color);
        EasyBMP::RGBColor custom_color(colors[0], colors[1], colors[2]);
        img.SetPixel(x, y, custom_color);
      }      
    }
  }
  img.Write();
  double t_end = omp_get_wtime();
  printf("image generated in %f seconds.\n", t_end - t_start); 

  return 0;
}