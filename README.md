# Computer Vision Useful Codes
## Some useful and simple codes developed using opencv to automate some processes when using a large amount of data
### Software Information
- Opencv 4.1.0
- C++
### Files description
- [ConvertExtension.cpp](https://github.com/AnneLivia/ComputerVisionUsefulCodes/blob/master/source/convertExtensions.cpp): this program converts images
of some original extension into another extension. It basically requires the directory where the files are, the original extension of the files, 
and the desired extension, it then gets all the archives encountered that sastisfies the condition and saves in the same directory with the same 
name as the original one.
- [ResizeImage.cpp](https://github.com/AnneLivia/ComputerVisionUsefulCodes/blob/master/source/resizeImages.cpp): this program gets images from a specific directory
and resizes it to a given size.
- [crop_image.cpp](https://github.com/AnneLivia/ComputerVisionUsefulCodes/blob/master/source/crop_image.cpp): this program gets images from a specific directory, detect some objects present on it and then saves. Useful when it's necessary to create a dataset containing the aimed object.
- [convertAllToGray.cpp](https://github.com/AnneLivia/ComputerVisionUsefulCodes/blob/master/source/convertAllToGray.cpp): converts all images from a directory to gray.
