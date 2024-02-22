# ddminMus algorithm in C++
## Compile
Just run `make` from the command line

## Usage
The agorithm only needs the input sequence as a `std::vector` and a function pointer to a function that checks,
if the input has a bug. This fucntion should return `false` if teh given input causes a bug.
The function therefore must have the following signature: `bool (std::vector<T>)` where `T`can be any type.

The program outputs the reduced inputs as a `0
