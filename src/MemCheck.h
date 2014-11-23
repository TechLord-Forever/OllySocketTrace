
#ifndef  LEAK_DETECTOR_C_H
#define  LEAK_DETECTOR_C_H

#define	FILE_NAME_LENGTH			256
#define	OUTPUT_FILE					"c:\\leak_info.txt"
#define	malloc(size)				xmalloc (size, __FILE__, __LINE__)
#define	calloc(elements, size)		xcalloc (elements, size, __FILE__, __LINE__)
#define	Memalloc(size, flags)		xMemalloc(size, flags, __FILE__, __LINE__)
#define HeapAlloc(heap, flags, size)	xHeapAlloc(heap, flags, size, __FILE__, __LINE__)
#define HeapReAlloc(heap, flags, new_addr, size)	xHeapReAlloc(heap, flags, new_addr, size, __FILE__, __LINE__)
#define HeapFree(heap, flags, addr)	xHeapFree(heap, flags, addr)
#define	free(mem_ref)				xfree(mem_ref)
#define	Memfree(mem_ref)			xfree(mem_ref)

struct _MEM_INFO
{
	void			*address;
	unsigned int	size;
	char			file_name[FILE_NAME_LENGTH];
	unsigned int	line;
};
typedef struct _MEM_INFO MEM_INFO;

struct _MEM_LEAK {
	MEM_INFO mem_info;
	struct _MEM_LEAK * next;
};
typedef struct _MEM_LEAK MEM_LEAK;

void add(MEM_INFO alloc_info);
void erase(unsigned pos);
void clear(void);

void * xmalloc(unsigned int size, const char * file, unsigned int line);
void * xcalloc(unsigned int elements, unsigned int size, const char * file, unsigned int line);
void * xMemalloc(unsigned long size, int flags, const char *file, unsigned int line);
void *xHeapAlloc(void *heap, unsigned long flags, unsigned long size, const char *file, unsigned int line);
void *xHeapReAlloc(void *heap, unsigned long flags, void *new_addr, unsigned long size, const char *file, unsigned int line);
int xHeapFree(void *heap, unsigned long flags, void *addr);
void xfree(void * mem_ref);

void add_mem_info (void *mem_ref, unsigned int size,  const char * file, unsigned int line);
void remove_mem_info (void *mem_ref);
void report_mem_leak(void);

#endif
