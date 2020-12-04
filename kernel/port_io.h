#ifndef IO_H_
#define IO_H_

//This function writes a byte to the port.
void port_byte_out(unsigned short port, unsigned char data);

//This function writes a word to the port.
void port_word_out(unsigned short port, unsigned short data);

//This function reads a byte from a port.
unsigned char port_byte_in(unsigned short port);

//This function reads a word from a port.
unsigned short port_word_in(unsigned short port);

#endif
