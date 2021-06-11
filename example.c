#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//宏:交换两数的值。
#define swap(a, b) {	\
	a ^= b; 			\
	b ^= a; 			\
	a ^= b; 			\
}

/*
	功能:只排序数组最后一位
	arr:数组
	length:数组长度
	*/
int insert_sort_only_last(int *arr, int length){
	if(length < 2) return -1;

	int i = length - 2, key = arr[length - 1];

	while(key < arr[i]){
		arr[i+1] = arr[i];
		i--;
		if(i < 0) break;
	}
	
	arr[i+1] = key;

	return 0;
}

/*
	递归插入排序
	arr:数组
	length:数组长度
	*/
int recursive_insert_sort(int *arr, int length){
	if(length <= 1) return -1;
	recursive_insert_sort(arr, length - 1);
	insert_sort_only_last(arr, length);


	return 0;
}

//算法导论习题2.2-2，选择排序算法
int select_sort(int *arr, int length){
	int i = 0, j = 0;
	int key = 0;
	//循环，0 to length -1 
	for(i; i < length - 1; i++){ 					//  n 
		//key = i to length -2，储存最小值的下标
		key = i;									//n-1
		//循环，i+1 to length -1 
		for(j = i + 1; j < length; j++){			// (n * n+1) /2
			//比较，小于就把下标赋值给key
			if(arr[j] < arr[key])					//(n * n+1) /2 - 1
				key = j;							//n	
		}
		//跳出内循环，找到第一轮最小值下标key
		if(arr[key] != arr[i])						// n -1
			//交换数组位于下标i和下标key的值
			swap(arr[i], arr[key]);					//n-1 
	}
	return 0;
}

//算法导论习题，2.3-2 
int merge(int *arr, int p, int q, int r){
	

	int m  = 0, n = 0, i = p;

	//申请动态内存
	int *Larr = calloc(sizeof(int),  (q-p+1));
	int *Rarr = calloc(sizeof(int),  (r-q));
	//将左半部copy到Larr
	memcpy(Larr, &arr[p], sizeof(int)*(q-p+1));
	//右半部copy到Rarr
	memcpy(Rarr, &arr[q-p+1], sizeof(int)*(r-q));
	//循环，从下标p到r
	for (i = p; i <= r; i++){
		//如果左边第一个数据较小，copy到arr
		if(Larr[m] <= Rarr[n]){
			arr[i] = Larr[m];
			//copy完将m+1
			m++;
			//m超出数组最大长度，将Rarr剩下部分copy到arr，然后跳出循环。
			if(m >= q-p+1){
				memcpy(&arr[i+1], &Rarr[n], r-n+1);
				break;
			}

		}
		//如果右边第一个数据较小，copy到arr
		else{
			arr[i] = Rarr[n];
			n++;
			//n超出数组最大长度，将Larr剩下部分copy到arr
			if(n >= r-q){
				memcpy(&arr[i+1], &Larr[m], q-m+1);
				break;
			}
		}
	
	}

	free(Larr);
	free(Rarr);
	return 0;

}
/*	归并排序
	arr:数组
	p:左下标
	r:右下标
*/
int merge_sort(int *arr, int p, int r){

	//如果只有一个数据，就退出。
	if(p >= r) return -1;
	//递归循环左半部
	merge_sort(arr, p, (p + r)/2);
	//递归循环右半部
	merge_sort(arr, (p + r)/2 + 1, r);
	//左右合并
	merge(arr, p , (p + r)/2, r);

	return 0;
}






int main(int argc, char ** argv){
	int arr[5] = {2,1,5,3,2};
	
	//选择排序
	//select_sort(arr, sizeof(arr)/sizeof(int));

	//归并排序
	//merge_sort(arr, 0, sizeof(arr)/sizeof(int) - 1);

	//递归插入排序
	recursive_insert_sort(arr, sizeof(arr)/sizeof(int));

	return 0;
}
