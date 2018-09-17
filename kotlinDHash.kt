

        fun dhash(oldWidth: Int, oldHeight: Int, newWidth: Int, newHeight: Int, ib: IntArray): Long {

            //val newBitmapPixels = IntArray(newWidth * newHeight)
            var x2: Int
            var y2: Int
            val end = (newWidth * newHeight) - 1;
            var index = 0
            var firstpixel = 0
            var hash: Long = 0

            //buffer has been allocated for size already on java side
            for (y in 0 until newHeight) {
                for (x in 0 until newWidth) {
                    x2 = x * oldWidth / newWidth
                    if (x2 < 0)
                        x2 = 0
                    else if (x2 >= oldWidth)
                        x2 = oldWidth - 1
                    y2 = y * oldHeight / newHeight
                    if (y2 < 0)
                        y2 = 0
                    else if (y2 >= oldHeight)
                        y2 = oldHeight - 1
                    //newBitmapPixels[index] = ib[((y2 * oldWidth) + x2)]
                    //same as : newBitmapPixels[(y * newWidth) + x] = previousData[(y2 * oldWidth) + x2];
                    /////>>>>>> big endian
                    if (index % newWidth == 0) {
                        firstpixel = ib[((y2 * oldWidth) + x2)];
                    } else if ((index) % newWidth != 0) {
                        var pixel2 = ib[y2 * oldWidth + x2]
                        var pixel = firstpixel
                        firstpixel = pixel2
                        pixel2 = (((pixel2 shr 24) and 0xff) * 0.299 + ((pixel2 shr 16) and 0xff) * 0.587 +
                                ((pixel2 shr 8) and 0xff) * 0.114).toInt()
                        pixel = (((pixel shr 24) and 0xff) * 0.299 + ((pixel shr 16) and 0xff) * 0.587 +
                                ((pixel shr 8) and 0xff) * 0.114).toInt()

                        hash = (hash or ((pixel < pixel2).toLong()))
                        if (index < end) {
                            hash = (hash shl 1)
                    }
                    }
                    index++
                }

            }

            return hash
        }

        inline fun Boolean.toLong() = if (this) 1L else 0L

