//
// Created by COMP5523 on 2022/2/24.
// Do not do any modifications to these codes!
//

#include "../image.h"
#include "../utils.h"
#include <iostream>
#include <string>

using namespace std;

void test_nn_resize_4x() {
    std::cout << "Test \"1. test_nn_resize_4x\"\n" << endl;

    Image im = load_image("data/dogsmall.jpg");
    Image resized = nearest_resize(im, im.w*4, im.h*4);
    resized.save_image("output/test_case_output/1_dogssmall_nn_resized_4x");
}

void test_nn_resize_adaptive() {
    std::cout << "Test \"2. test_nn_resize_adaptive\"\n" << endl;

    Image im2 = load_image("data/dog.jpg");
    Image resized2 = nearest_resize_adaptive(im2, 713, 467);
    resized2.save_image("output/test_case_output/2_dogssmall_nn_resized_adaptive");
}

void test_bl_resize_4x() {
    std::cout << "Test \"3. test_bl_resize_4x\"\n" << endl;

    Image im = load_image("data/dogsmall.jpg");
    Image resized = bilinear_resize(im, im.w*4, im.h*4);
    resized.save_image("output/test_case_output/3_dogssmall_bl_resized_4x");
}

void test_bl_resize_adaptive() {
    std::cout << "Test \"4. test_bl_resize_adaptive\"\n" << endl;

    Image im2 = load_image("data/dog.jpg");
    Image resized2 = bilinear_resize_adaptive(im2, 713, 467);
    resized2.save_image("output/test_case_output/4_dogssmall_bl_resized_adaptive");
}

void test_l1_normalization() {
    std::cout << "Test \"5. test_l1_normalization\"\n" << endl;

    Image im = load_image("data/dog.jpg");
    Image im_l1 = l1_normalize(im);
    im_l1.save_image("output/test_case_output/5_l1_normalization");
}

void test_padding_image() {
    std::cout << "Test \"6. test_padding_image\"\n" << endl;

    Image im = load_image("data/dog.jpg");
    Image f = make_box_filter(47);
    Image pad_image = padding_image(im, f);
    pad_image.save_image("output/test_case_output/6_dog_padding_image");
}

void test_convolution() {
    std::cout << "Test \"7. test_convolution\"\n" << endl;

    Image im = load_image("data/dog.jpg");
    Image f = make_box_filter(7);
    Image pad_image = padding_image(im, f);
    Image blur = convolve_image(pad_image, f, true);
    blur.clamp();
    blur.save_image("output/test_case_output/7_image_convolution");
}


void test_convolution_no_preserve() {
    std::cout << "Test \"8. test_convolution_no_preserve\"\n" << endl;

    Image im = load_image("data/dog.jpg");
    Image f = make_box_filter(7);
    Image pad_image = padding_image(im, f);
    Image blur = convolve_image(pad_image, f, false);
    blur.clamp();
    blur.save_image("output/test_case_output/8_image_convolution_no_preserve");
}

void test_highpass_filter() {
    std::cout << "Test \"9. test_highpass_filter\"\n" << endl;

    Image im = load_image("data/dog.jpg");
    Image f = make_highpass_filter();
    Image pad_image = padding_image(im, f);
    Image blur = convolve_image(pad_image, f, false);
    blur.clamp();
    blur.save_image("output/test_case_output/9_image_highpass_filter");
}

void test_sharpen_filter() {
    std::cout << "Test \"10. test_sharpen_filter\"\n" << endl;

    Image im = load_image("data/dog.jpg");
    Image f = make_sharpen_filter();
    Image pad_image = padding_image(im, f);
    Image blur = convolve_image(pad_image, f, true);
    blur.clamp();
    blur.save_image("output/test_case_output/10_image_sharpen_filter");
}

void test_emboss_filter() {
    std::cout << "Test \"11. test_emboss_filter\"\n" << endl;

    Image im = load_image("data/dog.jpg");
    Image f = make_emboss_filter();
    Image pad_image = padding_image(im, f);
    Image blur = convolve_image(pad_image, f, true);
    blur.clamp();
    blur.save_image("output/test_case_output/11_image_emboss_filter");
}



int main(int argc, char **argv) {
    std::cout << "\n------ Running the test cases ... ------\n" << endl;

    // Case 1, resize using nearest neighbor interpolation with fixed 4x ratio
    test_nn_resize_4x();

    // Case 2, resize using nearest neighbor interpolation with adaptive ratio
    test_nn_resize_adaptive();

    // Case 3,  resize using bilinear interpolation with fixed 4x ratio
    test_bl_resize_4x();

    // Case 4, resize using bilinear interpolation with adaptive ratio
    test_bl_resize_adaptive();

    //Case 5, apply l1 normalization to the image
    test_l1_normalization();

    // Case 6, pad the image with zero
    test_padding_image();

    // Case 7, image convolution with 7x7 box filter, preserve is TRUE
    test_convolution();

    // Case 8, image convolution with 7x7 box filter, preserve is FALSE
    test_convolution_no_preserve();

    // Case 9, image convolution with 3x3 highpass filter, preserve is FALSE
    test_highpass_filter();

    // Case 10, image convolution with 3x3 sharpen filter, preserve is TRUE
    test_sharpen_filter();

    // Case 11, image convolution with 3x3 emboss filter, preserve is TRUE
    test_emboss_filter();

    std::cout << "------ Done. ------\n" << endl;

    return 0;
}