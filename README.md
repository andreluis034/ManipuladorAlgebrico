# Algebric Manipulator 

A simple algebric manipulator that sums, derivates or integrates polynomials.

## Getting Started

Clone the project into a local folder: git clone https://github.com/andreluis034/ManipuladorAlgebrico.git
Change into the created folder and build the project using: make

### Prerequisites

To build the project you must have the following packaged installed:
* GNU Compiler Collection
* GNU Make
    
On Debian and Debian based distributions installing the build-essential package will suffice:
```
apt-get install build-essential
```

### Installing

After cloning the repository and installing the prerequisites:

Build the project using make

```
make algebra.out
```

Since this is a small project it shouldn't take long to build it.
After it has been built the project binary, algebra.out, will be in the project root folder.


### Examples

When asked for a polynomial it should come from standard input with the following regular expression:
```
([\+\-]?([0-9]*[\.]?)[0-9]*[A-Za-z]*([\^][0-9]+)?)*
```
This expression does not take into account the spaces from input as these are ignored when reading the input.

Although multiple variables are supported in a "monomial" you should not repeat the same variable twice.

Here are some examples of valid inputs:
* 5x^3254
* 532xyz^3254 + 6xy^23 - .5
* 5.65x^3254
* .62548



## Built With

* [GNU Make](https://www.gnu.org/software/make/) - Tool used to build the project
* [GNU Compiler Collection](https://www.gnu.org/software/gcc/) - Compiler used to build the project

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.


## Authors

* **André Brandão** - [andreluis034](https://github.com/andreluis034)
* **Rúben Carvalho**

See also the list of [contributors](https://github.com/andreluis034/ManipuladorAlgebrico/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
