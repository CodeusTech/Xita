/*
  optimize.h
  Codeus Tech
  Authored on   November 26, 2019
  Last Modified November 26, 2019
*/

/*
  Contains handling code for setting/getting XCS optimization scheme

  The 'OPTIMIZATION SCHEME' is a conceptual definition for how CPU registers
    should be used during the module's runtime.  
*/

#ifndef STD_OPTIMIZE_H
#define STD_OPTIMIZE_H


enum xcs_optimization_scheme 
{
  DEFAULT = 28, 
  a32i = 144,
  a32f = 87,
  a48sr = 55,
  a64sr = 55,
};


xcs_optimization_scheme _scheme = xcs_optimization_scheme::DEFAULT;

//  Number of Arbitrary Data Registers is Architecture Dependent
unsigned long NUMBER_OF_ADRS = xcs_optimization_scheme::DEFAULT;
/*
  NOTE:
    * Setting 'NUMBER_OF_ADRS' to  27 disables use of AArch64's NEON registers
    * Setting 'NUMBER_OF_ADRS' to  55 enables all AArch64 registers (1 per NEON)
    * Setting 'NUMBER_OF_ADRS' to  87 enables -a32f optimization (2 per NEON)
    * Setting 'NUMBER_OF_ADRS' to 144 enables -a32i optimization (4 per NEON)
     
  TODO: 
    * Set 'NUMBER_OF_ADRS' procedurally, based on optimization scheme setting
*/

ErrorCode set_optimization(xcs_optimization_scheme scheme) 
{ 
  _scheme = scheme; 
  NUMBER_OF_ADRS = scheme;
  
  //  Return Success
  return 0;
}
xcs_optimization_scheme get_optimization() { return _scheme; }

#endif
