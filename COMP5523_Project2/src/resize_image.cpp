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
    Image ret(w, h, im.c);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            for(int k = 0; k < im.c; k++)
                ret(i, j, k) = im(i/4, j/4, k);

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
    float w_radio = (float)im.w/w;
    float h_radio = (float)im.h/h;
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            for(int k = 0; k < im.c; k++)
                ret(i, j, k) = im.clamped_pixel(i * w_radio, j * h_radio, k);


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
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            for(int k = 0; k < im.c; k++) {
                float new_i = i/4.0;
                float new_j = j/4.0;
//                cout<<new_i<<" "<<new_j;
                int i_l = floorf(new_i);  // width_low
                int i_h = ceilf(new_i);  // width_high
                int j_l = floorf(new_j);  // height_low
                int j_h = ceilf(new_j);  // height_high
                float a_0 = new_i - i_l;
                float a_1 = 1 - a_0;
                float b_0 = j_h - new_j;
                float b_1 = 1 - b_0;
                ret(i, j, k) = a_1 * b_1 * im.clamped_pixel(i_l, j_h, k)
                        + a_0 * b_1 * im.clamped_pixel(i_h, j_h, k)
                        + a_1 * b_0 * im.clamped_pixel(i_l, j_l, k)
                        + a_0 * b_0 * im.clamped_pixel(i_h, j_l, k);
            }


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
    float w_radio = (float)im.w/w;
    float h_radio = (float)im.h/h;
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            for(int k = 0; k < im.c; k++) {
                int new_i = i * w_radio;
                int new_j = j * h_radio;
                int i_l = floorf(new_i);  // width_low
                int i_h = ceilf(new_i);  // width_high
                int j_l = floorf(new_j);  // height_low
                int j_h = ceilf(new_j);  // height_high
                float a_0 = new_i - i_l;
                float a_1 = 1 - a_0;
                float b_0 = j_h - new_j;
                float b_1 = 1 - b_0;
                ret(i, j, k) = a_1 * b_1 * im.clamped_pixel(i_l, j_h, k)
                               + a_0 * b_1 * im.clamped_pixel(i_h, j_h, k)
                               + a_1 * b_0 * im.clamped_pixel(i_l, j_l, k)
                               + a_0 * b_0 * im.clamped_pixel(i_h, j_l, k);
            }

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




