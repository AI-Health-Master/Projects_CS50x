
# Speller —  Dictionary-Based Text Spell Checking Program with Hash Tables

### Description 
A C program that implements a **dictionary-based spell checker**. The program loads a dictionary into memory using a hash table, then checks words in a given text file against the dictionary. It reports all misspelled words, along with statistics on dictionary loading time, text checking, and memory usage.

**How it works**
- **Dictionary loading:** Reads words from a dictionary file and stores them in a hash table.
- **Spell-checking:** Tokenizes an input text and checks each word against the hash table.
- **Misspelling report:** Outputs words not found in the dictionary.
- **Performance reporting:** Displays timing for load, check, size, and unload functions.

**Key CS Concepts**
- **Hash tables and hashing functions** for efficient dictionary lookups  
- **Dynamic memory management** with `malloc`/`free` for node allocation and cleanup  
- **File I/O and parsing** for reading dictionary and text input  
- **Linked lists for collision handling** in hash buckets  
- **Algorithmic complexity (O(1) average lookup time)** and performance tradeoffs  

 
 The main C file is speller.c

**Sample Output**
```bash
$ ./speller texts/lalaland.txt
MISSPELLED WORDS
...

WORDS MISSPELLED:     130
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        764
TIME IN load:         0.07
TIME IN check:        0.03
TIME IN size:         0.00
TIME IN unload:       0.01
TIME IN TOTAL:        0.11
