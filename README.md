# XCSL Cross-Compiler (AArch64)
#### Version: 0.1.0

Currently, the XCSL cross-compiler works on the Linux platform.  The resulting binary
executable uses XCS ABI, calling conventions, etc.

## Prerequisite Installation

##### Arch/Antergos

``` bash
$  sudo pacman -Syyu
$  sudo pacman -S make gcc flex bison
```

##### CentOS/RHEL/Scientific Linux/Fedora

``` bash
$  sudo yum update
$  sudo yum nasm
$  sudo yum group install "Development Tools"
```

##### Fedora 22+

``` bash
$  sudo dnf upgrade --refresh
$  sudo dnf groupinstall "Development Tools"
$  sudo dnf groupinstall "C Development Tools and Libraries"
```

##### Debian/Ubuntu/Mint

``` bash
$  sudo apt-get update
$  sudo apt-get upgrade
$  sudo apt-get install build-essential flex flexc++ bison bisonc++
```


## Installation using Terminal

##### Clone the Repository

```bash
$  cd path/to/projects
$  git clone https://github.com/CodeusTech/XSL.C.git
```

##### Build and Install XSL

```bash
$  cd XSL.C
$  sudo make install
```

##### Uninstall XSL

```bash
$  sudo make uninstall
```



