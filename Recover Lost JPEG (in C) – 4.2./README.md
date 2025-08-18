# Recover Lost JPEG Files from Memory Card

### Description 
A C program that **recovers JPEG images from a raw memory card dump**. The program reads the raw data sequentially in 512-byte blocks, detects JPEG headers byte signatures that mark the start of a JPEG file, and reconstructs each image by writing consecutive blocks until the following header is found. Each recovered image is saved sequentially to a new file (`000.jpg`, `001.jpg`, …) until the end of the dump.


**How it works (algorithm)**
- Read the raw file **block-by-block (512 bytes)**.
- Identify JPEG starts by checking the header bytes:
  - `0xff 0xd8 0xff` and `0xe0`–`0xef` in the 4th byte.
- When a new header is found:
  - Close the previous image (if any) and **start a new output file**.
  - **Append blocks** to the current JPEG until the next header appears.
- Repeat until EOF.

**Key CS Concepts**
- **Binary I/O** with `fread`/`fwrite` and fixed-size buffers  
- **Magic bytes & file signatures** (header-based format detection)  
- **Stateful streaming** (open/close output handles as boundaries change)  
- **Pointer & buffer management**; robust loop/EOF control  
- **Filesystem operations** (sequential filenames, error handling)





**Usage**
```bash
# compile
make recover
# or
gcc recover.c -o recover

# run
./recover card.raw
# outputs: 000.jpg, 001.jpg, 002.jpg, ...
```

02 of the 50 images recovered just as eg. The other are in the attached "recovered image" folder

![Image](/images/recovered images sample for 4.2 Recover/000.jpg)

![Image](/images/recovered images sample for 4.2 Recover/002.jpg)

![Image](/images/recovered images sample for 4.2 Recover/007.jpg)