def check_pattern(input_list):
    output_list = []
    for item in input_list:
        if '*' in item:
            output_list.append('Yes')
        else:
            output_list.append('No')
    return output_list

input_list = ['.6.aaab.zzzb.codeforces.atcoder.codeforces.tokitlx.aaaa.aaaaaa.abcd.abcd.c.f.']
output = check_pattern(input_list)
print(output)