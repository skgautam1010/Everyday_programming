from collections import Counter

def unique_element(arr,k):
	c=Counter(arr)
	print(c)
	l=list(c.values())
	print(l)
	l.sort()
	print(l)
	cum=0
	removed_num=0
	for i in range(len(l)):
		cum +=l[i]
		if cum>k:
			removed_num=i
			break
		if cum==k:
			removed_num=i+1
			break
	return len(l)-removed_num





l=list(map(int,input().split()))
k=int(input())
result=unique_element(l,k)
print(result)
