/* Define the end of RAM and limit of stack memory */
/* (RAM starts at address 0x20000000) */
_estack = 0x20005000;    /* end of 20K RAM */

MEMORY
{
    FLASH ( rx )      : ORIGIN = 0x08000000, LENGTH = 64K
    RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 20K
}