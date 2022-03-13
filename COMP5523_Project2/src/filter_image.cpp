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
    float sum_0 = 0;
    float sum_1 = 0;
    float sum_2 = 0;
    for(int k = 0; k < im.c; k++) {
        for(int i = 0; i < im.w; i++)
            for(int j = 0; j < im.h; j++) {
                if(k == 0) sum_0 += im(i, j, k);
                else if(k == 1) sum_1 += im(i, j, k);
                else if(k == 2) sum_2 += im(i, j, k);
            }
    }

//    cout << sum_0 << endl;
//    cout << sum_1 << endl;
//    cout << sum_2 << endl;

    for(int k = 0; k < im.c; k++)
        for(int i = 0; i < im.w; i++)
            for(int j = 0; j < im.h; j++) {
                if(k == 0) ret(i, j, k) = im(i, j, k) / sum_0;
                else if(k == 1) ret(i, j, k) = im(i, j, k) / sum_1;
                else if(k == 2) ret(i, j, k) = im(i, j, k) / sum_2;
            }
    // TODO: Your codes stop here
//    float testValue = 0;
//    for(int i = 0; i < im.w; i++)
//        for(int j = 0; j < im.h; j++) {
//            testValue += ret(i, j, 0);
//        }
//    cout << testValue << endl;
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
    float sum = w * w;
    for(int i = 0; i < w; i++)
        for(int j = 0; j < w; j++) {
            filter(i, j, 0) = 1.0 / sum;
        }
    // TODO: Your codes stop here
    return filter;
}

// pad the image with zero on the borders
Image padding_image(const Image& im, const Image& filter) {

    // TODO: Implement the padding, tips: padding size = (filter size - stride size)/2
    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();

    /*
     * origin image size: n*n
     * filter size: f*f
     * image size after convolution: (n-f+1)*(n-f+1)
     *
     * n+2p-f+1 = n
     * p = (f-1)/2
    */
    int f_size = filter.w;
    int p_size = (f_size - 1)/2;
    int ret_w = im.w + 2 * p_size;
    int ret_h = im.h + 2 * p_size;
    int ret_c = im.c;
    Image ret = Image(ret_w, ret_h, ret_c);
    for(int k = 0; k < ret.c; k++)
        for(int i = 0; i < ret.w; i++)
            for(int j = 0; j < ret.h; j++) {
                if(i < p_size || i > im.w + p_size || j < p_size || j > im.h + p_size)
                    ret(i, j, k) = 0;
                else if(i > p_size && i < im.w + p_size && j > p_size && j < im.h + p_size)
                    ret(i, j, k) = im.clamped_pixel(i - p_size, j - p_size, k);
            }


    //  TODO: Make sure to return the new image after convolution. This is just a placeholder
    //  TODO: return the new image
//    return Image(1, 1, 1); // This is just a placeholder
    return ret;
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
    Image ret;
    float q = 0;
    if(preserve) {
        ret = Image(im.w, im.h, im.c);
        for(int c = 0; c < im.c; c++)
            for(int i = 0; i < im.w; i++)
                for(int j = 0; j < im.h; j++) {
                    q = 0;
                    for(int w = 0; w < filter.w; w++)
                        for(int h = 0; h < filter.h; h++) {
                            int x = i - filter.w/2 + w;
                            int y = j - filter.h/2 + h;
                            q += filter(w, h, 0) * im.clamped_pixel(x, y, c);

                        }
//                    cout << q << endl;
                    ret(i, j, c) = q;
                }
    }

    if(!preserve) {
        ret = Image(im.w, im.h, 1);
        for(int i = 0; i < im.w; i++)
            for(int j = 0; j < im.h; j++) {
                q = 0;
                for (int c = 0; c < im.c; c++)
                    for (int w = 0; w < filter.w; w++)
                        for (int h = 0; h < filter.h; h++) {
                            int x = i - filter.w / 2 + w;
                            int y = j - filter.h / 2 + h;
                            q += filter(w, h, 0) * im.clamped_pixel(x, y, c);
                        }
                ret(i, j, 0) = q;
            }
    }

    //  TODO: Make sure to return the new image after convolution. This is just a placeholder
    //  TODO: return the new image
//    return Image(1, 1, 1); // This is just a placeholder
    return ret;
    // TODO: Your codes stop here
}


// returns basic 3x3 high-pass filter
Image make_highpass_filter() {

    Image filter(3,3,1);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();
    filter(0, 0, 0) = 0;
    filter(0, 1, 0) = -1;
    filter(0, 2, 0) = 0;
    filter(1, 0, 0) = -1;
    filter(1, 1, 0) = 4;
    filter(1, 2, 0) = -1;
    filter(2, 0, 0) = 0;
    filter(2, 1, 0) = -1;
    filter(2, 2, 0) = 0;

    // TODO: Your codes stop here
    return filter;
}


// returns basic 3x3 sharpen filter
Image make_sharpen_filter() {
    Image filter(3,3,1);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();
    filter(0, 0, 0) = 0;
    filter(0, 1, 0) = -1;
    filter(0, 2, 0) = 0;
    filter(1, 0, 0) = -1;
    filter(1, 1, 0) = 5;
    filter(1, 2, 0) = -1;
    filter(2, 0, 0) = 0;
    filter(2, 1, 0) = -1;
    filter(2, 2, 0) = 0;

    // TODO: Your codes stop here
    return filter;
}


// returns basic 3x3 emboss filter
Image make_emboss_filter() {
    Image filter(3,3,1);

    // TODO: Your codes begin here
    //  NOT_IMPLEMENTED();
    filter(0, 0, 0) = -2;
    filter(0, 1, 0) = -1;
    filter(0, 2, 0) = 0;
    filter(1, 0, 0) = -1;
    filter(1, 1, 0) = 1;
    filter(1, 2, 0) = 1;
    filter(2, 0, 0) = 0;
    filter(2, 1, 0) = 1;
    filter(2, 2, 0) = 2;


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
