#include <iostream>
#include "image.h"



// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image& im, int x, int y, int ch) {
      // TODO: calculate and return the index
      // get the location of the pixel
      // x: Column
      // y: Row
      // ch: channel
      // data[ch0: 0, ..., 65535,
      //      ch1: 65536, ..., 131,071
      //      ch2: 131,072, ..., 196,607]
      int width = im.w;
      int height = im.h;
      return x + width * y + (width * height * ch);
}

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image& im, int x, int y, int ch) {
      // TODO: clamp the coordinates and return the correct pixel value
      // perform padding to the image
    int width = im.w;
    int height = im.h;

    //    int channel = im.c;
    // x
    //        if(x < 0)
    //            x = 0;
    //        else if(x >= width)
    //            x = width - 1;
    //        // y
    //        if(y < 0)
    //            y = 0;
    //        else if(y >= height)
    //            y = height - 1;
    //
    //    // channel
    //    if(ch < 0)
    //        ch = 0;
    //    else if(ch > 3)
    //        ch = 3;

    x = x < 0 ? 0 : x;
    x = x > width-1 ? width - 1 : x;
    y = y < 0 ? 0 : y;
    y = y > height-1 ? height - 1 : y;
    ch = ch < 0 ? 0 : ch;
    ch = ch > 3 ? 3 : ch;
    //    float pixel = im(x, y, ch);
    //    std::cout << pixel;

//    cout << "x: " << x << "y:" << y;

    return im(x, y, ch);
}


// HW0 #1
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image& im, int x, int y, int c, float value) {
      // TODO: Only set the pixel to the value if it's inside the image

      int width = im.w;
      int height = im.h;
      int channel = im.c;

      if(x >= 0 && x < width && y >= 0 && y < height && c >= 0 && c < channel) {
          im(x, y, c) = value;
      }
  
}



// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image& to, const Image& from) {
    // allocating data for the new image
    to.data = (float*)calloc(from.w*from.h*from.c,sizeof(float));
    to.c = from.c; // copy channel

    // TODO: populate the remaining fields in 'to' and copy the data
    // You might want to check how 'memcpy' function works

    //  NOT_IMPLEMENTED();
    to.w = from.w; // copy weight
    to.h = from.h; // copy height

    memcpy(to.data, from.data, to.w*to.h*to.c*sizeof(float));
}
