#include "Mandelbrot.hpp"

Mandelbrot::Mandelbrot(){
    max_iteration = 100;
    center = Point(-0.5, 0.0);
    width = 2.0;
    N_pixels = 512;
}

int Mandelbrot::mandelbrot_finite(float x_0, float y_0, int max_iteration){
  float x = 0.0;
  float y = 0.0;
  int iteration = 0;
  while (x*x + y*y <= 4.0 && iteration < max_iteration){
    float x_temp = x*x - y*y + x_0;
    y = 2*x*y + y_0;
    x = x_temp;
    iteration++;
  }
  return iteration;
}


vector<int> Mandelbrot::choose_color(float x_color){
  // cf. https://stackoverflow.com/questions/20792445/calculate-rgb-value-for-a-range-of-values-to-create-heat-map  
  
  int blue_neg = (int)(255 * (1 - 2 * x_color));
  int blue =  max(blue_neg, 0);
  int green;
  if (x_color <=0.5){          
    green = (int)(2*x_color*255);
  } else{
    green = (int)(-2*(x_color - 1)*255);
  }
  int red_neg = (int)(255 * (2 * x_color - 1));
  int red = max(red_neg, 0);
  vector<int> colors;
  colors.push_back(red);
  colors.push_back(green);
  colors.push_back(blue);
  return colors;
}

void Mandelbrot::parse_params(int argc, char *argv[]){
    int opt;
  while((opt = getopt(argc, argv, "hs:i:x:y:w:")) != -1) 
  { 
      switch(opt) 
      { 
          case 'h':
            cout << endl;
            printf("-s: Size of the image in pixels (defines the width and the height of the image as it is a square). \n");
            printf("-i: Maximum number of iterations of the mandelbrot process. \n");
            printf("-x: x-coordinate of the view's center. Default parameter is %f \n", center.x);
            printf("-y: y-coordinate of the view's center. Default parameter is %f \n", center.y);            
            printf("-w: width of the view. Default parameter is %f \n", width);
            cout << endl;
            break;
          case 's': 
            N_pixels = stoi(optarg);
            printf("Image size is set to %i pixels \n", N_pixels);
            break;
          case 'i': 
            max_iteration = stoi(optarg);
            printf("Maximum number of iterations isset to %i \n", max_iteration);
            break;
          case 'x': 
            center.x = stof(optarg);
            printf("x-coordinate of the view's center is set to %f \n", center.x);
            break;
          case 'y': 
            center.y = stof(optarg);
            printf("x-coordinate of the view's center is set to %f \n", center.y);
            break;
          case 'w': 
            width = stof(optarg);
            printf("The width of the view is set to %f \n", width);
            break;
      } 
  }     
  // optind is for the extra arguments
  // which are not parsed
  for(; optind < argc; optind++){     
      printf("extra arguments: %s\n", argv[optind]); 
  }
}