/*
 * OBC1 emulation code  
 * (c) Copyright 2001-2004 zsKnight, pagefault, Kris Bleakley
 * Ported from x86 assembler to C by sanmaiwashi
 * 
 * Used by: Metal Combat: Falcon's Revenge
 */

#ifndef _OBC1_H_
#define _OBC1_H_

uint8 S9xGetOBC1(uint16 Address);
void S9xSetOBC1(uint8 Byte, uint16 Address);
void S9xResetOBC1(void);

extern uint8 *OBC1RAM;

#endif
