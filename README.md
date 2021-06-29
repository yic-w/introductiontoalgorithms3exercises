# 算法导论习题
# 第一章
## 1.1-1
### 排序
打牌、成绩单、按个子排队···  
### 凸壳
城墙、杯壁、盒子的四个顶点···
## 1.1-2
机械效率、功率等
## 1.1-3
### 链表  
优势：插入删除数据方便  
局限：查找数据费时
## 1.1-4
相似：都是求最短路径  
不同：两个点之间的最短路径，与多个点之间的最短路径
## 1.1-5
最佳解：过独木桥  
近似最佳解：堵车时绕路
## 1.2-1
excel表格排序，将给定的数据按从小到大或从大到小的顺序排序
## 1.2-2
当n<?时，8n²<64nlgn
## 1.2-3
当n>?时，100n²<2ⁿ  
# 思考题 1-1
|       | 1秒钟     | 1分钟     | 1小时      | 1天     | 1月     | 1年     | 1世纪     |  
| ---------- | :-----------:  | :-----------: | :-----------:  | :-----------: | :-----------:  | :-----------: | :-----------: |    
| lgn      | 10^1000     |      |       |      |      |      |      |  
| √n      | 1000^2     |      |       |      |      |      |      |  
| n      | 1000     |      |       |      |      |      |      |  
| nlgn      | 第一列     |      |       |      |      |      |      |  
| n²      |  √1000    |      |       |      |      |      |      |  
| n³      | 10     |      |       |      |      |      |      |  
| 2^n     | 9     |      |       |      |      |      |      |  
| n!      | 6     |      |       |      |      |      |      |  
# 第二章
## 2.1-1
![Image text]( https://img-blog.csdn.net/20180716214817682?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxNjE5NjU4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
![Image text]( https://img-blog.csdn.net/20180716214834521?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxNjE5NjU4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
![Image text]( https://img-blog.csdn.net/2018071621485689?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxNjE5NjU4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
![Image text]( https://img-blog.csdn.net/20180716214910737?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxNjE5NjU4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
![Image text]( https://img-blog.csdn.net/20180716214923188?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxNjE5NjU4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
![Image text]( https://img-blog.csdn.net/20180716214935691?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxNjE5NjU4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
## 2.1-2
```c
//算法导论习题2.1-2
int insert_sort(int *arr, int len){
	//数组元素个数小于2就退出
	if(len < 2) return -1;
	
	int i = 1, j = 0, key = 0;
	//循环，从数组第二个元素开始，直到最后一个元素
	for(i = 1; i < len; i++){
		
		//暂时保存当前要排序的元素
		key = arr[i];
		
		//此下标赋值为当前排序元素的前一个下标
		j = i - 1;

		//循环，比较当前排序元素和下标为j的元素
		while(arr[j] < key){
			//key较大，则向后移动下标j的元素
			arr[j + 1] = arr[j];
			j--;
			//第一个元素已经比较完
			if(j < 0) break;
		}
		//将当前要排序的元素key，赋值给下标j+1的位置，因为key比下标j的元素小，或者已经比较完全部元素
		arr[j+1] = key;
	}

	return 0;
}
```
## 2.1-3
```c
	linear_serch (A, v)
		while i < A.length 
			if A[i] == v
				return i
			i++
		return NIL
```
初始化：第一次循环迭代之前，数组中存在数据，恒为真  
保持：数组下标i之前的数据都不等于v  
终止：终止条件i < A.length 或者 下标i的数据等于v
## 2.1-4
形式化描述：  
	输入：存储两个n元二进制整数的n元数组A、B  
	输出：存储两个n元二进制整数的和的n+1元数组C  
```c
	sum (A, B)
		key = 0
		for i to n 
			C[i] = (A[i] + B[i] + key ) MOD 2
			key = (A[i] + B[i]) / 2
		C[n + 1] = key
		return C
```
## 2.2-1
θ（n³）
## 2.2-2
```c
	select-sort(A, length)                                     代价    次数
		for i in 1 to n-1                                      c1      n-1
			smallest_position = i                              c2      n-2
			for j in i+1 to n                                  c3      ∑（i=1..n-1)ti
				if A[smallest_position] > A[j]                 c4      ∑（i=1..n-1)ti -1
					smallest_position = j                      c5      ∑（i=1..n-1)ti -1
			swap(A[i], A[smallest_position])                   c6      n-1
```
### 循环不变式
初始化：第一次循环迭代之前，子数组中还没有数据  
保持：内层循环每次迭代都保证最小值的下标smallest_position，循环完毕后与A[i]交换，所以外层每次循环前，A[1..i-1]都是按从小到大的顺序排序好的  
终止：外层循环终止条件为i >= n，子数组A[1..n]由原来在A[1..n]中的元素组成，但已按序排列，此时子数组A[1..n]就是整个数组，推断出整个数组已排序，因此算法正确  
### 为什么只需对n-1个元素运行
运行到第n-1个元素时，将和第n个元素比较，所以第n个元素无需再运行
### 最好情况
输入A内的数据都已按升序排序：则c5 = 0，T(n) = c1(n-1) + c2(n-2) + c3∑（i=1..n-1)ti + c4∑（i=1..n-1)(ti -1) + c6(n-1)   = θ(n²)
### 最坏情况
输入A内的数据都已按降序排序：，T(n) = c1(n-1) + c2(n-2) + c3∑（i=1..n-1)ti + c4∑（i=1..n-1)(ti -1) + c5∑（i=1..n-1)(ti -1) + c6(n-1)   = θ(n²)
## 2.2-3
平均 = 总数/n = (n(n+1) / 2)/n = (n+1)/2
最坏 = n
平均和最坏运行时间都是θ(n)
## 2.2-4
idontkonw
## 2.3-1
![Image text]( https://img-blog.csdn.net/20180717090444307?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzQxNjE5NjU4/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
## 2.3-2
```c
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
```
## 2.3-3
暂无
## 2.3-4
T(n) = T(n-1) + n
```c
/*
	功能:只排序数组最后一位
	arr:数组
	length:数组长度
	*/
int insert_sort_only_last(int *arr, int length){
	if(length < 2) return -1;

	int i = length - 2/*倒数第二个元素*/, key = arr[length - 1]/*倒数第一个元素*/;

	while(key < arr[i]){//循环比较
		arr[i+1] = arr[i];//较大元素往后稍稍
		i--;//下标前移
		if(i < 0) break;
	}
	
	arr[i+1] = key;//赋值

	return 0;
}

/*
	算法导论习题2.3-4
	递归插入排序
	arr:数组
	length:数组长度
	*/
int recursive_insert_sort(int *arr, int length){
	if(length <= 1) return -1;
	recursive_insert_sort(arr, length - 1);//递归调用
	insert_sort_only_last(arr, length);//排序最后元素


	return 0;
}
```
## 2.3-5
### 伪代码
```c
half-serach(A, v, start, end)
	if v == A[half]
		return half
	else if v > A[half]
		half-serach(A, v, half + 1, end)
	else
		half-serach(A, v, start, half - 1)
```
### C
```c
int half_serach(int *arr, int v, int p, int q){
	if(p == q)
		return v == arr[p] ? p : -1;
	if(v == arr[(p+q) / 2])
		return (p+q) / 2;
	else if (v > arr[(p+q) / 2])
		return half_serach(arr, v, (p+q) / 2 + 1, q);
	else
		return half_serach(arr, v, p, (p+q) / 2 - 1);
}
```
