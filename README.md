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

## XCSL-AArch64 Installation

##### Clone the Repository

```bash
$  cd path/to/projects
$  git clone https://github.com/CodeusTech/XCSL-AArch64.git
```
**NOTE:** Two-Factor Authentication *must* be enabled.

##### Build and Install XCSL

```bash
$  cd XCSL-AArch64/
$  sudo make install
```

##### Build XCSL and Do NOT Install

```bash
$  cd XCSL-AArch64/
$  make build
```

##### Uninstall XCSL

```bash
$  cd XCSL-AArch64/
$  sudo make uninstall
```

##  XCSL-Usage 

The following usage commands assume XCS-AArch64 is installed on the current
Linux syetem.  If it is only built (and not installed), you will need to
use 

```_build/xcs-aarch64```

##### Live Interpreter

```bash
$  xcs-aarch64
```

##### XCS Cross-Compiler

```bash
$  xcs-aarch64 [file1 file2 ...]
```


