class Solution(object):
    def minOperations(self, logs):
        stack = []
        for log in logs:
            if log == "../":
                if stack:
                    stack.pop()
            elif log == "./":
                continue
            else:  
                stack.append(log)
        return len(stack)
        