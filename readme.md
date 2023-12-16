# currently working on
- [ ] Responsive window design
- [ ] Render components properly when resized
- [ ] Change the speed of the Animation 

# Sorting Visualizer with SFML

![Sorting Visualizer](/assets/images/sfml.png)

This project is a Sorting Visualizer built using the [SFML](https://www.sfml-dev.org/) library in C++. It allows you to visualize various sorting algorithms in action.

## Features
- Visualize sorting algorithms such as Bubble Sort

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Supported Sorting Algorithms](#supported-sorting-algorithms)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

Before running the program, ensure you have the following installed:

- [SFML Library](https://www.sfml-dev.org/download.php) - Follow the installation instructions for your platform.

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/Sorting-Visualizer.git
### Usage
1. Compile:
   
   To compile the file `cd` into `Sorting-Visualizer/src` file and compile `main.cpp` file and make sure to include the `include` folder while compiling, 
   and make sure to link all the flags.
  
    ```shell
    cd Sorting-Visualizer
    g++ -I include -o Sorting-Visualizer src/main.cpp -lsfml-system -lsfml-window -lsfml-graphics
    ```
   
2. Run:
    To run the executable file just do this
    > Be sure not mess up paths while compiling the source file after compiling `cd` into whatever dir you compiled the executable and run the executable by this command.
    ```shell
    ./Sorting-Visualizer
    ```
