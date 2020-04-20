# 3SS ©
An Android dhash algorithm that does reduction, greyscale, and fingerprint in one pass. Currently written to detect  duplicates with box interpolation.  While it does work when I download a large enough image (100 x 100), NN does not hold up with less pixel information, for distortions.
Other ideas: Haar wavelet, sinc lanczos. FMIQ and Deep Autoencoders. 

Available in C++ and Kotlin.


3SS describes the 3 steps of the dhash algorithm in one pass for image detection, optimized for use with Android(row hash only, DirectBuffer to JNI or Kotlin implementation). It is using NN for scaling with exact detection.  It is currently working on complex images with box interpolation and these shortcuts.

## Best times for hashing, so far:

* JNI C++ nativeDHash: times average around .005 seconds running in Edo app

* Kotlin dHash: 1.4s


<img src="https://i.imgur.com/f5jLtXl.png" height="250"/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

## License

* [Apache Version 2.0](http://www.apache.org/licenses/LICENSE-2.0.html)

## Building

This lib was built with Android Studio which uses the gradle build system.  

## Acknowledgements

This project uses the [Github API] ( https://www.github.com)
* http://www.hackerfactor.com/blog/index.php?/archives/529-Kind-of-Like-That.html
* http://tech.jetsetter.com/2017/03/21/duplicate-image-detection/





