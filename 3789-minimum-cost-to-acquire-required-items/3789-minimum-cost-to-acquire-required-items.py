class Solution(object):
    def minimumCost(self, cost1, cost2, costBoth, need1, need2):
        a = (max(need1,need2)*costBoth)
        b= ((need1*cost1)+(need2*cost2))
          
        c=0
        if need1>need2:
            c= ((costBoth*need2)+((cost1*(need1-need2))))
        else:
            c=((costBoth*need1)+(cost2*(need2-need1)))

        return min(a,b,c)
        # if cost1+cost2 >=costBoth:
        #     return costBoth*(max(need1,need2))
        # return (cost1*need1)+(cost2*need2)
        """
        :type cost1: int
        :type cost2: int
        :type costBoth: int
        :type need1: int
        :type need2: int
        :rtype: int
        """
        