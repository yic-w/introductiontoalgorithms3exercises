# 算法导论（第三版）习题
- [Docs](https://introductiontoalgorithms3exercises.readthedocs.io/en/latest/index.html)
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
		
		//j赋值为当前排序元素的前一个元素下标
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
	

	int m  = 0, n = 0, i = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	//申请动态内存
	int *Larr = calloc(sizeof(int),  n1);
	int *Rarr = calloc(sizeof(int),  n2);
	//将左半部copy到Larr
	memcpy(Larr, &arr[p], sizeof(int) * n1);
	//右半部copy到Rarr
	memcpy(Rarr, &arr[q+1], sizeof(int) * n2);
	//循环，从下标p到r
	for (i = p; i <= r; i++){
		//如果左边第一个数据较小，copy到arr
		if(Larr[m] <= Rarr[n]){
			arr[i] = Larr[m];
			//copy完将m+1
			m++;
			//m超出数组最大长度，将Rarr剩下部分copy到arr，然后跳出循环。
			if(m >= n1){
				while(++i <= r){
					arr[i] = Rarr[n++];
				}
				//memcpy(&arr[i+1], &Rarr[n], n2-n);
				break;
			}

		}
		//如果右边第一个数据较小，copy到arr
		else{
			arr[i] = Rarr[n];
			n++;
			//n超出数组最大长度，将Larr剩下部分copy到arr
			if(n >= n2){
				while(++i <= r){
					arr[i] = Larr[m++];
				}
				//memcpy(&arr[i+1], &Larr[m], n1-m);
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
### C递归
```c
int half_serach(int *arr, int v, int p, int q){
	if(p == q) // 递归结束
		return v == arr[p] ? p : -1;
	if(v == arr[(p+q) / 2])//中点
		return (p+q) / 2;
	else if (v > arr[(p+q) / 2])
		return half_serach(arr, v, (p+q) / 2 + 1, q);//递归调用右半部
	else
		return half_serach(arr, v, p, (p+q) / 2 - 1);//递归调用左半部
}
```
### C循环
```c
int half_serach(int *arr, int v, int length){

	int start = 0;
	int end = length - 1;
	int mid = 0;
	while(start <= end>){

		mid = (start + end) / 2;
		if(arr[mid] == v){
			return mid;
		}else if (arr[mid] < v){

			start = mid + 1;
			continue;
		}else{
			end = mid - 1;
			continue;

		}

	}

	return -1;

}
```
### 证明
递归式：T(n) = T(n/2) + 1 = T(n/2²） + 2 = T(n/2³） + 3 ...以此类推 =  θ（lgn）
## 2.3-6
不行。二分查找只是快速找出了当前元素插入的位置，并不能减少copy操作的次数。时间复杂度还是n²
## 2.3-7
1.归并排序集合S  
2.祛除重复数字  
3.构造集合T{X-S1,X-S2,X-S3,...}  
4.归并集合S，T。  
5.具有两个重复数字的元素，代表S中拥有另一个元素，和它的和为X
## 思考题
## 2-1
a：插入排序复杂度为k²，那么排序n/k个子表，总复杂度为k²*n/k = nk  
b：每层需要合并全部元素n，复杂度为θ（n），递归树共lg（n/k）层，总复杂度为nlgn/k  
c: 要使O(k+lg(n/k))=O(lgn)，则O(k)=O(lgn)，所以k=lgn  
d:选择插入排序比归并排序快的K值
## 2-2
略
## 2-3
### a
θ（n）
### b
```c
multi-sum(A,n,x)
	for i = 0 to n	
		s = 1
		for j = 0 to i
			s *= x
		sum += A[i] * s
```
运行时间为θ（n²），性能比霍纳规则差
### c
初始化：在第一次迭代之前， i = n，y = 0，满足条件。

保持：第 i 次迭代，
![Image text]( https://math.jianshu.com/math?formula=y%20%3D%20a_%7Bi%7D%20%2B%20x%20%5Csum_%7Bk%20%3D%200%7D%5E%7Bn%20-%20(i%20%2B%201)%7D%20a_%7Bk%20%2B%20i%20%2B%201%7D%20x%5Ek%20%3D%20a_%7Bi%7D%20x%5E0%20%2B%20%5Csum_%7Bk%20%3D%200%7D%5E%7Bn%20-%20(i%20%2B%201)%7D%20a_%7Bk%20%2B%20i%20%2B%201%7D%20x%5E%7Bk%20%2B%201%7D%20%3D%20a_%7Bi%7D%20x%5E0%20%2B%20%5Csum_%7Bk%20%3D%201%7D%5E%7Bn%20-%20i%7D%20a_%7Bk%20%2B%20i%7D%20x%5Ek%20%3D%20%5Csum_%7Bk%20%3D%200%7D%5E%7Bn%20-%20i%7D%20a_%7Bk%20%2B%20i%7D%20x%5Ek)  
终止：i = -1，则 ![Image text]( https://math.jianshu.com/math?formula=y%20%3D%20%5Csum_%7Bk%20%3D%200%7D%5E%7Bn%20-%20(-1%20%2B%201)%7D%20a_%7Bk%20-%201%20%2B%201%7D%20x%5Ek.%20%3D%20%5Csum_%7Bk%20%3D%200%7D%5E%7Bn%7D%20a_%7Bk%7D%20x%5Ek)，满足题意。
### d
由c得出结论
## 2-4
### a
（2,1）（3,1）（8,1）（6,1）（8,6）  
### b
降序数组逆序对最多；sum{n-1...1} = n(n-1) / 2  
### c
逆序对数量m为copy操作的次数；T(n) = n + m  
### d 
```c
int inversion_number_sum(int *arr, int p, int q, int r){

	int m  = 0, n = 0, i = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	int num = 0;
	//申请动态内存
	int *Larr = calloc(sizeof(int),  n1);
	int *Rarr = calloc(sizeof(int),  n2);
	//将左半部copy到Larr
	memcpy(Larr, &arr[p], sizeof(int) * n1);
	//右半部copy到Rarr
	memcpy(Rarr, &arr[q+1], sizeof(int) * n2);
	//循环，从下标p到r
	for (i = p; i <= r; i++){
		//如果左边第一个数据较小，copy到arr
		if(Larr[m] <= Rarr[n]){
			arr[i] = Larr[m];
			//copy完将m+1
			m++;
			//m超出数组最大长度，将Rarr剩下部分copy到arr，然后跳出循环。
			if(m >= n1){
				while(++i <= r){
					arr[i] = Rarr[n++];
				}
				//memcpy(&arr[i+1], &Rarr[n], n2-n);
				break;
			}

		}
		//如果右边第一个数据较小，copy到arr
		else{
			arr[i] = Rarr[n];
			n++;
			num += n1 - m; //此时Larr剩下的元素均大于Rarr[n]
			//n超出数组最大长度，将Larr剩下部分copy到arr
			if(n >= n2){
				while(++i <= r){
					arr[i] = Larr[m++];
				}
				//memcpy(&arr[i+1], &Larr[m], n1-m);
				break;
			}
		}
	
	}

	free(Larr);
	free(Rarr);
	return num;

}

int recursive_inversion_number_sum(int *arr, int p, int r){

	if(p >= r) return 0;

	int number = 0;
	int q = (p+r)/2;
	number += recursive_inversion_number_sum(arr, p, q);
	number += recursive_inversion_number_sum(arr, q+1, r);
	number += inversion_number_sum(arr, p, q, r);
	return number;
}
```
# 第三章
## 3.1-1
存在n1,使所有n>n1,f(n)>=0  
存在n2,使所有n>n2,g(n)>=0  
令n0 = max（n1,n2),对于所有n>n0
f <= max (f, g)  
g <= max (f, g)  
所以: f(n) + g(n) / 2 <= max(f, g), max(f, g) <= f(n) + g(n)   
有：0<= (f(n) + g(n)) 1 / 2 <= max(f, g) <= f(n) + g(n) , c1 = 1/2, c2 = 1  
## 3.1-2
当a>0,n^b <（n+a）^b < (2n)^b,所以c0 = 1,c1 = 2^b  
当a<0,(n+a)^b < n^b,且对于n0 > -2a，有当n>n0时，(n+a)^b > (n/2)^b,此时c0 = 2^-b,c1 = 1
## 3.1-3
大O代表上限，至少表下限。
## 3.1-4
存在n0>0,c = 3,使对于所有n>n0, 有 2*2^n  < c*2^n，所以2^n+1 = O(2^n) 成立  
2^2n = 2^n * 2^n,不存在n0,c，使得n>n0时c > 2^n，所以2^2n = O(2^n)不成立
## 3.1-5
在f = o(g)中，界0<= f < cg对所有c>0成立，即f/g < c ,可得n->无穷时，f/g = 0
## 3.1-6
Ω(g): 存在c，n1，对所有n>n1，0 <= c1g(n) < f(n)  
O(g）：存在c，n2，对所有n>n2，0 <= f(n)  < c2g(n)  
所以：对n > max(n1,n2),有0 <= c1g(n) < f(n) < c2g(n) :θ(g(n))
## 3.1-7
o(g(n)):存在c,n0,对于所有n>n0，有0 <= f(n) < cg(n)  
w(g(n)):存在c,n1,对于所有n>n1，有0 <= cg(n) < f(n)  
当n > max(n1,n2)时，有f(n) < cg(n) < f(n)，不等式矛盾，所以为空集
## 3.1-8
Ω(g(n,m)) = {f(n,m):存在正常量c,n0,m0,使得对所有n>n0,或m>m0,有0 <= cg(n,m) <= f(n,m)}  
θ(g(n,m)) = {f(n,m):存在正常量c1，c2,n0,m0,使得对所有n>n0,或m>m0,有0 <= c1g(n,m) <= f(n,m) <= c2g(n,m)}
## 3.2-1
f(n),g(n)单调递增，  
那么有：对于m <= n,f(m) <= f(n), g(m) <= g(n),  
合并可得：对于m <= n,f(m) + g(m) <= f(n) + g(n), f(g(m)) <= f(g(n))  
也即对于m <= n,f(n) + g(n)，和f(g(n))也是单调递增的  
若f(n)和g(n)都是非负的，那么对于m <= n,f(m) * g(m) <= f(n) * g(n)，也即f(n)g(n)也是单调递增的

## 3.2-2
a^logb^c = a^(loga^c / loga^b) = (a^(loga^c))^(1/loga^b) = c^(1/loga^b) = c^(logb^a)
## 3.2-3
![Image text]( https://img-blog.csdnimg.cn/2020102723070613.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3RvdHVzd2hm,size_16,color_FFFFFF,t_70)
## 3.2-5
![Image text]( https://private.codecogs.com/gif.latex?%5Clg%5Ctextup%7B*%7D%28%5Clg%7Bn%7D%29%20%3D%20%5Clg%5E*n%20-%201%20%3E%20%5Clg%28%5Clg%5Ctextup%7B*%7D%28n%29%29)
## 3.2-6
![Image text]( https://img-blog.csdnimg.cn/20201027232018176.png)

# 第四章
## 4.1-1
返回数组中最大的负数。  
最底层左递归返回A[0]，最底层右递归返回A[1],跨中点的递归则返回A[0] + A[1]，因为数组元素都是负数，跨中点的两个负数相加必然小于左右递归的最大值，显然每层递归最终返回左递归和右递归中的最大值，最终函数返回数组中最大的负数。
## 4.1-2
```c
 BRUTE_FORCE(A, low, high){
	max = A[low]
	max-left = low
	max-right = low
	for i = low to high
		sum = A[i]
		if sum > max
			max = sum
			max-left = i
			max-right = i
		for j = i+1 to high
			sum += A[j]
			if sum > max
				max = sum
				max-left = i
				max-right = j
	
	return {max, max-left, max-right}
}
```
## 4.1-3
### 暴力算法
```c
 int BRUTE_FORCE(int *arr, int low, int high, int *ret){
	int max = arr[low];
	int max_left = low;
	int max_right = low;
	int  i = 0, j = 0, sum = 0;
	for(i = low; i <= high; i++){
		sum = arr[i];
		if (sum > max){
			max = sum;
			max_left = i;
			max_right = i;
		}
		
		for(j = i+1; j<= high; j++){
			sum += arr[j];
			if (sum > max){
				max = sum;
				max_left = i;
				max_right = j;
			}
		}
	}

	ret[0] = max;
	ret[1] = max_left;
	ret[2] = max_right;
	
	return 0;
}
```
