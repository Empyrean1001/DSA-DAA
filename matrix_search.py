class Solution:
    def searchMatrix1(self, matrix: List[List[int]], target: int) -> bool:

        ####### O(mlog(n))

        def perform_binary(row, target):
            l,r = 0, len(row) - 1
            while l <= r:
                m = l + (r-l) // 2
                if row[m] == target:
                    return True
                elif target < row[m]:
                    r = m-1
                elif target > row[m]:
                    l = m+1
            return False

        for row in matrix:
            if target <= row[-1]:
                res = perform_binary(row, target)
                if res:
                    return True
            else:
                continue
        return False

    def searchMatrix2(self, matrix: List[List[int]], target: int) -> bool:

        ######## O(log(m*n))

        def perform_binary_rows(matrix, target):
            l,r = 0, len(matrix) - 1
            while l <= r:
                m = l + (r-l) // 2
                if matrix[m][0] <= target and target <= matrix[m][-1]:
                    return m
                elif target < matrix[m][0]:
                    r = m-1
                else:
                    l = m+1
            return -1

        rr = perform_binary_rows(matrix, target)
        if rr == -1:
            return False    
        
        def perform_binary_column(row, target):
            l,r = 0, len(row) - 1
            while l <= r:
                m = l + (r-l) // 2
                if row[m] == target:
                    return True
                elif target < row[m]:
                    r = m-1
                elif target > row[m]:
                    l = m+1
            return False

        return perform_binary_column(matrix[rr], target)