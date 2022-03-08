#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>

#include "image.h"

using namespace std;

// HW0 #3
// const Image& im: input image
// return the corresponding grayscale image
Image rgb_to_grayscale(const Image& im) {
    assert(im.c == 3); // only accept RGB images
    Image gray(im.w,im.h,1); // create a new grayscale image (note: 1 channel)

    // TODO: calculate the pixels of 'gray'
    // i -> width
    // j -> height
    for(int i = 0; i < im.w; i++)
        for(int j = 0; j < im.h; j++)
            gray(i, j,0) = 0.299 * im(i, j, 0) + 0.587 * im(i, j, 1) + 0.114 * im(i, j, 2);

    return gray;
}



// Example function that changes the color of a grayscale image
Image grayscale_to_rgb(const Image& im, float r, float g, float b) {
    assert(im.c == 1); // only accept gray image
    Image rgb(im.w,im.h,3);

    for(int q2=0;q2<im.h;q2++)for(int q1=0;q1<im.w;q1++) {
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
void shift_image(Image& im, int c, float v) {
    assert(c>=0 && c<im.c); // needs to be a valid channel

    // TODO: shift all the pixels at the specified channel
    // i -> width
    // j -> height
    for(int i = 0; i < im.w; i++)
        for(int j = 0; j < im.h; j++) {
            im(i, j, c) = im(i, j, c) + v;
        }
}

// HW0 #8
// Image& im: input image to be modified in-place
// int c: which channel to scale
// float v: how much to scale
void scale_image(Image& im, int c, float v) {
    assert(c>=0 && c<im.c); // needs to be a valid channel

    // TODO: scale all the pixels at the specified channel
    for(int i = 0; i < im.w; i++)
        for(int j = 0; j < im.h; j++) {
            im(i, j, c) = im(i, j, c) * v;
        }

}


// HW0 #5
// Image& im: input image to be modified in-place
void clamp_image(Image& im) {
    // TODO: clamp all the pixels in all channel to be between 0 and 1
    // i -> width
    // j -> height
    // ch -> channel
    for(int ch = 0; ch < 3; ch++)
        for(int i = 0; i < im.w; i++)
            for(int j = 0; j < im.h; j++){
                im(i, j, ch) = (im(i, j, ch) < 0) ? 0 : im(i, j, ch);
                im(i, j, ch) = (im(i, j, ch) > 1) ? 1 : im(i, j, ch);
            }
}

// These might be handy
float max(float a, float b, float c) {
    return max({a,b,c});
}

float min(float a, float b, float c) {
    return min({a,b,c});
}


// HW0 #6
// Image& im: input image to be modified in-place
void rgb_to_hsv(Image& im) {
    assert(im.c==3 && "only works for 3-channels images");

    // TODO: Convert all pixels from RGB format to HSV format
    // Value: V = max(R, G, B)
    // Saturation: m = min(R, G, B), c = v - m, Saturation = C / V
    // Hue
    // R : im(i, j, 0)
    // G : im(i, j, 1)
    // B : im(i, j, 2)
    float value, saturation, hue, m, c, h;
    float r, g, b;
    for(int i = 0; i < im.w; i++)
        for(int j = 0; j < im.h; j++) {
            r = im(i, j, 0);
            g = im(i, j, 1);
            b = im(i, j, 2);
            // value
            value = max(r, g, b);
            // saturation
            m = min(r, g, b);
            c = value - m;
            saturation = (value == 0) ? 0 : c / value;
            // hue
            if(c != 0) {
                if(value == r) // V = R
                    h = (g - b) / c;
                else if(value == g) // V = G
                    h = (b - r) / c + 2;
                else if(value == b) // V = B
                    h = (r - g) / c + 4;
            } else
                h = 0;

            hue = (h<0) ? h/6+1 : h/6;
            while(hue < 0) hue++;

            im(i, j, 0) = hue;
            im(i, j, 1) = saturation;
            im(i, j, 2) = value;
        }
}

// HW0 #7
// Image& im: input image to be modified in-place
void hsv_to_rgb(Image& im) {
    assert(im.c==3 && "only works for 3-channels images");

    // TODO: Convert all pixels from HSV format to RGB format
    // Value: V = max(R, G, B)
    // Saturation: m = min(R, G, B), c = v - m, Saturation = C / V
    // Hue
    // R : im(i, j, 0)
    // G : im(i, j, 1)
    // B : im(i, j, 2)
    // im(i, j, 0) = hue;
    // im(i, j, 1) = saturation;
    // im(i, j, 2) = value;
    float hue, saturation, value;
    float c, x, m;
    float r, g, b;
    for(int i = 0; i < im.w; i++) {
        for (int j = 0; j < im.h; j++) {
            hue = im(i, j, 0);
            saturation = im(i, j, 1);
            value = im(i, j, 2);
            c = value * saturation; // C = V * S
            x = c * (1 - abs(fmod(6 * hue, 2) - 1)); // X = C * (1 - abs((6*H mod 2) - 1))
            m = value - c; // m = V - C
            if(hue >= 0 && hue< float(1)/float(6)) {
                r = c;
                g = x;
                b = 0;
            } else if(hue < float(2)/float(6)) {
                r = x;
                g = c;
                b = 0;
            } else if(hue < float(3)/float(6)) {
                r = 0;
                g = c;
                b = x;
            } else if(hue < float(4)/float(6)) {
                r = 0;
                g = x;
                b = c;
            } else if(hue < float(5)/float(6)) {
                r = x;
                g = 0;
                b = c;
            } else if(hue < 1) {
                r = c;
                g = 0;
                b = x;
            }

            im(i, j, 0) = r + m;
            im(i, j, 1) = g + m;
            im(i, j, 2) = b + m;
        }
    }
}

// HW0 #9
// Image& im: input image to be modified in-place
void rgb_to_lch(Image& im) {
    assert(im.c==3 && "only works for 3-channels images");

    // TODO: Convert all pixels from RGB format to LCH format

    NOT_IMPLEMENTED();

//    float x, y, z;
//    for(int i = 0; i < im.w; i++)
//        for(int j = 0; j < im.h; j++) {
//            x = 0.412453 * r + 0.357580 * g + 0.180423 * b
//            y = 0.212671 * r + 0.715160 * g + 0.072169 * b
//            z = 0.019334 * r + 0.119193 * g + 0.950227 * b
//        }
}

// HW0 #9
// Image& im: input image to be modified in-place
void lch_to_rgb(Image& im) {
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
