s=input().split(",")
string=[]
digits=[]
for i in s:
	s1,num=i.split(":")
	string.append(s1)
	digits.append(num)
print(string)
print(digits)


def square_sum(num):
	sum=0
	while(num>0):
		rem=num%10
		sum=sum+rem*rem
		num=num//10
	return sum


def rotate(s,d):
	temp=int(d)
	ans=square_sum(temp)
	if ans%2==0:
		return s[-1:]+s[:-1]
	else:
		return s[2:]+s[:2]




for i in range(0,len(digits)):
	print(rotate(string[i],digits[i]))
