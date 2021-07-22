(*
  aux.xs
  Codeus Tech
  Authored on   March 17, 2019
  Last Modified  July 22, 2021
*)

Driver Aux

(*
  Contains Driver for Raspberry Pi 3 Auxilary I/O Devices

  TABLE OF CONTENTS
  =================
  1.) Memory-Mapped Register Constants

  See the Memory-Mapped Registers for the addressed firmware driver

  Address    | Register Name | Purpose
  ========== | ============= | ==========================
  0x3F215000 | AUX_IRQ       | Auxiliary Interrupt Status
  0x3F215004 | AUX_ENABLES   | Auxiliary Enables
  0x3F215040 | MU_IO_REG     | Mini UART I/O Data
  0x3F215044 | MU_IER_REG    | Mini UART Interrupt Enable
  0x3F215048 | MU_IIR_REG    | Mini UART Interrupt Identify
  0x3F21504C | MU_LCR_REG    | Mini UART Line Control
  0x3F215050 | MU_MCR_REG    | Mini UART Modem Control
  0x3F215054 | MU_LSR_REG    | Mini UART Line Status
  0x3F215058 | MU_MSR_REG    | Mini UART Modem Status
  0x3F21505C | MU_SCRATCH    | Mini UART Scratch Register
  0x3F215060 | MU_CNTL_REG   | Mini UART Extra Control
  0x3F215064 | MU_STAT_REG   | Mini UART Extra Status
  0x3F215068 | MU_BAUD_REG   | Mini UART Baud Rate
  0x3F215080 | SPI1_CNTL0    | SPI 1 Control Register 0
  0x3F215084 | SPI1_CNTL1    | SPI 1 Control Register 1
  0x3F215088 | SPI1_STAT     | SPI 1 Status
  0x3F215090 | SPI1_DATA     | SPI 1 I/O Data
  0x3F215094 | SPI1_PEEK     | SPI 1 Peek
  0x3F2150C0 | SPI2_CNTL0    | SPI 2 Control Register 0
  0x3F2150C4 | SPI2_CNTL1    | SPI 2 Control Register 1
  0x3F2150C8 | SPI2_STAT     | SPI 2 Status
  0x3F2150D0 | SPI2_DATA     | SPI 2 I/O Data
  0x3F2150D4 | SPI2_PEEK     | SPI 2 Peek
*)


(*
  1.) Memory-Mapped Register Constants
*)

const U32 aux_base = 0x3F215000;;

const U32 aux_irq     = aux_base + 0x00;;
const U32 aux_enables = aux_base + 0x04;;
const U32 mu_io       = aux_base + 0x40;;
const U32 mu_ier      = aux_base + 0x44;;
const U32 mu_iir      = aux_base + 0x48;;
const U32 mu_lcr      = aux_base + 0x4C;;
const U32 mu_mcr      = aux_base + 0x50;;
const U32 mu_lsr      = aux_base + 0x54;;
const U32 mu_msr      = aux_base + 0x58;;
const U32 mu_scratch  = aux_base + 0x5C;;
const U32 mu_cntl     = aux_base + 0x60;;
const U32 mu_stat     = aux_base + 0x64;;
const U32 mu_baud     = aux_base + 0x68;;
const U32 spi1_cntl0  = aux_base + 0x80;;
const U32 spi1_cntl1  = aux_base + 0x84;;
const U32 spi1_stat   = aux_base + 0x88;;
const U32 spi1_data   = aux_base + 0x90;;
const U32 spi1_peek   = aux_base + 0x94;;
const U32 spi2_cntl0  = aux_base + 0xC0;;
const U32 spi2_cntl1  = aux_base + 0xC4;;
const U32 spi2_stat   = aux_base + 0xC8;;
const U32 spi2_data   = aux_base + 0xD0;;
const U32 spi2_peek   = aux_base + 0xD4;;


