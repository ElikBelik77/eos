#ifndef TCB_H_
#define TCB_H_
#include <stdint.h>
typedef struct TCB {
	uint32_t ESP;
	uint32_t CR3;
	struct TCB* next_task;
	uint32_t state;
} TCB;
#endif
