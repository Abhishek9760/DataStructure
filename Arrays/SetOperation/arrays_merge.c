#include<stdio.h>
#include<stdlib.h>

struct Array{
	int A[20];
	int size;
	int length;
};

void Display(struct Array arr){
	int i;
	for(i=0; i<arr.length; i++){
		printf("%d\n",arr.A[i]);
	}
}

struct Array * merge_arrays(struct Array *arr,struct Array *arr2){

	int i,j,k;
	i=j=k=0;

	struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

	while(i<arr->length && j<arr2->length){

		if(arr->A[i]<arr2->A[j])
			arr3->A[k++]=arr->A[i++];
		else
		    arr3->A[k++]=arr2->A[j++];
	}

	for(;i<arr->length;i++)
		arr3->A[k++]=arr->A[i];
	for(;j<arr2->length;j++)
		arr3->A[k++]=arr2->A[j];

	arr3->length = arr->length + arr2->length;
	arr3->size = 10;

	return arr3;
}


int main(){
	struct Array arr={{5,10,15,20,25},20,5};
	struct Array arr2={{2,4,6,8,10},20,5};
	struct Array *arr3;
	arr3 = merge_arrays(&arr,&arr2);
	Display(*arr3);
	return 0;
}