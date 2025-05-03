# Biggest Square (BSQ) Finder

A **C program** that efficiently finds the largest possible empty square in a grid with obstacles, using **dynamic programming (DP)** as the core algorithm. When multiple solutions exist, it prioritizes the top-left square.

---

## Table of Contents

1. [Features](#features)
2. [Installation](#installation)
3. [Usage](#usage)
    - [Interactive Mode](#interactive-mode)
    - [File Mode](#file-mode)
4. [Algorithm](#algorithm)
5. [File Format](#file-format)
6. [Examples](#examples)
7. [Limitations](#limitations)
8. [Contributing](#contributing)
9. [License](#license)

---

## Features

- **Dynamic Programming (DP)** solution with **O(n²)** complexity.
- Finds the largest empty square in a grid with obstacles.
- Supports both **file input** and **interactive standard input**.
- Proper memory management and error handling.
- Validates input format and content.

---

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/bsq.git
    cd bsq
    ```

2. Compile the program:

    ```bash
    make
    ```

    This will create an executable named `bsq`.

---

## Usage

### Interactive Mode

Run the program without arguments to manually input a grid:

```bash
./bsq
```

- Type or paste your grid (end input with `Ctrl+D`).
- The solution will be printed to `stdout`.
- Input is also saved to `output.txt`.

### File Mode

Process one or multiple map files:

```bash
./bsq map1.txt map2.txt
```

- Each file will be processed sequentially.
- Results are printed to `stdout`.
- Errors are printed to `stderr`.

---

## Algorithm

The **dynamic programming (DP)** approach is the heart of this program:

1. **DP Table Construction**:
    - Create a DP table where each cell stores the size of the largest square ending at that position.
    - For each cell:
      - If it's an obstacle: DP value = `0`.
      - If it's empty: DP value = `1 + min(top, left, top-left neighbors)`.

2. **Tracking the Largest Square**:
    - Track the maximum DP value and its coordinates.
    - The coordinates indicate the bottom-right corner of the largest square.

3. **Output the Solution**:
    - Replace the largest square in the grid with the `full_char`.

This efficient DP solution ensures the program runs in **O(n²)** time, making it suitable for large grids.

---

## File Format

Input files must follow this format:

```
[number_of_rows][empty_char][obstacle_char][full_char]
[first row]
[second row]
...
```

### Example:

```
5.ox
.o...o
..o.o
o....o
.oo...
...o.o
```

---

## Examples

### File Input:

```bash
./bsq samples/map1.txt
```

**Input:**

```
5.ox
.o...o
...o.o
o....o
.oo...
...o.o
```

**Output:**

```
xo...o
...o.o
o....o
.oo...
...o.o
```

### Interactive Input:

```bash
./bsq
```

**Input:**

```
5.ox
.o...
.....
o....
.....
.....
```

**Output (after `Ctrl+D`):**

```
.oxxx
..xxx
o.xxx
.....
.....
```

---

## Limitations

- Maximum grid size is currently hardcoded to **100×100** (modifiable in `c_minded.h`).
- First line must contain valid metadata.
- All rows must be of equal length.
- Requires at least one empty space to find a solution.

---

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create your feature branch.
3. Commit your changes.
4. Push to the branch.
5. Open a pull request.

---

## License

This project is licensed under the [MIT License](LICENSE).

---