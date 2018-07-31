#include <jni.h>


/**3ss algorithm © 2018
 * scales the image using the fastest, simplest algorithm called "nearest neighbor, greyscales,
 * and fingerprints all in one*/
extern "C" JNIEXPORT jlong JNICALL
Java_com_droidteahouse_edo_ui_ArtActivity_00024MyPreloadModelProvider_nativeDhash(
        JNIEnv *env, jobject obj, jobject db, jint newWidth, jint newHeight, jint oldWidth,
        jint oldHeight) {

    jint *iBuf = (jint *) env->GetDirectBufferAddress(db);
    jint *newBitmapPixels = new jint[newWidth * newHeight];
    jint x2, y2;
    jint index = 0;
    jlong hash = 0;
    //buffer has been allocated for size already on java side
    for (jint y = 0; y < newHeight; ++y) {
        for (jint x = 0; x < newWidth; ++x) {
            x2 = x * oldWidth / newWidth;
            if (x2 < 0)
                x2 = 0;
            else if (x2 >= oldWidth)
                x2 = oldWidth - 1;
            y2 = y * oldHeight / newHeight;
            if (y2 < 0)
                y2 = 0;
            else if (y2 >= oldHeight)
                y2 = oldHeight - 1;
            newBitmapPixels[index] = iBuf[((y2 * oldWidth) + x2)];
            //same as : newBitmapPixels[(y * newWidth) + x] = previousData[(y2 * oldWidth) + x2];
            if (index > 0) {
                if ((index) % newWidth != 0) {
                    jint pixel2 = newBitmapPixels[index];
                    jint pixel = newBitmapPixels[index - 1];
                    pixel2 = (pixel2 & 0xff) * 0.299 + ((pixel2 >> 8) & 0xff) * 0.587 +
                             ((pixel2 >> 16) & 0xff) * 0.114;
                    pixel = (pixel & 0xff) * 0.299 + ((pixel >> 8) & 0xff) * 0.587 +
                            ((pixel >> 16) & 0xff) * 0.114;
                    hash |= ((pixel) < (pixel2));
                    hash <<= 1L;
                }
            }
            index++;
        }
    }
    return hash;
}
