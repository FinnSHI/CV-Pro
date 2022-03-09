#include <cmath>
#include "image.h"
#include <iostream>
#include <string>

using namespace std;


// ------------------------ Please fill the following functions between the two cutting lines ------------------------


// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image nearest_resize(const Image& im, int w, int h) {
    Image ret(w,h,im.c);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return ret;
}


// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image nearest_resize_adaptive(const Image& im, int w, int h) {
    Image ret(w,h,im.c);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return ret;
}


// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image bilinear_resize(const Image& im, int w, int h) {
    Image ret(w, h,im.c);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return ret;
}


// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image bilinear_resize_adaptive(const Image& im, int w, int h) {
    Image ret(w, h,im.c);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return ret;
}

// ------------------------ Please fill the above functions between the two cutting lines ------------------------






































// float x,y: inexact coordinates
// int c: channel
// returns the nearest neighbor to pixel (x,y,c)
float Image::pixel_nearest(float x, float y, int c) const
  {
  // Since you are inside class Image you can
  // use the member function pixel(a,b,c)
  
  // TODO: Your code here
  
  NOT_IMPLEMENTED();
  
  
  return 0;
  }


// float x,y: inexact coordinates
// int c: channel
// returns the bilinearly interpolated pixel (x,y,c)
float Image::pixel_bilinear(float x, float y, int c) const
  {
  // Since you are inside class Image you can
  // use the member function pixel(a,b,c)
  
  
  // TODO: Your code here
  
  NOT_IMPLEMENTED();
  
  
  return 0;
  }




