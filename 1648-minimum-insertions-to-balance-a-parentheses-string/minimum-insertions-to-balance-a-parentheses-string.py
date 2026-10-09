class Solution(object):
    def minInsertions(self, s):
        temp = ''
        n = len(s)
        cnt = 0
        i = 0
        while(i < n):
            if(s[i] == '('):
                temp += s[i]
            else:
                if(i + 1 < n and s[i+1] == ')'):
                    temp += s[i]
                    i+=1
                else:
                    cnt += 1
                    temp += s[i]
            i+=1
        
        stack = []
        for c in temp:
            if(c == '('):
                stack.append(c)
            else:
                if(not stack):
                    cnt += 1
                else:
                    stack.pop()
        
        return cnt + len(stack) * 2
        