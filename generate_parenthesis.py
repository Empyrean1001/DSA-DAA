class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def findParenthesis(l, r, s, res, n):
            if len(s) == n*2:
                res.append(s)
                return
            if l < n:
                findParenthesis(l+1, r, s+"(", res, n)
            if r < l:
                findParenthesis(l, r+1, s+")", res, n)

        findParenthesis(0,0,"",res,n)
        return res