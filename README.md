# Xita Cross-Compiler (AArch64)
#### Version: v0.27.10
[![Build Status](https://app.travis-ci.com/CodeusTech/Xita.svg?branch=PreAlpha-Stable)](https://app.travis-ci.com/CodeusTech/Xita)

**Note:**  The C++ version of Xita Cross-Compiler is currently deprecated.  For mathematical verifiability, the existing project is in process of being translated to Haskell.  The code state of this repository is also badly in need of review by a third party.  

This respository provides the Linux-to-Xita cross compiler.  This **Xita Control System** compiler currently targets Arm64 architecture, though a current thrust area for development is to support Arm32 and x86 architectures.

### Table of Contents

* [Prerequisites](#prerequisite-installation)
  * [Arch/Antergos](#arch/antergos)
  * [Red Hat-Like](#centos/rhel/scientific-linux/fedora)
  * [Fedora 22+](#fedora-22+)
  * [Debian-Like](#debian/ubuntu/mint)
* [Installation](#XCSL-AArch64-Cross-Compiler-Installation)
  * [Clone Repository](#clone-the-repository)
  * [Install XCSL-AArch64](#build-and-install-xcsl)
  * [Build XCSL-AArch64](#build-xcsl-and-do-not-install)
  * [Uninstall XCSL-AArch64](#uninstall-xcsl)
* [Usage](#xita-usage)
  * [Live Interpreter](#live-interpreter)
  * [Cross-Compiler](#xita-cross-compiler)
  * [Terminal Options](#terminal-options)
* [Syntax Highlighting](#syntax-highlighting)



### Clone the Repository

```bash
$  mkdir CodeusTech && cd CodeusTech
$  git clone https://github.com/CodeusTech/Xita.git
```

### Prerequisite Installation 

##### Arch/Antergos

``` bash
$  sudo pacman -Syyu
$  sudo pacman -S make gcc flex bison
```

##### CentOS/RHEL/Scientific Linux/Fedora

``` bash
$  sudo yum update
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

#####  Cross-Assembler

To use the Xita Cross-Compiler, we need a compliant AArch64 cross-compiler.  Using the command below will uncompress the cross-assembler into the correct location for Xita internal use.  

**NOTE: Xita expects the cross assembler to reside in ~/.opt/cross**.

```bash
$  cd Xita/
$  tar xf aarch64-assembler.tar.xz -C $HOME
```

### Xita-AArch64 Cross-Compiler Installation

##### Build and Install Xita

```bash
$  make install
```

##### Build Xita and Do NOT Install

```bash
$  make build
```

##### Uninstall Xita

```bash
$  make uninstall
```

###  Xita Usage 

The following usage commands assume XCS-AArch64 is installed on the current
Linux system.  If it is only built (and not installed), you will need to
use:   ` $  _build/xcs-aarch64 [...] `


```bash
$  xcs-aarch64 [OPTIONS] [file1 file2 ...]
```

##### Terminal Options

Command-line options can be fed to either the live interpreter or cross-compiler.  
See the following list for option syntax and functionality.

*  --version
*  -v  |  --verbose  

### Syntax Highlighting

At present, Xita syntax highlighting is only available for [Visual Studio Code](https://code.visualstudio.com/).  

After installing VS Code, execute the following to install the highlighter:
```bash
$  cd ~/.vscode/extensions/
$  git clone https://github.com/CodeusTech/Xita-SyntaxHighlighter
```
Restart VS Code if it doesn't register \*.xs files immediately.
