#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>

#include "image.h"

using namespace std;

// HW0 #3
// const Image& im: input image
// return the corresponding grayscale image
Image rgb_to_grayscale(const Image& im)
  {
  assert(im.c == 3); // only accept RGB images
  Image gray(im.w,im.h,1); // create a new grayscale image (note: 1 channel)
  
  // TODO: calculate the pixels of 'gray'
  for (int i=0; i<im.w; i++) {
      for (int j=0; j<im.h; j++) {
          float R = im(i, j, 0);
          float G = im(i, j, 1);
          float B = im(i, j, 2);
          gray(i, j, 0) = 0.299*R + 0.587*G + .114*B;
      }
  }


  // NOT_IMPLEMENTED();
  
  return gray;
  }



// Example function that changes the color of a grayscale image
Image grayscale_to_rgb(const Image& im, float r, float g, float b)
  {
  assert(im.c == 1);
  Image rgb(im.w,im.h,3);
  
  for(int q2=0;q2<im.h;q2++)for(int q1=0;q1<im.w;q1++)
    {
    rgb(q1,q2,0)=r*im(q1,q2);
    rgb(q1,q2,1)=g*im(q1,q2);
    rgb(q1,q2,2)=b*im(q1,q2);
    }
  
  return rgb;
  }




// HW0 #4
// Image& im: input image to be modified in-place
// int c: which channel to shift
// float v: how much to shift
void shift_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: shift all the pixels at the specified channel
  for (int i=0; i<im.w; i++) {
      for (int j=0; j<im.h; j++) {
          float value = im(i, j, c) + v;
          im(i, j, c) = value;
      }
  }
  
  // NOT_IMPLEMENTED();
  
  }

// HW0 #8
// Image& im: input image to be modified in-place
// int c: which channel to scale
// float v: how much to scale
void scale_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: scale all the pixels at the specified channel
  for (int i=0; i<im.w; i++) {
      for (int j=0; j<im.c; j++) {
          float value = im(i, c, j) + v;
          im(i, c, j) = value;
      }
  }

  
  // NOT_IMPLEMENTED();
  
  }


// HW0 #5
// Image& im: input image to be modified in-place
void clamp_image(Image& im)
  {
  // TODO: clamp all the pixels in all channel to be between 0 and 1
  for (int c=0; c<im.c; c++) {
      for (int i=0; i<im.w; i++) {
          for (int j=0; j<im.h; j++) {
              float v = im(i, j, c);
              if (v<0.0)
                  v = 0.0;
              if (v>1.0)
                  v = 1.0;
              im(i, j, c) = v;
          }
      }
  }
  
   // NOT_IMPLEMENTED();
  
  }

// These might be handy
float max(float a, float b, float c)
  {
  return max({a,b,c});
  }

float min(float a, float b, float c)
  {
  return min({a,b,c});
  }


// HW0 #6
// Image& im: input image to be modified in-place
void rgb_to_hsv(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from RGB format to HSV format
  for (int i=0; i<im.w; i++) {
      for (int j=0; j<im.h; j++) {
          float R = im(i, j, 0);
          float G = im(i, j, 1);
          float B = im(i, j, 2);

          float V = max(R,G,B);
          float m = min(R,G,B);
          float C = V - m;
          float S = 0.0f;
          if (V == 0.0f)
              S = 0.0f;
          else
              S = C / V;

          float H = 0.0;
          if (C == 0.0f)
              H = 0.0f;
          else {
              float h = 0.0f;
              if (V == R)
                  h = (G-B)/C;
              else if (V == G)
                  h = (B-R)/C + 2.0f;
              else if (V == B)
                  h = (R-G)/C + 4.0f;
              else
                  h = 0.0f;


              if (h<0.0f)
                  H = h/6.0f+1.0f;
              else
                  H = h/6.0f;
          }

          im(i, j, 0) = H;
          im(i, j, 1) = S;
          im(i, j, 2) = V;
      }
  }
  // NOT_IMPLEMENTED();
  
  }

// HW0 #7
// Image& im: input image to be modified in-place
void hsv_to_rgb(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from HSV format to RGB format

  // Given the H, S, V channels of an image:
      for (int i=0; i<im.w; i++) {
          for (int j=0; j<im.h; j++) {
              float H = im(i, j, 0);
              float S = im(i, j, 1);
              float V = im(i, j, 2);

              float C = V * S;
              // X = C * (1 - abs((6*H fmod 2) - 1))
              float X = fmod(6.0*H, 2.0);
              X = abs(X-1);
              X = C * (1-X);
              float m = V - C;

              float R = 0.0;
              float G = 0.0;
              float B = 0.0;
              if (0.0f<= H < (1.0f/6.0f)) {
                  R = C;
                  G = X;
                  B = 0.0;
              }
              else if ((1.0f/6.0f)<= H < (2.0f/6.0f)) {
                  R = X;
                  G = C;
                  B = 0.0;
              }
              else if ((2.0f/6.0f)<= H < (3.0f/6.0f)) {
                  R = 0.0;
                  G = C;
                  B = X;
              }
              else if ((3.0f/6.0f)<= H < (4.0f/6.0f)) {
                  R = 0;
                  G = X;
                  B = C;
              }
              else if ((4.0f/6.0f)<= H < (5.0f/6.0f)) {
                  R = X;
                  G = 0.0;
                  B = C;
              }
              else if ((5.0f/6.0f)<= H < 1.0f) {
                  R = C;
                  G = 0.0;
                  B = X;
              }
              else {
                  R = 0.0;
                  G = 0.0;
                  B = 0.0;
              }


              im(i, j, 0) = R+m;
              im(i, j, 1) = G+m;
              im(i, j, 2) = B+m;
          }
      }

  // NOT_IMPLEMENTED();
  
  }

// HW0 #9
// Image& im: input image to be modified in-place
void rgb_to_lch(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from RGB format to LCH format
  
  
  NOT_IMPLEMENTED();
  
  }

// HW0 #9
// Image& im: input image to be modified in-place
void lch_to_rgb(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from LCH format to RGB format
  
  NOT_IMPLEMENTED();
  
  }



// Implementation of member functions
void Image::clamp(void) { clamp_image(*this); }
void Image::shift(int c, float v) { shift_image(*this,c,v); }
void Image::scale(int c, float v) { scale_image(*this,c,v); }

void Image::HSVtoRGB(void) { hsv_to_rgb(*this); }
void Image::RGBtoHSV(void) { rgb_to_hsv(*this); }
void Image::LCHtoRGB(void) { lch_to_rgb(*this); }
void Image::RGBtoLCH(void) { rgb_to_lch(*this); }
