# hex

Simple command line tool to convert between decimal and hexadecimal numbers

# Usage

Example 1: `hex 10` returns `0xA`

Example 2: `hex 0xa` returns `10`

# Compile
Straight forward:

    g++ hex.cpp -o hex

To reduce the size of the executable:

    strip hex
