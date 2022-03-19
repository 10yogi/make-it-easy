class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        splits = queryIP.split('.')
        if len(splits) == 4:
            for s in splits:
                if len(s) > 3 or len(s) <= 0:
                    return "Neither"
                if len(s) > 1 and  s[0] == '0':
                    return "Neither"
                try:
                    if int(s) > 255 or int(s) < 0:
                        return "Neither"
                except ValueError:
                    return "Neither"
            return "IPv4"
        splits = queryIP.split(':')
        if len(splits) == 8:
            for s in splits:
                if len(s) > 4 or len(s) <= 0:
                    return "Neither"
                try:
                    int(s, 16)
                except ValueError:
                    return "Neither"
            return "IPv6"  
        return "Neither"
