# get_next_line

A lightweight C function that reads and returns a single line from a file descriptor every time it is called.

---

## 📌 Overview

Standard C lets you read raw bytes with `read()`, but it does not have a built-in way to read text line by line. **get_next_line** bridges that gap.

Whether reading from a small text file, standard input (`stdin`), or a huge log file, it delivers one clean line at a time until reaching the end of the file.

---

## ⚙️ How It Works

1. **Read in Chunks:** Reads a fixed number of bytes (`BUFFER_SIZE`) from the file descriptor.
2. **Stash the Data:** Saves the incoming bytes into a **static variable** so the data persists between function calls.
3. **Find the Newline:** Checks if a `\n` character exists in the stashed buffer.
4. **Extract & Return:** 
   * Slices out the line up to `\n` and returns it as a newly allocated string.
   * Keeps the remaining characters in the stash for the next call.
5. **End of File:** Returns `NULL` when there is nothing left to read or if an error occurs.

---

## 📂 Project Structure

| File | Purpose |
| :--- | :--- |
| `get_next_line.c` | Main logic: reading, extracting the line, and updating the static buffer. |
| `get_next_line_utils.c` | Helper functions for string operations (`strlen`, `strchr`, `strjoin`, `substr`). |
| `get_next_line.h` | Prototypes and default `BUFFER_SIZE` definition. |

---

## 🚀 Quick Start

### 1. Integration Example

Save this as `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd;
    char  *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Each returned line is dynamically allocated
    }

    close(fd);
    return (0);
}