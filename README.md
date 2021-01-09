# EOS
It's not a cryptographic coin project - it's an operating system

### Build & Run
You need to install bochs to run this OS.

To build the operating system simply:
```bash
make all
```
And run with:
```
make run
```
### Features
- [x] Customizable interrupt handler.
- [x] Screen driver (text mode 25x80, scrolling.).
- [x] Keyboard driver.
- [ ] SATA/SATAPI disk driver (half complete).
- [ ] Higher half kernel.
- [ ] ELF loading.
- [ ] Multitasking (in progress).



### Other Information
The operating system uses flat overlapping memory layout, and is planned to manage virtual memory on the lower half of the address space.
