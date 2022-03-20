class Solution:
    def countPairs(self, dlsc: List[int]) -> int:
        dlsCnt = {}
        nw = 0
        for itm in dlsc:
            if dlsCnt.get(itm):
                dlsCnt[itm] +=  1
            else: 
                dlsCnt[itm] = 1
        lk = list(dlsCnt.keys())
        lk.sort()
        for k in lk:
            for i in range(0, 23):
                if ((1 << i) - k) not in dlsCnt:
                    continue
             
                if (1<<i)-k > k:
                    # print(k, (1<<i)-k, ( dlsCnt[k] * dlsCnt[(1<<i)-k]))
                    nw = (nw + ( dlsCnt[k] * dlsCnt[(1<<i)-k]) % 1000000007) % 1000000007
                if (1<<i) == k + k:
                    # print(k, ((dlsCnt[k] * (dlsCnt[k]-1))/2))
                    nw = (nw + ((dlsCnt[k] * (dlsCnt[k]-1))/2)) % 1000000007
        return int(nw)
