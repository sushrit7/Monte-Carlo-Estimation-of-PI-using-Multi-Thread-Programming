# Monte Carlo Estimation of PI using Multi-Thread Programming

This project demonstrates a simple implementation of the Monte Carlo method to estimate the value of PI using multi-thread programming in C.

## Overview

The Monte Carlo method is a statistical technique that uses random sampling to obtain numerical results. In this project, we use the method to estimate the value of PI by generating random points within a unit square and determining how many fall inside a unit circle.

## Implementation Details

- The program is written in C and uses pthreads for multi-threading.
- Each thread generates a set number of random (x, y) pairs using `drand48_r`.
- The coordinates are used to check if they fall within the unit circle.
- A mutex is used to protect shared variables to avoid race conditions.

## Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/monte-carlo-pi-estimation.git
   cd monte-carlo-pi-estimation

2. Compile the program:

  ```bash
  gcc montecarlo.c -o montecarlo -pthread
  ```

3. Run the executable:
   ```bash
   ./montecarlo
   ```
View the estimated value of PI in the output.

## Code Structure
__montecarlo.c__: Main C program implementing the Monte Carlo estimation of PI using multi-threading.

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests.
