
def reverse(number):
	rev=0
	while number!=0:
		rem=number%10
		rev=rev*10+rem
		number=number//10
	return rev

def palindrome(num):
	rev_num=reverse(num)
	sum=rev_num+num
	rev_sum=reverse(sum)
	if rev_sum==sum:
		return sum

	while sum!=rev_sum:
		sum=sum+rev_sum
		rev_sum=reverse(sum)

	return sum






num=int(input("Enter the number: "))
result=palindrome(num)
print(result)
