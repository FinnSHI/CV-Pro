//
// Created by COMP5523 on 2022/1/17.
//

#include "../image.h"
#include "../utils.h"
#include <iostream>

#include <string>

using namespace std;


// 1-2. Getting and setting pixels
void test_pixel_setting() {
    Image im2 = load_image("data/dog.jpg");
    for (int i=0; i<im2.w; i++)
        for (int j=0; j<im2.h; j++)
            im2(i, j, 0) = 0;
    im2.save_image("output/test_case_output/case1_set_pixel_result");
}

// 3 Gray Scale
void test_grayscale() {
    Image im = load_image("data/colorbar.png");
    Image gray = rgb_to_grayscale(im);
    gray.save_image("output/test_case_output/case2_test_grayscale");

    Image g = load_image("data/gray.png");
    bool is_same = same_image(gray, g);
    std::cout << "Gray images are same: " << is_same << " (1 is same, 0 is not same)" << endl;
}

// 4. Shift Image
void test_shift_image() {
    Image im = load_image("data/dog.jpg");
    shift_image(im, 0, .4);
    shift_image(im, 1, .4);
    shift_image(im, 2, .4);
    im.save_image("output/test_case_output/case3_shift_result");
}

// 5. Clamp Image
void test_clamp_image() {
    Image im = load_image("data/dog.jpg");
    shift_image(im, 0, .4);
    shift_image(im, 1, .4);
    shift_image(im, 2, .4);

    clamp_image(im);
    im.save_image("output/test_case_output/case4_clamp_result");
}

// 6. RGB to HSV
void test_rgb_to_hsv() {
    Image im = load_image("data/dog.jpg");
    rgb_to_hsv(im);
    im.save_image("output/test_case_output/case5_test_rbg_to_hsv");

    Image hsv = load_image("data/dog.hsv.png");
    bool is_same = same_image(im, hsv);
    std::cout << "RGB and HSV are same: " << is_same << " (1 is same, 0 is not same)" << endl;
}

// 7. HSV to RGB
void test_hsv_to_rgb() {
    Image im = load_image("data/dog.jpg");
    Image c = im;
    rgb_to_hsv(im);
    hsv_to_rgb(im);
    im.save_image("output/test_case_output/case6_test_hsv_to_rgb");

    bool is_same = same_image(im, c);
    std::cout << "RGB and HSV are same: " << is_same << " (1 is same, 0 is not same)" << endl;
}

// 6-7. Colorspace and saturation
void test_colorspace_saturation() {
    Image im2 = load_image("data/dog.jpg");
    rgb_to_hsv(im2);
    shift_image(im2, 1, .2);
    clamp_image(im2);
    hsv_to_rgb(im2);
    im2.save_image("output/test_case_output/case7_colorspace_result");
}

// 8. A small amount of extra credit
void test_scale_image_saturation() {
    Image im = load_image("data/dog.jpg");
    rgb_to_hsv(im);
    scale_image(im, 1, 2);
    clamp_image(im);
    hsv_to_rgb(im);
    im.save_image("output/test_case_output/case8_dog_scale_saturated");
}

int main(int argc, char **argv)
{
    // Case 1
    test_pixel_setting();

    // Case 2
//    test_grayscale();

    // Case 3
//    test_shift_image();

    // Case 4
//    test_clamp_image();

    // Case 5
//    test_rgb_to_hsv();

    // Case 6
//    test_hsv_to_rgb();

    // Case 7
//    test_colorspace_saturation();

    // Case 8, extra credit, bonus, optional
//    test_scale_image_saturation();

    return 0;
}

