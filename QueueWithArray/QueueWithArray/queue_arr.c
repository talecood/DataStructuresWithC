#include <stdio.h>
#include <stdlib.h>
int* array = NULL;
int queue = 0, topqueue = 0, size = 2;
int deque() {
	if (queue == topqueue) {
		printf("Queue is empty.");
		return -1;
	}
	//printf(" boyut = %d, sira= %d , fark=%d\n",boyut,sira,sira-sirabasi);
	if (queue - topqueue <= size / 4) {
		int* dizi2 = (int*)malloc(sizeof(int) * size / 2);
		for (int i = 0; i < queue - topqueue; i++) {
			dizi2[i] = array[topqueue + i];
		}
		queue -= topqueue;
		topqueue = 0;
		free(array);
		size /= 2;
		array = dizi2;
	}
	return array[topqueue++];
}
void toparla() {
	if (topqueue == 0)
		return;
	for (int i = 0; i < size; i++) {
		array[i] = array[i + topqueue];
	}
	queue -= topqueue;
	topqueue = 0;
}
void enque(int a) {
	if (array == NULL) {
		array = (int*)malloc(sizeof(int) * 2);
	}
	if (queue >= size) {
		size *= 2;
		int* dizi2 = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size / 2; i++)
			dizi2[i] = array[i];
		free(array);
		array = dizi2;
	}
	array[queue++] = a;
}
int main() {
	for (int i = 0; i < 20; i++) {
		enque(i * 10);
	}
	printf("\n status: size : %d queue %d queuetop %d", size, queue, topqueue);
	for (int i = 0; i < 13; i++) {
		printf("%d ", deque());
	}
	printf("\n status: size : %d queue %d queuetop %d", size, queue, topqueue);
	for (int i = 0; i < 20; i++) {
		enque(i * 10);
	}
	printf(" status: size : %d queue %d queuetop %d", size, queue, topqueue);
	for (int i = 0; i < 30; i++) {
		printf("%d ", deque());
	}
	printf("\n status: size : %d queue %d queuetop %d", size, queue, topqueue);

}
