#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��:����������ֵ��
#define swap(a, b) {	\
	a ^= b; 			\
	b ^= a; 			\
	a ^= b; 			\
}

/*
	����:ֻ�����������һλ
	arr:����
	length:���鳤��
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
	�ݹ��������
	arr:����
	length:���鳤��
	*/
int recursive_insert_sort(int *arr, int length){
	if(length <= 1) return -1;
	recursive_insert_sort(arr, length - 1);
	insert_sort_only_last(arr, length);


	return 0;
}

//�㷨����ϰ��2.2-2��ѡ�������㷨
int select_sort(int *arr, int length){
	int i = 0, j = 0;
	int key = 0;
	//ѭ����0 to length -1 
	for(i; i < length - 1; i++){ 					//  n 
		//key = i to length -2��������Сֵ���±�
		key = i;									//n-1
		//ѭ����i+1 to length -1 
		for(j = i + 1; j < length; j++){			// (n * n+1) /2
			//�Ƚϣ�С�ھͰ��±긳ֵ��key
			if(arr[j] < arr[key])					//(n * n+1) /2 - 1
				key = j;							//n	
		}
		//������ѭ�����ҵ���һ����Сֵ�±�key
		if(arr[key] != arr[i])						// n -1
			//��������λ���±�i���±�key��ֵ
			swap(arr[i], arr[key]);					//n-1 
	}
	return 0;
}

//�㷨����ϰ�⣬2.3-2 
int merge(int *arr, int p, int q, int r){
	

	int m  = 0, n = 0, i = p;

	//���붯̬�ڴ�
	int *Larr = calloc(sizeof(int),  (q-p+1));
	int *Rarr = calloc(sizeof(int),  (r-q));
	//����벿copy��Larr
	memcpy(Larr, &arr[p], sizeof(int)*(q-p+1));
	//�Ұ벿copy��Rarr
	memcpy(Rarr, &arr[q-p+1], sizeof(int)*(r-q));
	//ѭ�������±�p��r
	for (i = p; i <= r; i++){
		//�����ߵ�һ�����ݽ�С��copy��arr
		if(Larr[m] <= Rarr[n]){
			arr[i] = Larr[m];
			//copy�꽫m+1
			m++;
			//m����������󳤶ȣ���Rarrʣ�²���copy��arr��Ȼ������ѭ����
			if(m >= q-p+1){
				memcpy(&arr[i+1], &Rarr[n], r-n+1);
				break;
			}

		}
		//����ұߵ�һ�����ݽ�С��copy��arr
		else{
			arr[i] = Rarr[n];
			n++;
			//n����������󳤶ȣ���Larrʣ�²���copy��arr
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
/*	�鲢����
	arr:����
	p:���±�
	r:���±�
*/
int merge_sort(int *arr, int p, int r){

	//���ֻ��һ�����ݣ����˳���
	if(p >= r) return -1;
	//�ݹ�ѭ����벿
	merge_sort(arr, p, (p + r)/2);
	//�ݹ�ѭ���Ұ벿
	merge_sort(arr, (p + r)/2 + 1, r);
	//���Һϲ�
	merge(arr, p , (p + r)/2, r);

	return 0;
}






int main(int argc, char ** argv){
	int arr[5] = {2,1,5,3,2};
	
	//ѡ������
	//select_sort(arr, sizeof(arr)/sizeof(int));

	//�鲢����
	//merge_sort(arr, 0, sizeof(arr)/sizeof(int) - 1);

	//�ݹ��������
	recursive_insert_sort(arr, sizeof(arr)/sizeof(int));

	return 0;
}
