#User function Template for python3

def doUnion(a,n,b,m):
    
    #code here
    l1=list(set(a))
    l2=list(set(b))
    l3=[]
    p=len(l1)
    q=len(l2)
    for i in range(p):
        l3.append(l1[i])
    for j in range(q):
        l3.append(l2[j])
    l4=list(set(l3))
    size=len(l4)
    return size


#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        
        n,m=[int(x) for x in input().strip().split()]
        
        a=[int(x) for x in input().strip().split()]
        b=[int(x) for x in input().strip().split()]
        
        
        print(doUnion(a,n,b,m))
# } Driver Code Ends