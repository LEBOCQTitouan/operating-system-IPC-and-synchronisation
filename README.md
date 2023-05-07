# Operating system : IPC and synchronization

This package implement a simple example of IPC and synchronization between two processes using shared memory and
semaphores.

## Installation

This project will only work on Linux and Mac OS.

### Dependencies

- [CMake](https://cmake.org/)/[Make](https://www.gnu.org/software/make/) : For building the project.
- [OpenGL](https://www.opengl.org/) : For the graphical interface.

### Building

#### Using Make

```bash
make
```

#### Using CMake

```bash
mkdir build
cmake --build build
```

## Project description

This project is to be used with `windy_fountain` executable:
* `windy_fountain_mac` : For Mac OS.
* `windy_fountain.bin` : For Linux.
* Windows is not supported.

In this program their will be 5 processes:
* A process which start the camera control in the UI
  * A process to control the camera rotation.
  * A process to control the camera zoom (distance).
* A process to control the environment properties.
* A process to control orchestration of the other processes.

### Usage

Start the `windy_fountain` executable and then start the compiled project.