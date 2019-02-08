OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  . = 0x00004000;
  .text.init : { *(.text.init) }
  .text : { *(.text) }
  .data : { *(.data) }
  .bss : { *(.bss) }
  _end = .;
}

