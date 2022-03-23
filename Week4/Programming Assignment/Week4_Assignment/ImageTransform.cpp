#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)

Write your name and email address in the comment space here:

Name: Mohamed Ragab
Email: mrfa221999@gmail.com

(...end multi-line comment.)
******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned i = 0; i < image.width(); i++) {
    for (unsigned j = 0; j < image.height(); j++) {
         HSLAPixel & pixel = image.getPixel(i, j);
         pixel.s = 0;
    }
  }

  return image;
}


PNG createSpotlight(PNG image, int centerX, int centerY) {
    
    unsigned newx = static_cast<unsigned>(centerX);
    unsigned newy = static_cast<unsigned>(centerY);

    for (unsigned i = 0; i < image.width(); ++i) {
        for (unsigned j = 0; j < image.height(); ++j) {
            if (i == newx && j == newy) {
                continue;
            }

            HSLAPixel& pixel = image.getPixel(i, j);
            double lum = std::sqrt((newx - i) * (newx - i) + (newy - j) * (newy - j)) * static_cast<double>(0.005);

            if (lum >= static_cast<double>(0.8)) {
                lum = static_cast<double>(0.8);
            }
            lum = 1.0 - lum;
            pixel.l = (pixel.l * lum);
        }
    }

    return image;

}
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
    for (unsigned i = 0; i < image.width(); ++i) {
        for (unsigned j = 0; j < image.height(); ++j) {
            HSLAPixel& pixel = image.getPixel(i, j);
            if (pixel.h >= 200 && pixel.h < 330) {
                pixel.h = 216;
            }
            else {
                pixel.h = 11;
            }
        }
    }
    return image;
}
 

/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {
    for (unsigned i = 0; i < secondImage.width(); i++) {
        for (unsigned j = 0; j < secondImage.height(); j++) {
            HSLAPixel& firstPixel = firstImage.getPixel(i, j);
            HSLAPixel& secondPixel = secondImage.getPixel(i, j);
            if (secondPixel.l == 1.0) {
                firstPixel.l += 0.2;
            }
        }
    }
    return firstImage;
}
