
# Image Filter Program (Basic Filters)

## Description  
A C program that applies image filters to bitmap (BMP) files. Implemented grayscale, sepia, reflection, and blur filters transformations by manipulating individual pixels. The program uses fundamental image processing techniques and low-level manipulation of bitmap data, iterating over each pixel in a 2D array and adjusting its RGB color values. 


**Key Concepts**
- **2D arrays in C** — representing and manipulating pixel grids 
- **Structs** for data representation — working with (`RGBTRIPLE`) to store pixel color components
- Nested iteration — traversing rows and columns of an image to apply filters transformations
- **Algorithm** implementation — grayscale averaging, sepia tone conversion, horizontal reflection, and box blur
- Low-level data manipulation — Direct **manipulation of bitmap image data** in C  



**Sample Output**  
- Input: Original BMP image  
- Output: Four transformed versions possible:  
  - Grayscale conversion  
  - Sepia tone effect  
  - Horizontal reflection  
  - Blur filter  

```bash
  $ ./filter -g images/yard.bmp out.bmp

  
```
![Original](/images/yard-grayscale.bmp)

![Filtered](images/yard.bmp)
