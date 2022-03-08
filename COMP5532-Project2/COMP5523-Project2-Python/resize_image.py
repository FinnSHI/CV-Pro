from Image import Image

def nearest_resize(img, w, h):
    source = img
    target = Image(h, w, img.c)
    ## note: access pixel should input [h_coord, w_coord, c_coord], and simply use int() to get integer number, not round()
    ## TODO: use source pixel value to fill target pixel value



    return target



def bilinear_resize(img, w, h):
    source = img
    target = Image(h, w, img.c)
    ## note: access pixel should input [h_coord, w_coord, c_coord], and simply use int() to get integer number, not round()
    ## TODO: use source pixel value to fill target pixel value



    return target
