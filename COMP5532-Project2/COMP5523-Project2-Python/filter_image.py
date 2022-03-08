from Image import Image


def l1_normalize(img):
    ret = Image(img.h, img.w, img.c)



    return ret

class make_box_filter(object):
    def __init__(self, kernel_size):
        if kernel_size % 2 == 0:
            raise ValueError("kernel size needs to be odd")
        self.kernel = Image(kernel_size, kernel_size, 1)
        self.h = self.kernel.h
        self.w = self.kernel.w
        self.c = self.kernel.c


    def __call__(self, local):
        out = 0


        return out



def padding_image(img, filter):
    stride = 1
    padding = int((filter.h - stride)/2)
    ret = Image(img.h+padding*2, img.w+padding*2, img.c)



    return ret


def convolve_image(img, filter, preseve):
    if filter.c != 1:
        raise ValueError("filter kernel should only have 1 channel")

    ret = Image(img.h-filter.h +1, img.w-filter.w +1, img.c)



    return ret


class make_highpass_filter(object):
    def __init__(self):
        self.kernel = Image(3, 3, 1)

        self.h = self.kernel.h
        self.w = self.kernel.w
        self.c = self.kernel.c

    def __call__(self, local):
        out = 0


        return out

class make_sharpen_filter(object):
    def __init__(self):
        self.kernel = Image(3, 3, 1)

        self.h = self.kernel.h
        self.w = self.kernel.w
        self.c = self.kernel.c

    def __call__(self, local):
        out = 0


        return out


class make_emboss_filter(object):
    def __init__(self):
        self.kernel = Image(3, 3, 1)

        self.h = self.kernel.h
        self.w = self.kernel.w
        self.c = self.kernel.c

    def __call__(self, local):
        out = 0


        return out

