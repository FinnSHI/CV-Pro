#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "image.h"
#include <iostream>

using namespace std;

//#define M_PI 3.14159265358979323846



// ------------------------ Please fill the following functions between the two cutting lines ------------------------

// Image& im: image to L1-normalize
Image l1_normalize(const Image& im) {

    Image ret(im.w, im.h, im.c);

    // TODO: Normalize each channel
    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return ret;
}


// int w: size of filter
// returns the filter Image of size WxW
Image make_box_filter(int w) {
    assert(w%2); // w needs to be odd

    Image filter(w,w,1);

    // TODO: Implement the filter
    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return filter;
}

// pad the image with zero on the borders
Image padding_image(const Image& im, const Image& filter) {

    // TODO: Implement the padding, tips: padding size = (filter size - stride size)/2
    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();




    //  TODO: Make sure to return the new image after convolution. This is just a placeholder
    //  TODO: return the new image
    return Image(1, 1, 1); // This is just a placeholder

    // TODO: Your codes stop here
}



// const Image&im: input image
// const Image& filter: filter to convolve with
// bool preserve: whether to preserve number of channels
// returns the convolved image
Image convolve_image(const Image& im, const Image& filter, bool preserve) {
    assert(filter.c==1);
    // TODO: Make sure you set the sizes of ret properly. Use ret=Image(w,h,c) to reset ret
    // TODO: Do the convolution operator
    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();




    //  TODO: Make sure to return the new image after convolution. This is just a placeholder
    //  TODO: return the new image
    return Image(1, 1, 1); // This is just a placeholder

    // TODO: Your codes stop here
}


// returns basic 3x3 high-pass filter
Image make_highpass_filter() {

    Image filter(3,3,1);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return filter;
}


// returns basic 3x3 sharpen filter
Image make_sharpen_filter() {
    Image filter(3,3,1);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return filter;
}


// returns basic 3x3 emboss filter
Image make_emboss_filter() {
    Image filter(3,3,1);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();



    // TODO: Your codes stop here
    return filter;
}

// ------------------------ Please fill the above functions between the two cutting lines ------------------------




























// HW1 #2.4
// float sigma: sigma for the gaussian filter
// returns basic gaussian filter
Image make_gaussian_filter(float sigma)
  {
  // TODO: Implement the filter
  NOT_IMPLEMENTED();
  
  return Image(1,1,1);
  
  }


// HW1 #3
// const Image& a: input image
// const Image& b: input image
// returns their sum
Image add_image(const Image& a, const Image& b)
  {
  assert(a.w==b.w && a.h==b.h && a.c==b.c); // assure images are the same size
  
  // TODO: Implement addition
  NOT_IMPLEMENTED();
  
  return a;
  
  }

// HW1 #3
// const Image& a: input image
// const Image& b: input image
// returns their difference res=a-b
Image sub_image(const Image& a, const Image& b)
  {
  assert(a.w==b.w && a.h==b.h && a.c==b.c); // assure images are the same size
  
  // TODO: Implement subtraction
  NOT_IMPLEMENTED();
  
  return a;
  
  }

// HW1 #4.1
// returns basic GX filter
Image make_gx_filter()
  {
  // TODO: Implement the filter
  NOT_IMPLEMENTED();
  
  return Image(1,1,1);
  }

// HW1 #4.1
// returns basic GY filter
Image make_gy_filter()
  {
  // TODO: Implement the filter
  NOT_IMPLEMENTED();
  
  return Image(1,1,1);
  }

// HW1 #4.2
// Image& im: input image
void feature_normalize(Image& im)
  {
  assert(im.w*im.h); // assure we have non-empty image
  
  // TODO: Normalize the features for each channel
  NOT_IMPLEMENTED();
  
  }


// Normalizes features across all channels
void feature_normalize_total(Image& im)
  {
  assert(im.w*im.h*im.c); // assure we have non-empty image
  
  int nc=im.c;
  im.c=1;im.w*=nc;
  
  feature_normalize(im);
  
  im.w/=nc;im.c=nc;
  
  }


// HW1 #4.3
// Image& im: input image
// return a pair of images of the same size
pair<Image,Image> sobel_image(const Image& im)
  {
  // TODO: Your code here
  NOT_IMPLEMENTED();
  
  return {im,im};
  }


// HW1 #4.4
// const Image& im: input image
// returns the colorized Sobel image of the same size
Image colorize_sobel(const Image& im)
  {
  
  // TODO: Your code here
  NOT_IMPLEMENTED();
  
  return im;
  }


// HW1 #4.5
// const Image& im: input image
// float sigma1,sigma2: the two sigmas for bilateral filter
// returns the result of applying bilateral filtering to im
Image bilateral_filter(const Image& im, float sigma1, float sigma2)
  {
  Image bf=im;
  
  // TODO: Your bilateral code
  NOT_IMPLEMENTED();
  
  return bf;
  }



// HELPER MEMBER FXNS

void Image::feature_normalize(void) { ::feature_normalize(*this); }
void Image::feature_normalize_total(void) { ::feature_normalize_total(*this); }
void Image::l1_normalize(void) { ::l1_normalize(*this); }

Image operator-(const Image& a, const Image& b) { return sub_image(a,b); }
Image operator+(const Image& a, const Image& b) { return add_image(a,b); }
