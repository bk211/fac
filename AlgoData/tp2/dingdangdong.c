#include "stdio.h"
#include <unistd.h>
static void ding(void);
static void dang(void);
static void dong(void);
static void (*_fct)(void) = ding;

static void ding(void){
	printf("ding\n");
	sleep(1);
	_fct = dang;
}

static void dang(void){
	printf("dang\n");
	sleep(1);
	_fct = dong;
}

static void dong(void){
	printf("dong\n");
	sleep(1);
	_fct = ding;
}

int main(void)
{
	while(1)
		_fct();
	return 0;
}
