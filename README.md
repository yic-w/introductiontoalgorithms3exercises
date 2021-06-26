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
| lgn      | 10^1000     | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
| √n      | 1000^2     | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
| n      | 1000     | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
| nlgn      | 第一列     | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
| n²      |  √1000    | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
| n³      | 10     | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
| 2^n     | 9     | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
| n!      | 6     | 第二列     | 表格      | 第一列     | 第二列     | 第二列     | 第二列     |  
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
	select-sort(A, length)
		for i in 1 to n-1
			smallest_position = i
			for j in i+1 to n
				if A[i] > A[j]
					smallest_position = j
			swap(A[i], A[smallest_position])
```