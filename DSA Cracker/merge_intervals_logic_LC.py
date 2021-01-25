class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        s=[]
        intervals.sort()
        for start,end in intervals:
            if len(s)==0:
                s.append([start,end])
            elif s[-1][1]>=start:
                s[-1][1]=max(end,s[-1][1])
            else:
                s.append([start,end])
        return s
    