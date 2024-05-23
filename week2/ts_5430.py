t = int(input())
for _ in range(t):
    p = input()
    n = int(input())
    arr = list(input()[1:-1].replace(',', ' ').split())

    start = 0
    end = n - 1
    front = True

    for i in p:
        if i == 'R':
            if front is True:
                front = False
            else:
                front = True
        else:
            if front is True:
                start += 1
            else:
                end -= 1

    string = ''
    if start <= end:
        string += '['
        if front is True:
            for char in arr[start:end + 1]:
                string += char
                string += ','
        else:
            for char in arr[-(n - end):-(n - start + 1):-1]:
                string += char
                string += ','
        string = string[0:-1]
        string += ']'
        print(string)
    else:
        if start - end == 1:
            print('[]')
        else:
            print('error')
